#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "sudoku.h"

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  Sudoku sudoku;

  QQmlApplicationEngine engine;
  const QUrl rootUrl(u"qrc:/sudoku/qml/main.qml"_qs);
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [rootUrl](QObject *obj, const QUrl &objUrl) {
        if (!obj && rootUrl == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.rootContext()->setContextProperty("sudokuObject", &sudoku);
  engine.load(rootUrl);

  return app.exec();
}
