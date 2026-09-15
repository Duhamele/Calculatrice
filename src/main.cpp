#include "calwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalWindow w;
    w.show();
    return a.exec();
}
