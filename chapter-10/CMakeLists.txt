cmake_minimum_required(VERSION 3.16)

project(Tutorial_10_Video VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appTutorial_10_Video
    main.cpp
)

qt_add_qml_module(appTutorial_10_Video
    URI Tutorial_10_Video
    VERSION 1.0
    QML_FILES
        Main.qml
RESOURCES Components/ButtonsModule/qmldir StyleModule/qmldir
QML_FILES Components/ButtonsModule/CustomButton.qml Components/ButtonsModule/DangerButton.qml Components/ButtonsModule/PrimaryButton.qml Components/ButtonsModule/SecondaryButton.qml StyleModule/Styles.qml
)

list(APPEND QML_DIRS ${CMAKE_SOURCE_DIR})
set(QML_IMPORT_PATH "${QML_DIRS}" CACHE STRING "Qt Creator 15.0.1 extra qml import paths")

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTutorial_10_Video PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTutorial_10_Video
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTutorial_10_Video
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appTutorial_10_Video
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
