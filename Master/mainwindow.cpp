#include <QtDebug>
#include <QStringListModel>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //évite de nous retrouver sur le mauvais widget a cause de l'uidesigner
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::setPlateforme(Plateforme &p)
{
    plateforme = &p;
}


void MainWindow::seConnecter()
{
    std::string login = ui->lineLogin->text().toStdString();
    std::string mdp = ui->lineMdp->text().toStdString();

    if (plateforme->containsEtudiant(login) && plateforme->getEtudiantParLogin(login).verifMDP(mdp) ) {
        //QMessageBox::information(this, tr("Connecté"), tr("Bienvenue !"));
        //Passe a la page suivante
        QString home = QString::fromStdString("Bienvenue " + login + " !");
        ui->label_3->setText(home);

        // Afficher les cours suivis
        Etudiant e = plateforme->getEtudiantParLogin(login);
        QStringList listCoursSuivis;
        for(auto it = e.getPremierCours(); it!=e.getDernierCours(); it++) {
            listCoursSuivis << QString::fromStdString( (*it)->getNom() );
        }
        listeModelCoursSuivis.setStringList(listCoursSuivis);
        ui->listCoursSuivis->setModel(&listeModelCoursSuivis);

        // Afficher tous les cours
        QStringList listCours;
        for(auto it = plateforme->getPremierCours(); it!=plateforme->getDernierCours(); it++) {
            listCours << QString::fromStdString( (*it).first );
        }

        listeModelCours.setStringList(listCours);
        ui->listCours->setModel(&listeModelCours);

        ui->stackedWidget->setCurrentIndex(1);
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Login ou mot de passe incorrect"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Precedent_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_actionexit_triggered()
{
    close();
}

void MainWindow::on_pushButtonAccueil_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_listCoursSuivis_doubleClicked(const QModelIndex &index)
{
    // On récupère le nom du cours en fonction de l'index
    QString nomCours = listeModelCoursSuivis.data(index).toString();
    coursSelectionne = &plateforme->getCoursParNom(nomCours.toStdString());

    // Donne le nom du cours au label
    QString labelText = "Cours : " + nomCours;
    ui->labelNomCours->setText(labelText);

    // Affiche la liste princiaple des étudiants
    std::list<Etudiant*> listeEtudiantP = coursSelectionne->getListeEtudiantP();
    QStringList QStringlistEtudiantP;
    for (auto it=listeEtudiantP.cbegin(); it!=listeEtudiantP.cend(); it++ ){
        QStringlistEtudiantP << QString::fromStdString( (*it)->getLogin() );
    }
    listeModelEdutiantsPrincipal.setStringList(QStringlistEtudiantP);
    ui->listPrincipaleEtudiant->setModel(&listeModelEdutiantsPrincipal);

    // Affiche la liste d'attente des étudiants
    std::list<Etudiant*> listeEtudiantA = coursSelectionne->getListeEtudiantA();
    QStringList QStringlistEtudiantA;
    for (auto it=listeEtudiantA.cbegin(); it!=listeEtudiantA.cend(); it++ ){
        QStringlistEtudiantA << QString::fromStdString( (*it)->getLogin() );
    }
    listeModelEdutiantsSecondaire.setStringList(QStringlistEtudiantA);
    ui->listAttenteEtudiant->setModel(&listeModelEdutiantsSecondaire);

    // Affiche le nombre de place
    labelText = QString("Nombre de places : %1").arg(coursSelectionne->getNbPlace());
    ui->labelNombrePlace->setText(labelText);

    // Affiche la bonne page
    ui->stackedWidget->setCurrentIndex(2);
}
