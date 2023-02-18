import QtQuick 2.14
import "dialogs" as Dialogs
import "components" as Components


Window {
    id: rootWindow

    width: 640
    height: 640
    visible: true
    color: "#0a1929"
    title: qsTr("Sudoku")

    Loader {
        id: pageLoader
        source: "views/MainMenuWindow.qml"
    }

    Dialogs.SelectSaveNameDialog {
        id: selectSaveNameDialog
    }

    Dialogs.SelectFileDialog {
        id: fileSelectDialog
    }

    Dialogs.ErrorDialog {
        id: errorDialog
    }

    Connections {
        target: sudokuObject
        function onBoardReady(event) {
            pageLoader.source = "views/LoadedNoticeWindow.qml"
        }

        function onError(message) {
            errorDialog.text = message;
            errorDialog.open();
        }
    }

    Connections {
        target: pageLoader.item
        function onWinSignal(time) {
            pageLoader.source = "views/WinWindow.qml"
            pageLoader.item.time = time
        }
    }
}
