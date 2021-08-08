#ifndef TOTEMANIMATINGWIDGET_H
#define TOTEMANIMATINGWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QList>
#include <QLineF>
#include <QPropertyAnimation>

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
    QList<QLineF> paralleLineList_;



};

#endif // TOTEMANIMATINGWIDGET_H
