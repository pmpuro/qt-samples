#include <QApplication>
#include <QPushButton>

#include "tekstinmuuttaja.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QPushButton button("Uskallatko painaa?");
    button.show();

    TekstinMuuttaja muuttaja(&button);

    QObject::connect(
            &button, SIGNAL(clicked()),
            &muuttaja, SLOT(muutaTeksti()));


    return QApplication::exec();
}
