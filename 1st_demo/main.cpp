#include <QApplication>
#include <QLabel>


int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  QLabel laabeli("Jotain tekstia tulee sitten ....");
  laabeli.show();

  return QApplication::exec();
}
