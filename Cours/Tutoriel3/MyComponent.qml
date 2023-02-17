import QtQuick

Item {
    id: monPlug
    width: 90
    height: 60
    property alias plugTexteColor: plugTexte.color
    property alias plugTexteText: plugTexte.text

    Text {
        id: plugTexte
        x: 8
        y: 14
        text: qsTr("Matías")
        font.pixelSize: 24
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.underline: true
        font.family: "Verdana"
    }

}
