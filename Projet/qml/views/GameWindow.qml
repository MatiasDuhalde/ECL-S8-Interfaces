import QtQuick 2.14
import QtQuick.Layouts 1.14
import "../components" as Components


Item {
    id: gameWindow

    property int selectedCase: -1

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
                focus: true

                Repeater {
                    id: sudokuRepeater

                    model: 9 * 9
                    delegate: Components.SudokuSquare {
                        size: 40
                        color: "#001e3c"
                        borderColor: "#5090d3";
                        borders: [
                            Math.floor(index / 9) == 0 ? 5 : Math.floor(index / 9) % 3 == 0 ? 2.5 : 1,
                            index % 9 == 8 ? 5 : index % 3 == 2 ? 2.5 : 1,
                            Math.floor(index / 9) == 8 ? 5 : Math.floor(index / 9) % 3 == 2 ? 2.5 : 1,
                            index % 9 == 0 ? 5 : index % 3 == 0 ? 2.5 : 1,
                        ]
                        value: sudokuObject.getCaseValue(Math.floor(index / 9), index % 9)
                        fixed: sudokuObject.isCaseFixed(Math.floor(index / 9), index % 9)
                    }
                }

                Keys.onReleased: function(event) {
                    if (selectedCase == -1) {
                        return;
                    }
                    switch (event.key) {
                    case Qt.Key_1:
                        sudokuObject.setCaseValue(Math.floor(selectedCase / 9), selectedCase % 9, 1);
                        break;
                    case Qt.Key_2:
                        sudokuObject.setCaseValue(Math.floor(selectedCase / 9), selectedCase % 9, 2);
                        break;
                    case Qt.Key_3:
                        sudokuObject.setCaseValue(Math.floor(selectedCase / 9), selectedCase % 9, 3);
                        break;
                    case Qt.Key_4:
                        sudokuObject.setCaseValue(Math.floor(selectedCase / 9), selectedCase % 9, 4);
                        break;
                    case Qt.Key_5:
                        sudokuObject.setCaseValue(Math.floor(selectedCase / 9), selectedCase % 9, 5);
                        break;
                    case Qt.Key_6:
                        sudokuObject.setCaseValue(Math.floor(selectedCase / 9), selectedCase % 9, 6);
                        break;
                    case Qt.Key_7:
                        sudokuObject.setCaseValue(Math.floor(selectedCase / 9), selectedCase % 9, 7);
                        break;
                    case Qt.Key_8:
                        sudokuObject.setCaseValue(Math.floor(selectedCase / 9), selectedCase % 9, 8);
                        break;
                    case Qt.Key_9:
                        sudokuObject.setCaseValue(Math.floor(selectedCase / 9), selectedCase % 9, 9);
                        break;
                    case Qt.Key_Backspace:
                        sudokuObject.setCaseValue(Math.floor(selectedCase / 9), selectedCase % 9, 0);
                        break;
                    }
                }
            }

            ColumnLayout {
                id: gameControlColumnLayout

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

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

        RowLayout {
            id: gameControlRowLayout

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }

    Connections {
        target: sudokuObject

        function onCaseChanged(i, j, value) {
            const element = sudokuRepeater.itemAt(j + i * 9)
            if (element) {
                element.value = value
                element.repaint()
            }
        }

        function onCaseConflictStatusChanged(i, j, status) {
            const element = sudokuRepeater.itemAt(j + i * 9)
            if (element) {
                element.changeConflictStatus(status)
            }
        }
    }
}
