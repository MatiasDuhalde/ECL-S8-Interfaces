import QtQuick 2.14
import QtQuick.Controls 2.14

Button {
    text: qsTr("Placeholder")

    font.pixelSize: 22
    font.family: "Arial"
    font.bold: true
    // font.color: "#0a1929"

    background: Rectangle {
        color: (parent.hovered ? "#64b5f6" : "#90caf9")
        radius: 5
    }
}