#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QPixmap pixmap("C:/Users/Andrew/Documents/RacingPics/cropped-checkered-flag-icon.png");
    QSplashScreen splash(pixmap);
    splash.show();
    a.thread()->sleep(1);
    a.processEvents();
    MainWindow w;
    w.show();
    splash.finish(&w);

    return a.exec();
}
