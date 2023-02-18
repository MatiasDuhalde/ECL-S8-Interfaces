import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtQuick.Dialogs
import "../components" as Components


Dialog {
    id: dialog

    title: "Please enter a save file name"
    anchors.centerIn: parent

    width: 400
    height: 200

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20

        TextField {
            id: fileNameField
            Layout.fillWidth: true
            placeholderText: "Enter a file name (no extension)"
        }

        RowLayout {
            Button {
                id: saveButton
                text: "Save"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onClicked: {
                    const fileName = fileNameField.text;
                    if (fileName) {
                        const filePath = `saves/${fileName}.sudoku.csv`;
                        sudokuObject.saveToFile(filePath);
                        dialog.close();
                    } else {
                        errorDialog.text = "No file name entered";
                        errorDialog.open();
                    }
                }
            }

            Button {
                id: cancelButton
                text: "Cancel"

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onClicked: {
                    dialog.close();
                }
            }
        }
    }

}

