#include "SerialPort.h"

SerialPortManager::SerialPortManager(QObject *parent) : QObject(parent) {
    connect(&m_serialPort, &QSerialPort::readyRead, this, &SerialPortManager::handleReadyRead);
}

bool SerialPortManager::openSerialPort(const QString &portName, int baudRate) {
    m_serialPort.setPortName(portName);
    m_serialPort.setBaudRate(baudRate);
    if (m_serialPort.open(QIODevice::ReadWrite)) {
        return true;
    }
    return false;
}

void SerialPortManager::closeSerialPort() {
    if (m_serialPort.isOpen()) {
        m_serialPort.close();
    }
}

QStringList SerialPortManager::availablePorts()
{
    return m_availablePorts;
}

void SerialPortManager::refreshPorts()
{
    m_availablePorts.clear();
    const auto ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &port : ports) {
        m_availablePorts << port.portName();
    }
   emit portsUpdated();
}

void SerialPortManager::writeData(const QByteArray &data) {
    if (m_serialPort.isOpen()) {
        m_serialPort.write(data);
    }
}

void SerialPortManager::handleReadyRead() {
    const QByteArray data = m_serialPort.readAll();
    emit dataReceived(QString::fromUtf8(data));
}
