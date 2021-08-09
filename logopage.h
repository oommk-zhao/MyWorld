#ifndef LOGOPAGE_H
#define LOGOPAGE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

class LogoPage : public QWidget
{
    Q_OBJECT

public:
    LogoPage(QWidget *parent = nullptr);
    virtual ~LogoPage();

    void showWidget(void);

private:

    QGraphicsView * totemGraphicsView_;
    QGraphicsScene * totemGraphicsScene_;

};
#endif // LOGOPAGE_H
