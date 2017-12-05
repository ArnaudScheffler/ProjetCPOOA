#include <QApplication>

#include "ui_mainwindow.h"
#include "mainwindow.h"

int main(int argc, char **argv)
{
    /*
    QApplication app (argc, argv);

    QPushButton button ("Hello world !");
    button.show();

    return app.exec();
    */

    QApplication app(argc, argv);
    MainWindow *main = new MainWindow;
    Ui::MainWindow ui;
    ui.setupUi(main);

    main->show();
    return app.exec();
}
