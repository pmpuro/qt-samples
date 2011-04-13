#ifndef MYGESTURERECOGNIZER_H
#define MYGESTURERECOGNIZER_H

#include <QGestureRecognizer>

class MyGestureRecognizer : public QGestureRecognizer
{    
public:
    MyGestureRecognizer();

    virtual QGesture *create(QObject *target);
    virtual Result recognize(
                QGesture *state, QObject *watched, QEvent *event);
};

#endif // MYGESTURERECOGNIZER_H
