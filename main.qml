import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Extras 1.4
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    GroupBox
    {
        id: groupBox
        x: 206
        y: 112
        width: 200
        height: 173
        title: qsTr("Serial Setting")

        ComboBox {
            id: comboBox
            x: 52
            y: 17
            width: 99
            height: 28
            model: serial.availablePorts()
        }

        Text {
            id: text1
            x: 18
            y: 23
            width: 23
            height: 16
            text: qsTr("Port:")
            font.pixelSize: 14
        }

        Button {
            id: button
            x: 52
            y: 63
            width: 99
            height: 28
            text: qsTr("Connect")
            onClicked: {
                serial.refreshPorts()
            }
        }
    }
}
