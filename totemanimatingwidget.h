#ifndef TOTEMANIMATINGWIDGET_H
#define TOTEMANIMATINGWIDGET_H

#include <QGraphicsView>
#include <QDebug>
#include <QList>
#include <QPropertyAnimation>


// Responsibility
// 1. decide whether to generate new branch
//    set the parameters "length", "angel", "count" for the new branch
// 2. execute the main loop of the generating
//    and each branch will end itself when the "count" is at the end
// 3. for each turn of loop, get the generated graphic item
//    and forward it to the Scene


class TotemAnimatingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TotemAnimatingWidget(QWidget *parent = nullptr);
    virtual ~TotemAnimatingWidget();

    void showWidget(void);

signals:

private:

    QPropertyAnimation * selfGenerateAnimation_;



};

#endif // TOTEMANIMATINGWIDGET_H
