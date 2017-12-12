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
    Ui::MainWindow *ui;
    Plateforme *plateforme;
    Cours *coursSelectionne;

    QStringListModel listeModelCours;
    QStringListModel listeModelCoursSuivis;
    QStringListModel listeModelEtudiantsPrincipal;
    QStringListModel listeModelEtudiantsSecondaire;
    QStringListModel listeModelRessources;

public slots:
    void seConnecter();
private slots:
    void on_Precedent_clicked();
    void on_actionexit_triggered();
    void on_pushButtonAccueil_clicked();
    void on_listCoursSuivis_doubleClicked(const QModelIndex &index);
};

#endif // MAINWINDOW_H
