#include "mylabel.h"

#include <QKeyEvent>
#include <QPainter>
#include <QTransform>


MyLabel::MyLabel(QWidget *parent) :
        QLabel(parent), color(Qt::white), timer(2000), factor(0)
{
    connect(&timer, SIGNAL(valueChanged(qreal)), SLOT(animateThis(qreal)));
}


void MyLabel::keyPressEvent(QKeyEvent *ev)
{
    setText(text() + ev->text());

    if(color == Qt::white) {
        color = Qt::black;
    } else
    {
        color = Qt::white;
    }

    update();

    timer.start();
}

void MyLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    QPainter p(this);

    QTransform transformation;
    transformation.rotate(360 * factor);
    p.setTransform(transformation);

    QLinearGradient g(0, 0, 100, 100);
    g.setColorAt(0.0, color);
    g.setColorAt(1.0, Qt::blue);
    p.setBrush(g);
    p.drawRect(0, 0, 100, 100);
}

void MyLabel::animateThis(qreal value)
{
    factor = value;
    update();
}
