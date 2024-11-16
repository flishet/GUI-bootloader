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
    Q_PROPERTY(int counter READ counter WRITE setCounter NOTIFY counterChanged)
public:
    explicit functions(QObject *parent = nullptr);

    Q_INVOKABLE bool openSerialPort(const QString &portName, int baudRate);
    Q_INVOKABLE void closeSerialPort();
    Q_INVOKABLE void writeData();
    Q_INVOKABLE QStringList refreshPorts();
    Q_INVOKABLE void openfile();
    Q_INVOKABLE void onTimeout();

    int counter() const { return m_counter; }

        void setCounter(int value) {
            if (m_counter != value) {
                m_counter = value;
                emit counterChanged();
            }
        }

signals:
    void dataReceived(const QString &data);
    void portsUpdated();
    void counterChanged();

private slots:
    void handleReadyRead();

private:
    QSerialPort m_serialPort;
QTimer *timer = new QTimer(this);
int m_counter=0;

};

#endif // SERIALPORTMANAGER_H
