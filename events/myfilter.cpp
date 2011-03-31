#include "myfilter.h"

#include <QPushButton>
#include <QEvent>


MyFilter::MyFilter(QObject *parent) :
    QObject(parent)
{
}

bool MyFilter::eventFilter(QObject *receiver, QEvent *event)
{
    if(QEvent::MouseButtonPress != event->type())
    {
        return false;
    }

    QPushButton* button = dynamic_cast<QPushButton*>(receiver);

    if(button)
    {
        button->setGeometry(
                10 + button->x(),
                button->y(),
                button->width(),
                button->height());
    }

    return false;
}
