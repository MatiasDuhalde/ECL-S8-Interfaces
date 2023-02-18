import QtQuick 2.14
import QtQuick.Dialogs


FileDialog {
    title: "Please choose a save file"
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
