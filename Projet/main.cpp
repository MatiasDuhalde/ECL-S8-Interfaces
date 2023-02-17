#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  const QUrl rootUrl(u"qrc:/sudoku/qml/main.qml"_qs);
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [rootUrl](QObject *obj, const QUrl &objUrl) {
        if (!obj && rootUrl == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(rootUrl);

  return app.exec();
}
