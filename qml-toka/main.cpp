#include <QApplication>
#include <QDeclarativeView>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QDeclarativeView view;
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    return QApplication::exec();
}
