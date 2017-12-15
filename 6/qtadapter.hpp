#ifndef QTADAPTER_HPP
#define QTADAPTER_HPP

#include <QStringList>

#include "Plateforme.hpp"

class QtAdapter
{
public:

    QtAdapter(Plateforme &p);

    /**
     * @brief mapRessourceToQStringList
     * @param map
     * @return
     */
    QStringList mapRessourceToQStringList(std::map<std::string, Ressource*> map);

    /**
     * @brief ListeCoursValide
     * @return
     */
    QStringList ListeCoursValide();

    /**
     * @brief ListeCoursAValider
     * @return
     */
    QStringList ListeCoursAValider();

    /**
     * @brief ListeCoursSuivis
     * @param e
     * @return
     */
    QStringList ListeCoursSuivis(Etudiant &e);

    /**
     * @brief ListeEtudiantToQStringList
     * @param list
     * @return
     */
    QStringList ListeEtudiantToQStringList(std::list<Etudiant*> list);


    /**
     * @brief return platforme
     * @return platforme
     */
    Plateforme& getPF(){
        return *plateforme;
    }

private:
    Plateforme *plateforme;
};

#endif // QTADAPTER_HPP
