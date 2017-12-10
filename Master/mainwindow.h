#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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

public slots:
    void seConnecter();
private slots:
    void on_Precedent_clicked();
    void on_actionexit_triggered();
};

#endif // MAINWINDOW_H
