#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QStringListModel>

#include "Plateforme.hpp"
#include "qtadapter.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent, Plateforme &p);
    ~MainWindow();

private:
    Ui::MainWindow *ui;         // Regroupe tous les widgets créé par l'ui designer
    Etudiant *etudiantConnecte;    // Permet de garder un lien vers l'Etudiant connecté
    Cours *coursSelectionne;    // Permet de garder un lien vers le cours séléctionné
    QtAdapter adapter;          // Permet d'accéder aux données de la plateforme a travers l'adapter

    QStringListModel listeModelCours;
    QStringListModel listeModelCoursSuivis;
    QStringListModel listeModelCoursPropose;
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
    void on_SeDesinscrire_clicked();
    void on_pushButtonInscription_clicked();

    /**
     * @brief affiche le cours selectionné par l'user
     * @param nomCours le nom du cours
     */
    void afficherCours(const QString nomCours);

    /**
     * @brief connexion connecte un utilisateur et affiche les données dans la vue
     * @param login de l'utilisateur
     * @param mdp de l'utilisateur
     */
    void connexion(std::string login, std::string mdp);

    void on_inscrirecours_clicked();
    void on_validationCours_stateChanged();
};

#endif // MAINWINDOW_H
