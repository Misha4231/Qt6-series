import QtQuick
import QtQuick.Dialogs // file picking dialog window
import QtQuick.Layouts // arrange items in UI
import QtQuick.Controls // for things like buttons and dropdown list
import QtQuick.Controls.Material // for the beauty of the application
import Tutorial_8_Video 1.0

Window {
    id: root
    width: 700
    height: 500
    visible: true
    title: qsTr("Logs filter")

    LogsFilter {
        id: logsFilter1
        filePath: ""
    }
    LogsFilter {
        id: logsFilter2
        filePath: "someValue"
    }


    ColumnLayout {
        spacing: 12
        anchors.fill: parent
        anchors.margins: 20

        GroupBox {
            id: form
            title: "Logs filter"
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignTop
            font.bold: true

            ColumnLayout {
                spacing: 10
                Layout.fillWidth: true

                RowLayout {
                    Label {
                        text: "File: "
                        font.pixelSize: 14
                    }
                    TextField {
                        id: selectedFileName
                        text: logsFilter1.fileName
                        readOnly: true
                        Layout.fillWidth: true
                    }
                    Button {
                        text: "Select File"
                        onClicked: fileDialog.open()
                    }
                    FileDialog {
                        id: fileDialog
                        title: "Select a log file"
                        onAccepted: {
                            let filePath = fileDialog.selectedFile.toString();
                            logsFilter1.filePath = filePath;
                        }
                    }
                }
                RowLayout {
                    Label {
                        text: "Type: "
                        font.pixelSize: 14
                    }
                    ComboBox {
                        id: logTypeSelect
                        model: ["INFO", "ERROR", "WARNING"]
                        Layout.fillWidth: true
                    }
                }
            }
        }
        Button {
            id: searchButton
            text: "Search Logs"
            Layout.alignment: Qt.AlignHCenter
            Material.background: Material.Yellow
            onClicked: {
                logsFilter1.searchLogs(logTypeSelect.currentText);
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "white"
            border.color: "#b0bec5"
            border.width: 1
            radius: 8
            clip: true

            Flickable {
                anchors.fill: parent
                contentHeight: resultLogs.contentHeight
                clip: true

                TextEdit {
                    id: resultLogs
                    text: logsFilter1.filteredLogs
                    wrapMode: TextArea.WordWrap
                    readOnly: true
                    padding: 10
                    font.pixelSize: 14
                }
            }
        }
    }
}
