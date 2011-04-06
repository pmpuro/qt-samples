#include <QApplication>
#include <QPushButton>

#include <QPropertyAnimation>

#include <QStateMachine>
#include <QState>

#include <QSignalTransition>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QPushButton button;
    button.setText("Dare you press?");
    button.show();

    QPropertyAnimation* animation = new QPropertyAnimation;
    animation->setTargetObject(&button);
    animation->setPropertyName("pos");
    animation->setEndValue(QVariant(QPoint(250, button.y())));
    animation->setDuration(1500);

    QPropertyAnimation* another = new QPropertyAnimation;
    another->setTargetObject(&button);
    another->setPropertyName("pos");
    another->setEndValue(QVariant(button.pos()));

    QStateMachine machine;
    QState* first = new QState(&machine);
    QState* second = new QState(&machine);

    QSignalTransition* t1 = first->addTransition(&button, SIGNAL(clicked()), second);
    QSignalTransition* t2 = second->addTransition(&button, SIGNAL(clicked()), first);

    t1->addAnimation(animation);
    t2->addAnimation(another);

    machine.setInitialState(first);

    first->assignProperty(&button, "text", QString("tila yksi"));
    second->assignProperty(&button, "text", QString("tila kaksi"));

    machine.start();

    return QApplication::exec();
}
