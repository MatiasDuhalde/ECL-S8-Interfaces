import QtQuick 2.14
import QtQuick.Layouts 1.14
import "../components" as Components


Item {
    id: gameWindow

    signal winSignal(string time)

    width: 640
    height: 640
    focus: true

    // start time
    property bool gameActive: true
    property int selectedCase: -1
    property bool timeRunning: true
    property date startTime: new Date()

    ColumnLayout {
        id: gameColumnLayout

        anchors.fill: parent
        spacing: 20

        Components.Title {
            id: mainTitle

            Layout.alignment: Qt.AlignCenter
        }

        RowLayout {
            id: gameCenterRowLayout

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            spacing: 20

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
                        conflict: sudokuObject.isCaseConflicting(Math.floor(index / 9), index % 9)
                    }
                }
            }
        }

        RowLayout {
            id: gameControlRowLayout

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            spacing: 20

            Components.CustomButton {
                id: gameSaveButton

                text: "Save Game"
                Layout.alignment: Qt.AlignCenter

                onClicked: {
                    selectSaveNameDialog.open()
                }
            }

            Components.CustomButton {
                id: gameBackButton

                text: "Return to Menu"
                Layout.alignment: Qt.AlignCenter

                onClicked: {
                    pageLoader.source = "views/MainMenuWindow.qml"
                }
            }

            Components.CustomButton {
                id: gameResetButton

                text: "Reset Game"
                Layout.alignment: Qt.AlignCenter

                onClicked: {
                    sudokuObject.reset()
                }
            }

            Text {
                id: gameTimerText

                Layout.alignment: Qt.AlignCenter
                text: qsTr("00:00:00")
                font.pixelSize: 24
                font.family: "Arial"
                font.bold: true
                color: "#f3f6f9"
            }
        }
    }

    Timer {
        interval: 900
        running: timeRunning
        repeat: true
        onTriggered: function (event) {
            const difference = new Date().getTime() - startTime.getTime();
            let seconds = Math.floor(difference / 1000) % 60;
            seconds = seconds < 10 ? "0" + seconds : seconds.toString();
            let minutes = Math.floor(seconds / 60) % 60;
            minutes = minutes < 10 ? "0" + minutes : minutes.toString();
            let hours = Math.floor(minutes / 60);
            hours = hours < 10 ? "0" + hours : hours.toString();
            gameTimerText.text = qsTr(`${hours}:${minutes}:${seconds}`);
        }
    }

    Keys.onReleased: function(event) {
        if (selectedCase == -1 || !gameActive) {
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
        case Qt.Key_Delete:
        case Qt.Key_0:
            sudokuObject.setCaseValue(Math.floor(selectedCase / 9), selectedCase % 9, 0);
            break;
        }
    }

    Connections {
        target: sudokuObject

        function onCaseChanged(i, j, value) {
            const element = sudokuRepeater.itemAt(j + i * 9);
            if (element) {
                element.value = value;
                element.repaint();
            }
        }

        function onCaseConflictStatusChanged(i, j, status) {
            const element = sudokuRepeater.itemAt(j + i * 9);
            if (element) {
                element.changeConflictStatus(status);
            }
        }

        function onCorrect() {
            timeRunning = false;
            gameActive = false;
            winSignal(gameTimerText.text);
        }
    }
}