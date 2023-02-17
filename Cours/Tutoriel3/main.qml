import QtQuick

Window {
    width: 300
    height: 100
    visible: true
    color: "#ffffff"
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 300
        height: 100
        color: "#479736"
        border.color: "#ffffff"
        focus: true

        Keys.onPressed: function(event) {
            switch (event.key) {
            case Qt.Key_A:
                prenom1.plugTexteText=qsTr("Alba");
                break;
            }
        }

        MyComponent {
            id: prenom1
            x: 8
            y: 20
            plugTexteText: qsTr("Matías")
        }

        MouseArea {
            id: mouseArea
            x: 150
            y: 0
            width: 150
            height: 100

            onClicked: function(event) {
                prenom2.plugTexteColor = "#51c3e1";
            }

            MyComponent {
                id: prenom2
                x: 52
                y: 20
                plugTexteText: qsTr("Pierre")
            }
        }
    }
}
