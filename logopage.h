#ifndef LOGOPAGE_H
#define LOGOPAGE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QPointF>
#include "selfgenerateline.h"

class LogoPage : public QWidget
{
    Q_OBJECT

public:
    LogoPage(QWidget *parent = nullptr);
    virtual ~LogoPage();

    void showWidget(void);

private slots:

    void generateTotem(void);
    void generatingLoop(QPointF startPos);

private:

    QGraphicsView * totemGraphicsView_;
    QGraphicsScene * totemGraphicsScene_;

    QPushButton * animateActiveButton_;

    int generatingCount_;

};
#endif // LOGOPAGE_H
