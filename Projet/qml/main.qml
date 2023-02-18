import QtQuick 2.14
import QtQuick.Dialogs


Window {
    id: rootWindow

    width: 640
    height: 480
    visible: true
    color: "#0a1929"
    title: qsTr("Sudoku")

    Loader {
        id: pageLoader
        source: "views/MainMenuWindow.qml"
    }

    FileDialog {
        id: fileSelectDialog

        title: "Please choose a save file"
        currentFolder: "saves"
        nameFilters: ["*.sudoku.csv"]
        options: {
            FileDialog.DontResolveSymlinks |
            FileDialog.ReadOnly |
            FileDialog.HideNameFilterDetails
        }
        onAccepted: function(event) {
            const { selectedFile } = fileSelectDialog;
            if (selectedFile) {
                const filePath = selectedFile.toString().replace("file://", "");
                sudokuObject.initFromSaveFile(filePath);
            } else {
                errorDialog.text = message;
                errorDialog.open();
            }
        }
        onRejected: function(event) {
            errorDialog.text = "No file selected";
            errorDialog.open();
        }
    }

    MessageDialog {
        id: errorDialog

        title: "Error"
        text: "An error has occurred"
    }

    Connections {
        target: sudokuObject
        function onBoardReady(event) {
            pageLoader.source = "views/LoadedNotice.qml"
        }

        function onError(message) {
            errorDialog.text = message;
            errorDialog.open();
        }
    }
}

