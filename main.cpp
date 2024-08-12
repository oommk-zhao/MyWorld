#include "worldblackboard.h"

#include <QApplication>
#include <QTcpSocket>

// logo page demo done

// TBD
// 1. map demo, 16 * 9
// 2. different type of the single map object
// 3. character painting
// 4. moving animation

// Optimized TBD
// 1. Smooth different page/widget/screen switching
// 2. Github update
// 3. Simple project plan with different version and milestone

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto tcpSocketItem = new QTcpSocket();
    tcpSocketItem->connectToHost(QString("172.22.1.115"), 5000);

    WorldBlackBoard w;
    w.loadLogoWidget();
    return a.exec();
}
