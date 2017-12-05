#include <QApplication>

#include "ui_mainwindow.h"

int main(int argc, char **argv)
{
    /*
    QApplication app (argc, argv);

    QPushButton button ("Hello world !");
    button.show();

    return app.exec();
    */

    QApplication app(argc, argv);
    QMainWindow *main = new QMainWindow;
    Ui::MainWindow ui;
    ui.setupUi(main);

    main->show();
    return app.exec();
}
