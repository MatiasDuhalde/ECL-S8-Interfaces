import QtQuick 2.14
import QtQuick.Layouts 1.14
import QtQuick.Controls 2.14


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
}
