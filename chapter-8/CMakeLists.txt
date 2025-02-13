cmake_minimum_required(VERSION 3.16)

project(Tutorial_8_Video VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appTutorial_8_Video
    main.cpp
)

qt_add_qml_module(appTutorial_8_Video
    URI Tutorial_8_Video
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES LogsFilter.h LogsFilter.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTutorial_8_Video PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTutorial_8_Video
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTutorial_8_Video
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appTutorial_8_Video
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
