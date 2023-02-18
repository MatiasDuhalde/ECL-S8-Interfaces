import QtQuick 2.14
import QtQuick.Layouts 1.14
import "../components" as Components


Item {
    id: winWindow

    signal winSignal(string time)

    width: 640
    height: 640

    property string time: "00:00:00"

    ColumnLayout {
        id: winColumnLayout

        anchors.fill: parent
        spacing: 20

        Components.Title {
            id: mainTitle

            Layout.alignment: Qt.AlignCenter
        }

        Text {
            id: winText

            color: "#f3f6f9"
            text: qsTr("You have completed the puzzle!")
            font.pixelSize: 32
            Layout.alignment: Qt.AlignCenter
            font.family: "Arial"
            font.bold: true
        }

        Text {
            id: winTimeText

            color: "#f3f6f9"
            text: qsTr(`Your time: ${time}`)
            font.pixelSize: 24
            Layout.alignment: Qt.AlignCenter
            font.family: "Arial"
            font.bold: true
        }

        Components.CustomButton {
            id: winReturnButton

            text: "Return to Menu"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            onClicked: {
                pageLoader.source = "views/MainMenuWindow.qml"
            }
        }
    }
}
