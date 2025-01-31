#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine; // load and manage QML components in your application
    QObject::connect( // setting up a signal-slot connection for error handling
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        //QueuedConnection is used for thread safety
        Qt::QueuedConnection);

    // loads a QML module
    engine.loadFromModule("Tutorial_7_Video", "Main");

    return app.exec();
}
