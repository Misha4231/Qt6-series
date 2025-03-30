import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ListView {
    id: list
    width: 300
    height: 200
    spacing: 5

    delegate: Frame {
        width: list.width
        RowLayout {
            anchors.fill: parent

            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                EditableText {
                    field: name
                }

                Text {
                    text: " : "
                    font.pointSize: 16
                }

                EditableText {
                    field: email
                }
            }

            Button {
                Layout.alignment: Qt.AlignRight
                text: "-"
                onClicked: {
                    list.model.removeAt(model.row);
                }
                font.pointSize: 20
            }
        }
    }

    header: Rectangle {
        width: parent.width
        height: 30
        color: "red"
        Text {
            text: "Contacts list"
            color: "white"
            font.pointSize: 18
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    footer: Rectangle {
        width: parent.width
        height: 20
        color: "red"
        z: 10
    }
    footerPositioning: ListView.OverlayFooter
}
