#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

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
    //qDebug() << ui->lineLogin->text();
    //qDebug() << ui->lineMdp->text();

    if (plateforme->containsEtudiant(login) && plateforme->getEtudiantParLogin(login).verifMDP(mdp) ) {
        //QMessageBox::information(this, tr("Connecté"), tr("Bienvenue !"));
        //Passe a la page suivante
        QString home = QString::fromStdString("Bienvenue " + login + " !");
        ui->label_3->setText(home);
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
