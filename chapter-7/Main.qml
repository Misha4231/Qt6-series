import QtQuick

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: "Welcome App"

    Text {
        text: "Welcome to Qt Quick!"
        font.pixelSize: 24
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 20
    }
    Text {
        id: welcomeMessage
        text: "Hello, World!"
        font.pixelSize: 20
        anchors.centerIn: parent
    }
    Rectangle {
        width: 150
        height: 40
        color: "blue"
        radius: 8
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20

        Text {
            text: "Click Me!"
            color: "white"
            font.pixelSize: 18
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                welcomeMessage.text = "You clicked the button!"
                console.log("CLICK")
            }
        }
    }
}
