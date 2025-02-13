#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "LogsFilter.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);

    // Context Properties
    // QScopedPointer<LogsFilter> logsFilter(new LogsFilter);
    // QQmlApplicationEngine engine;
    // engine.rootContext()->setContextProperty("logsFilter", logsFilter.get());

    // QScopedPointer<LogsFilter> logsFilter(new LogsFilter);
    // QQmlApplicationEngine engine;
    // qmlRegisterSingletonInstance("MyImport", 1, 0, "LogsFilter", logsFilter.get());

    QQmlApplicationEngine engine;
    //qmlRegisterSingletonType<LogsFilter>("MyImport", 1, 0, "LogsFilter", LogsFilter::instance);


    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Tutorial_8_Video", "Main");

    return app.exec();
}
