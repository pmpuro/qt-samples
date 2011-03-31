#include <QApplication>
#include <QDialog>

#include "ui_dialog.h"

#include <QTranslator>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QTranslator translaattori;
    translaattori.load("suomi");
    app.installTranslator(&translaattori);

    QDialog d;

    Ui::Dialog* generoituRyona = new Ui::Dialog;
    generoituRyona->setupUi(&d);
//    generoituRyona->pushButton->setText("Muutettu teksti...");
    delete generoituRyona;

    QPushButton* button = d.findChild<QPushButton*>("pushButton_2");
    if(button)
        button->setText(QObject::tr("OK - muutettu"));

    d.exec();

    return 0;
}
