#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "functions.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    functions function;
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("functions", &function);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
