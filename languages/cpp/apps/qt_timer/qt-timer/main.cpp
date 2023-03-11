#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "backend.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView view;

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/qt-timer/main.qml"_qs);
    BackEnd bck;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("bck", &bck);
    engine.load(url);

    return app.exec();
}
