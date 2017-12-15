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
int main(int argc, char **argv)
{
    //init des composants
    QApplication app(argc, argv);

    Plateforme p;

    // Initialise les composants de la fenêtre
    MainWindow main(NULL, p);

    // Initialise la plateforme avec des données en dur

    // Admin
    Admin *a = new Admin("admin", "pass");
    p.addUser(ROLE_ADMIN, *a);

    // Les enseignants
    Enseignant* en2def = new Enseignant("Arnaud", "pass");
    p.addUser(ROLE_ENSEIGN,*en2def);
    Enseignant* endef = new Enseignant("Gautier", "pass");
    p.addUser(ROLE_ENSEIGN,*endef);
    Admin* addef = new Admin("Elliot", "pass");
    p.addUser(ROLE_ADMIN,*addef);

    // Ajoute des cours
    Cours *cpooa = new Cours("CPOOA", "","","",10);
    cpooa->setValidation(false);
    endef->proposerUnCours(*cpooa);
    Cours *algo = new Cours("Algo", "", "", "", 13);
    algo->setValidation(true);
    endef->proposerUnCours(*algo);
    Cours *sys = new Cours("Systeme", "", "", "", 1);
    sys->setValidation(true);
    en2def->proposerUnCours(*sys);
    Ressource *res = new Ressource("pdf", "./test.pdf");
    algo->addRessource(*res);
    p.addCours(*cpooa);
    p.addCours(*algo);
    p.addCours(*sys);

    // Ajoute des etudiants
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

    // Affichage de la fenêtre
    main.show();
    return app.exec();
}
