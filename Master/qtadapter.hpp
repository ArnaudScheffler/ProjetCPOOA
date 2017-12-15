#ifndef QTADAPTER_HPP
#define QTADAPTER_HPP

#include <QStringList>

#include "Plateforme.hpp"

class QtAdapter
{
public:

    /**
     * @brief QtAdapter Constructeur
     * @param p Platerforme à adapter
     * @version 6
     */
    QtAdapter(Plateforme &p);

    /**
     * @brief mapRessourceToQStringList Tranforme une map de Ressources en QStringList
     * @param map de ressources
     * @return QStringList avec le nom des ressources
     * @version 6
     */
    QStringList mapRessourceToQStringList(std::map<std::string, Ressource*> map);

    /**
     * @brief ListeCoursValide Génère une QStringList avec le nom des cours valides
     * @return QStringList avec le nom des cours valides
     * @version 6
     */
    QStringList ListeCoursValide();

    /**
     * @brief ListeCoursAValider Génère une QStringList avec le nom des cours plus ceux à valider
     * @return QStringList
     * @version 6
     */
    QStringList ListeCoursPourAdmin();

    /**
     * @brief ListeCoursSuivis Génère une QStringList contenant la liste des cours suivis d'un étudiant
     * @param e Etudiant
     * @return QStringList
     * @version 6
     */
    QStringList ListeCoursSuivis(Etudiant &e);

    /**
     * @brief ListeCoursPropose Génère une QStringList contenant la liste des cours proposés par l'ensiegnant
     * @param e Enseigant
     * @return QStringList
     * @version 7
     */
    QStringList ListeCoursPropose(Enseignant &e);

    /**
     * @brief ListeEtudiantToQStringList Transforme une liste d'étudiants en QStringList
     * @param list d'étudiant
     * @return QStringList avec les login des étudiants de la liste
     * @version 6
     */
    QStringList ListeEtudiantToQStringList(std::list<Etudiant*> list);

    /**
     * @brief return platforme
     * @return platforme
     * @version 6
     */
    Plateforme& getPF(){
        return *plateforme;
    }

private:
    Plateforme *plateforme;
};

#endif // QTADAPTER_HPP
