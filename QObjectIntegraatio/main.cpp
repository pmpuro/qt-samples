#include <QApplication>
#include <QDeclarativeView>

#include "mycounter.h"

#include <QDeclarativeEngine>
#include <QDeclarativeContext>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyCounter counter;

    QDeclarativeView view;
    view.setSource(QUrl("qrc:/main.qml"));

    QDeclarativeEngine* engine = view.engine();
    QDeclarativeContext* context = engine->rootContext();

    context->setContextProperty("theCounter", &counter);

    view.show();

    return QApplication::exec();
}

