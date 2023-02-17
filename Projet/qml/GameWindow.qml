import QtQuick 2.14
import QtQuick.Layouts 1.14
import QtQuick.Controls 2.14


Item {
    id: gameWindow

    width: 640
    height: 480


    ColumnLayout {
        id: gameColumnLayout
        anchors.fill: parent
        spacing: 20

        GridLayout {
            id: gameGridLayout

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            columns: 9
            rows: 9

            Repeater {
                id: gameGridRepeater

                model: 9 * 9
                delegate: Rectangle {
                    width: 30
                    height: 30
                    color: "white"
                    border.color: "black"
                    border.width: 2
                    MouseArea {
                        anchors.fill: parent
                        onClicked: function(event) {
                            const gameSquare = gameGridRepeater.itemAt(index);
                            console.log(gameSquare.color);
                            if (gameSquare.color == "#ffffff") {
                                gameSquare.color = "black";
                            } else {
                                gameSquare.color = "white";
                            }
                        }
                    }
                }
            }
        }

        RowLayout {
            id: gameControlRowLayout
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Button {
            id: gameResetButton
            text: "Reset"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onClicked: {
                for (var i = 0; i < gameGridRepeater.count; i++) {
                    gameGridRepeater.itemAt(i).color = "white";
                }
            }
        }

    }

}
