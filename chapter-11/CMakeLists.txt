cmake_minimum_required(VERSION 3.16)

project(Tutorial_11_Video VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appTutorial_11_Video
    main.cpp
)

qt_add_qml_module(appTutorial_11_Video
    URI Tutorial_11_Video
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES ListExample.qml
        QML_FILES ExampleDataset.qml
        QML_FILES GridExample.qml
        SOURCES contactsmodel.h contactsmodel.cpp
        QML_FILES EditableText.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTutorial_11_Video PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTutorial_11_Video
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTutorial_11_Video
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appTutorial_11_Video
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
