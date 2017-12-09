#include <QApplication>
#include <QtDebug>

#include "ui_mainwindow.h"
#include "mainwindow.h"

int main(int argc, char **argv)
{
    //init des composants
    QApplication app(argc, argv);
    //init des composants de la fenêtre
    MainWindow main;
    Plateforme p;
    Etudiant* etudef = new Etudiant("el", "pass");
    p.addEtudiant(*etudef);
    etudef = new Etudiant("a", "pass");
    p.addEtudiant(*etudef);
    etudef = new Etudiant("b", "pass");
    p.addEtudiant(*etudef);
    etudef = new Etudiant("this4u", "pass");
    p.addEtudiant(*etudef);
    etudef = new Etudiant("jo", "pass");
    p.addEtudiant(*etudef);
    main.setPlateforme(p);
    //afichage de la fenêtre
    main.show();
    return app.exec();
}
