import QtQuick
import QtQuick.Layouts

RowLayout {
    property string iconSource
    property string link
    property string label

    FontLoader {
        id: kapalFont
       // source: "qrc:/fonts/assets/Kapal.ttf"
        source: "assets/Kapal.ttf"
    }


    Image {
        id: icon
        source: iconSource
        Layout.preferredWidth: 30
        Layout.preferredHeight: 30
    }
    Text {
        id: hyperLinkText
        text: label
        font.pixelSize: 25
        font.family: kapalFont.name

        MouseArea {
            anchors.fill: parent
            onClicked: Qt.openUrlExternally(link)
            hoverEnabled: true
            onEntered: hyperLinkText.color = "blue"
            onExited: hyperLinkText.color = "black"
        }
    }
}
