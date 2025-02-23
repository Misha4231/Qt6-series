import QtQuick
import QtQuick.Layouts

Window {
    id: root
    width: 750
    height: 700
    visible: true
    title: qsTr("Profile")

    RowLayout {
        id: container
        anchors.fill: parent

        ColumnLayout {
            Layout.preferredWidth: parent.width / 2

            Image {
                Layout.alignment: Qt.AlignRight
                source: "assets/logo.png"

                Layout.preferredWidth: 250
                Layout.preferredHeight: 250
            }
        }
        ColumnLayout {
            Layout.preferredWidth: parent.width / 2

            ProfileLink {
                //iconSource: "qrc:/icons/assets/instagram.png"
                iconSource: "assets/instagram.png"
                link: "https://www.instagram.com/misha.dev.diary/"
                label: "Instagram"
            }
            ProfileLink {
                //iconSource: "qrc:/icons/assets/youtube.png"
                iconSource: "assets/youtube.png"
                link: "https://www.youtube.com/@misha.devDiary"
                label: "Youtube"
            }
            ProfileLink {
               // iconSource: "qrc:/icons/assets/medium.png"
                iconSource: "assets/medium.png"
                link: "https://medium.com/@mishagalko5"
                label: "Medium"
            }
        }

    }
}
