cmake_minimum_required(VERSION 3.16)

project(Tutorial_9_Video VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appTutorial_9_Video
    main.cpp
)

file(GLOB_RECURSE ASSET_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} assets/*)

qt_add_qml_module(appTutorial_9_Video
    URI Tutorial_9_Video
    VERSION 1.0
    QML_FILES
        Main.qml
       # RESOURCES resources.qrc
        QML_FILES ProfileLink.qml
        # RESOURCES assets/instagram.png
        # assets/Kapal.ttf
        # assets/logo.png
        # assets/medium.png
        # assets/youtube.png
        RESOURCES ${ASSET_FILES}
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTutorial_9_Video PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTutorial_9_Video
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTutorial_9_Video
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appTutorial_9_Video
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
