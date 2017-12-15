#include "qtadapter.hpp"

QtAdapter::QtAdapter(Plateforme &p)
{
    plateforme = &p;
}

QStringList QtAdapter::mapRessourceToQStringList(std::map<std::string, Ressource*> map)
{
    QStringList list;
    for (auto it=map.cbegin(); it!=map.cend(); it++) {
        list << QString::fromStdString( it->first );
    }
    return list;
}


QStringList QtAdapter::ListeCoursValide()
{
    QStringList list;
    for (auto it=plateforme->getPremierCours(); it!=plateforme->getDernierCours(); it++ ) {
        if ( it->second->getStatus() )
            list << QString::fromStdString( it->first );
    }
    return list;
}

QStringList QtAdapter::ListeCoursAValider()
{
    QStringList list;
    for (auto it=plateforme->getPremierCours(); it!=plateforme->getDernierCours(); it++ ) {
        if ( it->second->getStatus() )
            list << QString::fromStdString( it->first );
    }
    return list;
}

QStringList QtAdapter::ListeCoursSuivis(Etudiant &e)
{
    QStringList list;
    for (auto it=e.getPremierCours(); it!=e.getDernierCours(); it++ ) {
        list << QString::fromStdString( (*it)->getNom() );
    }
    return list;
}

QStringList QtAdapter::ListeEtudiantToQStringList(std::list<Etudiant*> list)
{
    QStringList qStList;
    for (auto it=list.cbegin(); it!=list.cend(); it++) {
        qStList << QString::fromStdString( (*it)->getLogin() );
    }
    return qStList;
}
