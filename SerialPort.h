#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialPortManager : public QObject {
    Q_OBJECT
public:
    explicit SerialPortManager(QObject *parent = nullptr);

    Q_INVOKABLE bool openSerialPort(const QString &portName, int baudRate);
    Q_INVOKABLE void closeSerialPort();
    Q_INVOKABLE QStringList availablePorts();
    Q_INVOKABLE void writeData(const QByteArray &data);
     Q_INVOKABLE void refreshPorts();

signals:
    void dataReceived(const QString &data);
    void portsUpdated();

private slots:
    void handleReadyRead();

private:
    QSerialPort m_serialPort;
    QStringList m_availablePorts;
};

#endif // SERIALPORTMANAGER_H
