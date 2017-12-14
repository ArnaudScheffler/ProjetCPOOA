#include <QApplication>
#include <QtDebug>

#include "ui_mainwindow.h"
#include "mainwindow.h"

/**
 * @brief main Permet de lancer l'ui du projet.
 * @param argc
 * @param argv
 * @return
 */
int main2(int argc, char **argv)
{
    //init des composants
    QApplication app(argc, argv);
    //init des composants de la fenêtre
    MainWindow main;

    Plateforme p;

    // Initialise la plateforme avec des données en dure
    Cours *cpooa = new Cours("CPOOA", "","","",10);
    cpooa->setValidation(true);
    Cours *algo = new Cours("Algo", "", "", "", 13);
    algo->setValidation(true);
    Ressource *res = new Ressource("pdf", "./test.pdf");
    algo->addRessource(*res);
    p.addCours(*cpooa);
    p.addCours(*algo);

    Enseignant* endef = new Enseignant("Arnaud", "pass");
    p.addUser(ROLE_ENSEIGN,*endef);
    Etudiant* etudef = new Etudiant("el", "pass");
    p.addUser(ROLE_ETUD,*etudef);
    etudef = new Etudiant("a", "pass");
    etudef->inscrire( *cpooa );
    etudef->inscrire( *algo );
    p.addUser(ROLE_ETUD,*etudef);
    etudef = new Etudiant("b", "pass");
    etudef->inscrire( *algo );
    p.addUser(ROLE_ETUD,*etudef);
    etudef = new Etudiant("this4u", "pass");
    p.addUser(ROLE_ETUD,*etudef);
    etudef = new Etudiant("jo", "pass");
    p.addUser(ROLE_ETUD,*etudef);



    main.setPlateforme(p);
    //afichage de la fenêtre
    main.show();
    return app.exec();
}
