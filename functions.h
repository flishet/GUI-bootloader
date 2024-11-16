#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QTimer>

class functions : public QObject {
    Q_OBJECT

public:
    explicit functions(QObject *parent = nullptr);

    int m_counter=0;

signals:
    void dataReceived(const QString &data);
    void portsUpdated();
    void counterChanged(quint8 m_counter);

private slots:
    void handleReadyRead();

public slots:
    bool openSerialPort(const QString &portName, int baudRate);
    void closeSerialPort();
    void writeData();
    QStringList refreshPorts();
    void openfile();
    void onTimeout();

private:
    QSerialPort m_serialPort;
    QTimer *timer = new QTimer(this);
};

#endif // SERIALPORTMANAGER_H
