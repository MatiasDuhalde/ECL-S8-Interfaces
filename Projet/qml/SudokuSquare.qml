import QtQuick 2.14

Item {
    property real size: 10;
    property string color: "#001e3c";
    property string borderColor: "#5090d3";
    property list<int> borders: [5, 5, 5, 5];

    property int value: 0;
    property list<bool> possibleValues: [
        false, false, false,
        false, false, false,
        false, false, false
    ];

    property bool highlighted: false;

    width: size
    height: size

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onClicked: function(event) {
            if (event.button === Qt.LeftButton) {
                if (gameWindow.selectedCase !== -1) {
                    sudokuGridLayout.children[gameWindow.selectedCase].highlighted = false;
                }
                if (gameWindow.selectedCase === index) {
                    gameWindow.selectedCase = -1;
                    highlighted = false;
                } else {
                    gameWindow.selectedCase = index;
                    highlighted = true;
                }
            }
        }
    }

    Canvas {
        width: size
        height: size

        onPaint: function(event) {
            const ctx = getContext("2d");
            ctx.fillStyle = color;
            ctx.fillRect(0, 0, width, height);
            
            // borders
            const borderTop = borders[0];
            const borderRight = borders[1];
            const borderBottom = borders[2];
            const borderLeft = borders[3];

            const originalLineWidth = ctx.lineWidth;
            ctx.strokeStyle = borderColor;
            ctx.fillStyle = borderColor;

            if (borderTop > 0) {
                ctx.beginPath();
                ctx.lineWidth = borderTop;
                ctx.moveTo(0, 0);
                ctx.lineTo(size, 0);
                ctx.stroke();
            }
            if (borderRight > 0) {
                ctx.beginPath();
                ctx.lineWidth = borderRight;
                ctx.moveTo(size, 0);
                ctx.lineTo(size, size);
                ctx.stroke();
            }
            if (borderBottom > 0) {
                ctx.beginPath();
                ctx.lineWidth = borderBottom;
                ctx.moveTo(size, size);
                ctx.lineTo(0, size);
                ctx.stroke();
            }
            if (borderLeft > 0) {
                ctx.beginPath();
                ctx.lineWidth = borderLeft;
                ctx.moveTo(0, size);
                ctx.lineTo(0, 0);
                ctx.stroke();
            }

            // value
            if (value > 0) {
                ctx.font = `bold ${Math.floor(size * 0.9)}px "sans-serif"`;
                ctx.textAlign = "center";
                ctx.textBaseline = "middle";
                ctx.fillText(value, size / 2, size / 2);
            } else {
                // possible values
                for (let i = 0; i < possibleValues.length; i++) {
                    if (possibleValues[i]) {
                        const x = (i % 3) * size / 3;
                        const y = Math.floor(i / 3) * size / 3;
                        ctx.font = `bold ${Math.floor(size * 0.3)}px "sans-serif"`;
                        ctx.textAlign = "center";
                        ctx.textBaseline = "middle";
                        ctx.fillText(i + 1, x + size / 6, y + size / 6);
                    }
                }
            }
        }
    }

    Rectangle {
        id: selectOverlay

        width: size
        height: size
        color: "white"
        opacity: highlighted ? 0.3 : 0
    }
}