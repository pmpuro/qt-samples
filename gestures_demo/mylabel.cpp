#include "mylabel.h"

#include <QEvent>
#include <QGestureEvent>
#include <QGesture>

#include "mygesture.h"


MyLabel::MyLabel(QWidget *parent) :
    QLabel(parent)
{
}

bool MyLabel::event(QEvent *e)
{
    if(QEvent::Gesture == e->type())
    {
        QGestureEvent* gestureEvent = dynamic_cast<QGestureEvent*>(e);

        if(gestureEvent)
        {
            QGesture* gesture = gestureEvent->gesture(gestureType);

            if(Qt::GestureFinished == gesture->state())
            {
                setText(text() + QString(" - Got a gesture.... - "));

                MyGesture*
                    myGesture = dynamic_cast<MyGesture*>(gesture);

                if(myGesture)
                {
                    setText(
                        text() + QString::number(myGesture->distance));
                }
            }
        }
    }

    return QLabel::event(e);
}
