#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "functions.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);
    functions function;
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("functions", &function);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
