import QtQuick 2.14
import QtQuick.Layouts 1.14
import QtQuick.Controls 2.14


Item {
    id: mainMenu

    width: 640
    height: 480

    ColumnLayout {
        id: mainMenuColumnLayout

        anchors.fill: parent
        spacing: 20

        Text {
            id: mainTitle

            color: "#f3f6f9"
            text: qsTr("Sudoku")
            font.pixelSize: 84
            Layout.alignment: Qt.AlignCenter
            font.family: "Arial"
            font.bold: true
        }



        ColumnLayout {
            id: mainMenuButtonColumnLayout

            Layout.alignment: Qt.AlignCenter
            spacing: 20
            

            Button {
                id: mainMenuNewGameButton

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.preferredHeight: 60
                Layout.preferredWidth: 236
                text: qsTr("NEW GAME")
                font.pixelSize: 22
                font.family: "Arial"
                font.bold: true
                // font.color: "#0a1929"

                background: Rectangle {
                    color: "#90caf9"
                    radius: 5
                }

                onClicked: function(event) {
                    pageLoader.source = "LevelSelectionWindow.qml"
                }
            }

            Button {
                id: mainMenuContinueGameButton

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.preferredHeight: 60
                Layout.preferredWidth: 236
                text: qsTr("CONTINUE GAME")
                font.pixelSize: 22
                font.family: "Arial"
                font.bold: true
                // font.color: "#0a1929"

                background: Rectangle {
                    // change color on hover
                    color: (parent.hovered ? "#90caf9" : "#90caf9")
                    radius: 5
                }
            }

            Button {
                id: mainMenuExitButton

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.preferredHeight: 60
                Layout.preferredWidth: 236
                text: qsTr("EXIT")
                font.pixelSize: 22
                font.family: "Arial"
                font.bold: true
                // font.color: "#0a1929"

                background: Rectangle {
                    color: "#90caf9"
                    radius: 5
                }
            }
        }
    }
}
