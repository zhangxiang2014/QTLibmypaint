#include "mainwindow.h"
#include <QApplication>
#include "mypaint.h"




int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    mypaint_init();
    MainWindow window;
    window.show();

    return a.exec();
}
