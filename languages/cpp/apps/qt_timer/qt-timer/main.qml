import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQml
import io.qt.qttimerex.backend

Window {
    //width: 640
    //height: 480
    visible: true

    title: qsTr("Hello World")
    id: mainWindow

    property int timerSecondsRemaining: 0
    property bool ticking: false

    Rectangle {
        color: "#ffffff"
        anchors.centerIn: parent
        width: 300
        height: 110
    ColumnLayout {
        anchors.centerIn: parent

        BackEnd {
            id: backend
        }

        function randomHexStr() { return Number(backend.randomInt).toString(16); }

        function randomRGB() {
            return "#" + randomHexStr() + randomHexStr() + randomHexStr();
        }

        Timer {
            running: ticking
            repeat: true
            interval: 1000
            onTriggered: {
                if(timerSecondsRemaining == 0) {
                    timerText.text = "KEKW";
                    mainWindow.color = parent.randomRGB();
                    ticking = false;
                    goButton.text = "GO!";
                } else {
                    timerSecondsRemaining -= 1;
                    backend.timeFromInt = timerSecondsRemaining.toString();
                    timerText.text = backend.timeFromInt;
                }
            }
        }
        Label {
            id: timerText
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 48
            text: "00:00:00"
        }
        RowLayout {
            Button {
                text: "+"
                onClicked: {
                    timerSecondsRemaining += 10
                    backend.timeFromInt = timerSecondsRemaining.toString();
                    timerText.text = backend.timeFromInt;
                }
            }
            Button {
                id: goButton
                text: "GO!"
                onClicked: {
                    if(timerSecondsRemaining == 0) {
                        text = "GO!";
                        ticking = false;
                    }
                    else if(timerSecondsRemaining != 0) {
                        ticking = !ticking;
                        text = ticking ? "STOP" : "GO!";
                    }
                }
            }
            Button {
                text: "-"
                onClicked: {
                    if(timerSecondsRemaining > 10)
                        timerSecondsRemaining -= 10
                    else
                        timerSecondsRemaining = 0;

                    backend.timeFromInt = timerSecondsRemaining.toString();
                    timerText.text = backend.timeFromInt;
                }
            }
        }
    }
    }
}
