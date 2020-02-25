#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "registertype.h"

int main(int argc, char *argv[]) {
  qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

  RegisterType::registerType();

  QCoreApplication::setOrganizationName("MySoft");
  QCoreApplication::setOrganizationDomain("mysoft.com");
  QCoreApplication::setApplicationName("Star Runner");
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  return app.exec();
}
