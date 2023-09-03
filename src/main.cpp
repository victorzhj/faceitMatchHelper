#include "mainwindow.h"
#include "utils/networker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Networker m;
    m.requestData(QString("https://open.faceit.com/data/v4/players?nickname=zacro"));
    return a.exec();
}
