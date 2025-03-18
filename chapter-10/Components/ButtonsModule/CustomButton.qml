import QtQuick

Item {
    id: root

    width: btnWidth
    height: btnHeight

    property alias btnWidth: rect.width
    property alias btnHeight: rect.height

    property alias bgColor: rect.color
    property alias textColor: sharedAlias.color
    Rectangle {id: sharedAlias}

    property alias text: buttonText.text

    signal clicked()

    property color storedBgColor
    property color storedTextColor
    Component.onCompleted: {
        storedBgColor = bgColor
        storedTextColor = textColor
    }

    Rectangle {
        id: rect
        radius: 10
        border.width: 2
        border.color: sharedAlias.color

        Text {
            id: buttonText
            anchors.centerIn: parent
            font.bold: true
            font.pixelSize: rect.height - 20
            color: sharedAlias.color
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onClicked: root.clicked()
            onEntered: {
                root.bgColor = storedTextColor
                root.textColor = storedBgColor
            }
            onExited: {
                root.textColor = storedTextColor
                root.bgColor = storedBgColor
            }
        }
    }
}

