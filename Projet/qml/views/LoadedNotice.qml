import QtQuick 2.14
import QtQuick.Layouts 1.14
import "../components" as Components


Item {
    id: loadedNotice

    width: 640
    height: 480

    ColumnLayout {
        id: loadedNoticeColumnLayout

        anchors.fill: parent
        spacing: 20

        Components.Title {
            id: mainTitle

            Layout.alignment: Qt.AlignCenter
        }

        Text {
            id: loadedNoticeText

            color: "#f3f6f9"
            text: qsTr("Game Loaded!")
            font.pixelSize: 32
            Layout.alignment: Qt.AlignCenter
            font.family: "Arial"
            font.bold: true
        }

        Components.CustomButton {
            id: loadedNoticeStartButton

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.preferredHeight: 60
            Layout.preferredWidth: 236
            text: qsTr("Start")

            onClicked: function(event) {
                pageLoader.source = "views/GameWindow.qml"
            }
        }

        Components.CustomButton {
            id: loadedNoticeReturnButton

            text: "Return to Menu"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            onClicked: {
                pageLoader.source = "views/MainMenuWindow.qml"
            }
        }
    }
}
