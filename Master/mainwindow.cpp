#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::seConnecter()
{
    QMessageBox::critical(this, tr("Erreur"), tr("Il faut au moins un onglet !"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
