#include <QApplication>

#include "mylabel.h"
#include "mygesturerecognizer.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Qt::GestureType
     id = QGestureRecognizer::registerRecognizer(new MyGestureRecognizer);

    MyLabel label;
    label.gestureType = id;
    label.grabGesture(id);
    label.setText("Here we go.");
    label.show();

    return QApplication::exec();
}
