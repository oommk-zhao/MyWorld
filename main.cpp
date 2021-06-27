#include "logopage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogoPage w;
    w.show();
    return a.exec();
}
