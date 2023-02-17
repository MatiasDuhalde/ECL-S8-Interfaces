import QtQuick 2.14
import QtQuick.Layouts 1.14
import QtQuick.Controls 2.14


Item {
    id: levelSelection

    width: 640
    height: 480

    ColumnLayout {
        id: levelSelectionColumnLayout

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

                model: ["Easy", "Medium", "Hard", "Expert"]

                Button {
                    id: levelSelectionNewGameButton

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.preferredHeight: 60
                    Layout.preferredWidth: 236
                    text: qsTr(modelData)
                    font.pixelSize: 22
                    font.family: "Arial"
                    font.bold: true
                    // font.color: "#0a1929"
                    background: Rectangle {
                        color: "#90caf9"
                        radius: 5
                    }
                    onClicked: function(event) {
                        pageLoader.source = "GameWindow.qml"
                        gameWindow.difficulty = modelData
                    }
                }
            }
        }
    }
}
