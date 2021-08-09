#ifndef TOTEMANIMATINGWIDGET_H
#define TOTEMANIMATINGWIDGET_H

#include <QGraphicsView>
#include <QDebug>
#include <QList>
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



};

#endif // TOTEMANIMATINGWIDGET_H
