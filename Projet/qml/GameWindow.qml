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
        spacing: 10

        RowLayout {
            id: gameCenterRowLayout

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            GridLayout {
                id: sudokuGridLayout

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                columns: 9
                rows: 9

                columnSpacing: 0
                rowSpacing: 0

                Repeater {
                    id: sudokuRepeater

                    model: 9 * 9
                    delegate: SudokuSquare {
                        size: 40
                        color: "#001e3c"
                        borderColor: "#5090d3";
                        borders: [
                            Math.floor(index / 9) == 0 ? 5 : Math.floor(index / 9) % 3 == 0 ? 2.5 : 1,
                            index % 9 == 8 ? 5 : index % 3 == 2 ? 2.5 : 1,
                            Math.floor(index / 9) == 8 ? 5 : Math.floor(index / 9) % 3 == 2 ? 2.5 : 1,
                            index % 9 == 0 ? 5 : index % 3 == 0 ? 2.5 : 1,
                        ]
                    }
                }
            }

            ColumnLayout {
                id: gameControlColumnLayout

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                Button {
                    id: gameResetButton

                    text: "Reset"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    onClicked: {
                        for (var i = 0; i < sudokuRepeater.count; i++) {
                            sudokuRepeater.itemAt(i).color = "white";
                        }
                    }
                }
            }
        }

        RowLayout {
            id: gameControlRowLayout

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }
}
