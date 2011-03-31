#include <QApplication>
#include <QLabel>
#include <QPushButton>

#include <myfilter.h>
#include <mylabel.h>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyLabel window;
    QPushButton* button = new QPushButton("Joku teksti", &window);

    MyFilter filter;
    button->installEventFilter(&filter);

    window.show();

    return QApplication::exec();
}
