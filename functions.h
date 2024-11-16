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

signals:
    void dataReceived(const QString &data);
    void portsUpdated();
    void valueChanged(int newValue);

public slots:
    bool openSerialPort(const QString &portName, int baudRate);
    void closeSerialPort();
    void writeData();
    QStringList refreshPorts();
    void openfile();
    void onTimeout();
    void emitValue(int value) {
            emit valueChanged(value);
        }

private slots:
    void handleReadyRead();

private:
    QSerialPort m_serialPort;
    QTimer *timer = new QTimer(this);
    quint8 m_counter=0;

};

#endif // SERIALPORTMANAGER_H
