import QtQuick

Window {
    width: 320
    height: 240
    visible: true
    color: "#4c5cdc"
    title: qsTr("Compteur")

    Rectangle {
        id: rectangle
        x: 110
        y: 95
        width: 100
        height: 50
        color: "#6be1ef"

        Text {
            id: text1
            color: "#200cc6"
            text: vueObjetCpt.cptQML
            Keys.onPressed: function(event) {
              switch (event.key) {
                case Qt.Key_Up:
                  vueObjetCpt.increment();
                  break;
                case Qt.Key_Down:
                  vueObjetCpt.decrement();
                  break;
              }
            }
            anchors.fill: parent
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.family: "Tahoma"
            focus: true
        }
    }
}
