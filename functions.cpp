#include "functions.h"

functions::functions(QObject *parent) : QObject(parent) {
    connect(&m_serialPort, &QSerialPort::readyRead, this, &functions::handleReadyRead);
    connect(timer, &QTimer::timeout, this, &functions::onTimeout);

}

void functions::onTimeout()
{
    m_counter++;
    emit counterChanged(m_counter);
}

bool functions::openSerialPort(const QString &portName, int baudRate) {
    m_serialPort.setPortName(portName);
    m_serialPort.setBaudRate(baudRate);
    if (m_serialPort.open(QIODevice::ReadWrite)) {
        return true;
    }
    return false;
}

void functions::closeSerialPort() {
    if (m_serialPort.isOpen())
    {
        m_serialPort.close();
    }
}

QStringList functions::refreshPorts()
{
    QStringList m_availablePorts;
    m_availablePorts.clear();
    const auto ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &port : ports) {
        m_availablePorts << port.portName();
    }
    return m_availablePorts;
}

void functions::writeData()
{
//    if (m_serialPort.isOpen()) {
//        m_serialPort.write(data);
//    }
    qDebug()<<"write data";
    timer->start(100);
}

void functions::handleReadyRead() {
    const QByteArray data = m_serialPort.readAll();
    emit dataReceived(QString::fromUtf8(data));
}

void functions::openfile()
{
    //QFile file(path);
    //file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString filePath = QFileDialog::getOpenFileName(nullptr,"Open File","C:/","Text Files (*.txt);;All Files (*)");
    qDebug()<<filePath;
}
