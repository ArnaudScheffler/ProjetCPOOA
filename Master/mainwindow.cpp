#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

void MainWindow::setPlateforme(Plateforme &p)
{
    plateforme = &p;
}


void MainWindow::seConnecter()
{
    std::string login = ui->lineEdit->text().toStdString();
    std::string mdp = ui->lineEdit_2->text().toStdString();
    qDebug() << ui->lineEdit->text();
    qDebug() << ui->lineEdit_2->text();

    if (plateforme->containsEtudiant(login) && plateforme->getEtudiantParLogin(login).verifMDP(mdp) ) {
        QMessageBox::information(this, tr("Connecté"), tr("Bienvenue !"));
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Login ou mot de passe incorrect"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
