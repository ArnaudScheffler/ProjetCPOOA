#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QStringListModel>

#include "Plateforme.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setPlateforme(Plateforme &p);

private:
    Ui::MainWindow *ui;         // Regroupe tous les widgets créé par l'ui designer
    Plateforme *plateforme;     // Permet d'accéder aux données de la plateforme
    Cours *coursSelectionne;    // Permet de garder un lien vers le cours séléctionné

    QStringListModel listeModelCours;
    QStringListModel listeModelCoursSuivis;
    QStringListModel listeModelEtudiantsPrincipal;
    QStringListModel listeModelEtudiantsSecondaire;
    QStringListModel listeModelRessources;

private slots:

    /**
     * @brief seConnecter Vérifie l'accès d'un utilisateur à l'application et charge les informations de la page
     * d'accueil
     */
    void seConnecter();

    /**
     * @brief on_buttonDeconnection_clicked Permet de se déconnecter et d'afficher la page d'inscription
     */
    void on_buttonDeconnexion_clicked();

    /**
     * @brief on_actionexit_triggered Quitte l'application dans le menu Fichier -> Quitter
     */
    void on_actionexit_triggered();

    /**
     * @brief on_pushButtonAccueil_clicked Retourne à la page d'accueil d'un utilisateur quand on est sur la
     * page d'un cours
     */
    void on_pushButtonAccueil_clicked();

    /**
     * @brief on_listCoursSuivis_doubleClicked Affiche la vue d'un cours avec ses informations quand on
     * le séléctionne dans la liste de cours suivis
     * @param index duc cours séléctionné dans la liste
     */
    void on_listCoursSuivis_doubleClicked(const QModelIndex &index);


    void on_listCours_doubleClicked(const QModelIndex &index);
};

#endif // MAINWINDOW_H
