import Qt 4.7

Rectangle {
    width: 240
    height: 180
    color: "lightblue"

    Text {
        id: theText
        anchors.centerIn: parent
        text: "counter = " + theCounter.currentValue
    }

    Text {
        anchors.top: theText.bottom
        anchors.horizontalCenter: theText.horizontalCenter
        id: theOtherText
        text: ""
    }



    MouseArea {
        anchors.fill: parent
        onClicked: {
            theCounter.increase()
        }
    }

    Connections {
        target: theCounter
        onReached10: {
            theOtherText.text = "Tämä tuli signaalista = " + value
        }
    }
}
