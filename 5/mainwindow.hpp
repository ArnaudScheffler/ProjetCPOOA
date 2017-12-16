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
     * @brief on_Precedent_clicked
     */
    void on_Precedent_clicked();
    void on_actionexit_triggered();
    void on_pushButtonAccueil_clicked();
    void on_listCoursSuivis_doubleClicked(const QModelIndex &index);
};

#endif // MAINWINDOW_H
