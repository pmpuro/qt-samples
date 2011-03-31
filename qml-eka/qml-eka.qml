import Qt 4.7  // tämä toimiii Qt 4.7.0 kirjaston kanssa
// import QtQuick 1.0 // tämä toimii Qt 4.7.1 ja uudemman kirjaston kanssa
Rectangle {
    width: 200
    height: 200

    Rectangle {
        id: akkuna
        width: parent.width
        height: parent.height
        color: "lightblue"

        Behavior on y {
            PropertyAnimation { duration: 1000 }
        }

        //    Row Column Grid

        Image {
            id: kuva
            source: "skull.png"

            Behavior on scale {
                PropertyAnimation { duration: 1000 }
            }
        }


        Text {
            property int property_name: 0

            signal oma_signaali()

            function oma_java_scripti_funktio() {
                // java scripti koodi tänne

            }

            id: teksti
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Hello World"
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                teksti.text = "vasenta nappia painettiin."
                teksti.oma_signaali()
                teksti.oma_java_scripti_funktio()

                kuva.scale = 0.6 + kuva.scale

                if (kuva.scale > 10) {
                    kuva.scale = 0.5
                }

                akkuna.y = -akkuna.height
                ikkuna.y = 0

            }
        }

        Timer {
            running: true
            interval: 5000
            repeat: true
            onTriggered: {
                if (akkuna.state == "oikein") {
                    akkuna.state = "väärin"
                } else {
                    akkuna.state = "oikein"
                }
            }
        }

        state: "oikein"

        states: [
            State {
                name: "oikein"
                PropertyChanges {
                    target: akkuna
                    rotation: 0
                }
            },
            State {
                name: "väärin"
                PropertyChanges {
                    target: akkuna
                    rotation: 180
                }
            }

        ]

        transitions: [
            Transition {
                from: "oikein"
                to: "väärin"
                PropertyAnimation {
                    target: akkuna
                    properties: "rotation"
                    duration: 500
                }
            },
            Transition {
                from: "väärin"
                to: "oikein"
                PropertyAnimation {
                    target: akkuna
                    properties: "rotation"
                    duration: 1500
                }
            }

        ]


    }

    Rectangle {
        id: ikkuna
        color: "red"
        width: parent.width
        height: parent.height

        Behavior on y {
            PropertyAnimation { duration: 1000 }
        }

        Column {
            anchors.fill: akkuna

            Text {
                text: "Tähän tulee jotain teksti"
            }

            Text {
                text: "Ja homma jatkuu tähän lisää"
            }

            Text {
                text: "Ja tekstiä suolletaan tänne lisää"
            }

        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                ikkuna.y = -ikkuna.height
                akkuna.y = 0
            }
        }
    }
}
