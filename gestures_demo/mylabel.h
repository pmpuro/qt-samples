#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);

    bool event(QEvent *e);

    Qt::GestureType gestureType;
};

#endif // MYLABEL_H
