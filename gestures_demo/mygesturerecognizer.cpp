#include "mygesturerecognizer.h"

#include "mygesture.h"

#include <QEvent>
#include <QMouseEvent>


MyGestureRecognizer::MyGestureRecognizer() :
    QGestureRecognizer()
{
}

QGesture *MyGestureRecognizer::create(QObject *)
{
    return new MyGesture;
}

QGestureRecognizer::Result MyGestureRecognizer
        ::recognize(QGesture *state, QObject *, QEvent *event)
{
    MyGesture* gesture = dynamic_cast<MyGesture*>(state);

    if(!gesture)
    {
        return QGestureRecognizer::CancelGesture;
    }

    if(QEvent::MouseButtonPress == event->type())
    {
        QMouseEvent* mouseEvent = dynamic_cast<QMouseEvent*>(event);

        if(mouseEvent)
        {
            gesture->position = mouseEvent->pos();
            return QGestureRecognizer::MayBeGesture;
        }
    }

    if(QEvent::MouseButtonRelease == event->type())
    {
        QMouseEvent* mouseEvent = dynamic_cast<QMouseEvent*>(event);

        if(mouseEvent)
        {
            gesture->distance
                    = gesture->position.x() - mouseEvent->pos().x();

            if(100 <= qAbs(gesture->distance))
            {
                return QGestureRecognizer::FinishGesture;
            }
        }
    }

    return QGestureRecognizer::CancelGesture;
}
