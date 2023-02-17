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
        source: "MainMenuWindow.qml"
    }

    FileDialog {
        id: fileSelectDialog

        title: "Please choose a save file"
        currentFolder: Qt.resolvedUrl("./saves")
        nameFilters: ["*.sudoku.csv"]
        options: {
            FileDialog.DontResolveSymlinks |
            FileDialog.ReadOnly |
            FileDialog.HideNameFilterDetails
        }
        onAccepted: function(event) {
            console.log("Accepted: " + fileSelectDialog.selectedFile)
            pageLoader.source = "GameWindow.qml"
            // pageLoader.item.loadGame(fileSelectDialog.fileUrl)
        }
    }
}

