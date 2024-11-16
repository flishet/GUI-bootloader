import QtQuick 2.12
import QtQuick.Window 2.3
import QtQuick.Extras 1.4
import QtQuick.Controls 2.12
import QtQml 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    Connections{
        target: functions

        onCounterChanged: {
            console.log(m_counter)
            progressBar.value = m_counter/100
        }
    }

    GroupBox {
        id: groupBox
        x: 20
        y: 19
        width: 200
        height: 173
        title: qsTr("Serial Setting")
        ComboBox {
            id: comboBox
            x: 52
            y: 17
            width: 99
            height: 28
            model: functions.refreshPorts()
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
            text: qsTr("Refresh")
            onClicked: {
                comboBox.model= functions.refreshPorts();
            }
        }
    }

    ProgressBar {
        id: progressBar
        x: 220
        y: 373
    }

    Button {
        id: button1
        x: 241
        y: 19
        text: qsTr("Open File")
        onClicked: functions.openfile();
    }

    Button {
        id: button2
        x: 241
        y: 74
        text: qsTr("Send")
        onClicked: functions.writeData();

    }

    TextInput {
        id: hexInput
        x: 241
        y: 129
        width: 200
        height: 40
        font.pixelSize: 16
        //                placeholderText: "e.g. 1A3F"
        horizontalAlignment: TextInput.AlignHCenter
        verticalAlignment: TextInput.AlignVCenter




        inputMask: ">HHHHHHHH;"
        validator: RegExpValidator {
            regExp: /^[0-9a-fA-F]*$/
        }

        onTextChanged: {
            console.log("Hex Input:", text)
        }
    }
}


