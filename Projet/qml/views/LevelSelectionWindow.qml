import QtQuick 2.14
import QtQuick.Layouts 1.14
import "../components" as Components


Item {
    id: levelSelection

    width: 640
    height: 480

    ColumnLayout {
        id: levelSelectionColumnLayout

        anchors.fill: parent
        spacing: 20

        Components.Title {
            id: mainTitle

            Layout.alignment: Qt.AlignCenter
        }

        Text {
            id: selectionPrompt

            color: "#f3f6f9"
            text: qsTr("Select a difficulty level:")
            font.pixelSize: 32
            Layout.alignment: Qt.AlignCenter
            font.family: "Arial"
            font.bold: true
        }

        GridLayout {
            id: levelSelectionButtonGridLayout

            columns: 2
            rows: 2
            Layout.alignment: Qt.AlignCenter

            Repeater {
                id: levelSelectionRepeater

                model: ["Beginner", "Easy", "Intermediate", "Expert"]

                Components.CustomButton {
                    id: levelSelectionNewGameButton

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.preferredHeight: 60
                    Layout.preferredWidth: 236
                    text: qsTr(modelData)

                    onClicked: function(event) {
                        sudokuObject.initFromLevel(index)
                    }
                }
            }
        }

        Components.CustomButton {
            id: gameResetButton

            text: "Return to Menu"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            onClicked: {
                pageLoader.source = "views/MainMenuWindow.qml"
            }
        }
    }
}
