#include <QApplication>
#include <QtDebug>

#include "ui_mainwindow.h"
#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MainWindow main;
    Plateforme p;
    Etudiant *a = new Etudiant("a", "a");
    p.addEtudiant(*a);
    main.setPlateforme(p);
    main.show();
    return app.exec();
}
