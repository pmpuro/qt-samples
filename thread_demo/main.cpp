#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QThread>

#include "receiver.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    QPushButton* button = new QPushButton(&window);
    window.show();

    QThread t;
    t.start();

    Receiver receiver;

    receiver.moveToThread(&t);

    QObject::connect(button, SIGNAL(clicked()), &receiver, SLOT(theSlot()));
    QObject::connect(&receiver, SIGNAL(theSignal()), button, SLOT(hide()));

    return QApplication::exec();
}
