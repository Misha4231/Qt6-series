pragma Singleton
import QtQuick

QtObject { // like QObject in C++
    property bool isDarkTheme: true
    readonly property color primaryColor: isDarkTheme ? "#5c85ff" : "#003cee"
    readonly property color secondaryColor: "#da9603"
    readonly property color backgroundColor: isDarkTheme ? "#121212" : "#FFFFFF"
    readonly property color errorColor: isDarkTheme ? "#cc3737" : "#d6042a"
    readonly property color textColor: isDarkTheme ? "#FFFFFF" : "#000000"
}
// Item - can be displayed
// QtObject - store values
