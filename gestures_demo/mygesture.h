#ifndef MYGESTURE_H
#define MYGESTURE_H

#include <QGesture>

class MyGesture : public QGesture
{
public:

    QPoint position;
    int distance;
};

#endif // MYGESTURE_H
