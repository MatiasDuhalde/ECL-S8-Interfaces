import QtQuick 2.14
import QtQuick.Layouts 1.14
import "../components" as Components


Item {
    id: mainMenu

    signal winSignal(string time)

    width: 640
    height: 640

    ColumnLayout {
        id: mainMenuColumnLayout

        anchors.fill: parent
        spacing: 20

        Components.Title {
            id: mainTitle

            Layout.alignment: Qt.AlignCenter
        }



        ColumnLayout {
            id: mainMenuButtonColumnLayout

            Layout.alignment: Qt.AlignCenter
            spacing: 20
            

            Components.CustomButton {
                id: mainMenuNewGameButton

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.preferredHeight: 60
                Layout.preferredWidth: 236
                text: qsTr("NEW GAME")

                onClicked: function(event) {
                    pageLoader.source = "views/LevelSelectionWindow.qml"
                }
            }

            Components.CustomButton {
                id: mainMenuContinueGameButton

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.preferredHeight: 60
                Layout.preferredWidth: 236
                text: qsTr("CONTINUE GAME")

                onClicked: function(event) {
                    fileSelectDialog.open();
                }
            }

            Components.CustomButton {
                id: mainMenuExitButton

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.preferredHeight: 60
                Layout.preferredWidth: 236
                text: qsTr("EXIT")

                onClicked: function(event) {
                    Qt.quit()
                }
            }
        }
    }
}
