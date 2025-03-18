import QtQuick
import StyleModule 1.0
import Components.ButtonsModule 1.0

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Buttons")

    Column {
        spacing: 10
        anchors.centerIn: parent

        PrimaryButton {
            btnWidth: 200
            btnHeight: 40
            text: "Click me"

            onClicked: {
                console.log("[Click] PrimaryButton");
            }
        }
        SecondaryButton {
            btnWidth: 200
            btnHeight: 40
            text: "Click me"

            onClicked: {
                console.log("[Click] SecondaryButton");
            }
        }

        DangerButton {
            btnWidth: 200
            btnHeight: 40
            text: "Click me"

            onClicked: {
                console.log("[Click] DangerButton");
            }
        }
    }



    Rectangle {
        id: _background
        z: -100

        anchors.fill: parent
        color: Styles.backgroundColor
    }
}
