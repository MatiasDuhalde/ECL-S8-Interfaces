#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "compteur.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Compteur aCompteur;

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/Compteur/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("vueObjetCpt", &aCompteur);
    engine.load(url);

    return app.exec();
}
