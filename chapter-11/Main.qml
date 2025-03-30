import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import Tutorial_11_Video 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ContactsModel {
        id: contactsData
    }

    ColumnLayout {
        ListExample {
            model: contactsData
        }

        Button {
            text: "Add"
            onClicked: contactsData.appendEmptyRow()
        }
    }
}
