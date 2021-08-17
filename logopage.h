#ifndef LOGOPAGE_H
#define LOGOPAGE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QPushButton>
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

private:

    QGraphicsView * totemGraphicsView_;
    QGraphicsScene * totemGraphicsScene_;

    SelfGenerateLine * testLine_;

    QPushButton * animateActiveButton_;


};
#endif // LOGOPAGE_H
