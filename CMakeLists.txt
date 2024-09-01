cmake_minimum_required(VERSION 3.16)

project(MagicPacketTool VERSION 0.1 LANGUAGES CXX)

# Enable automatic MOC, UIC, and RCC handling
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt packages
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools Network)

# Translation files
set(TS_FILES MagicPacketTool_en_US.ts)

# Source files
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    resources.qrc
    ${TS_FILES}
)

# Add executable for Qt6
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MagicPacketTool
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
# Add executable for Qt5
else()
    qt5_wrap_ui(UI_SOURCES mainwindow.ui)
    qt5_add_resources(RESOURCE_SOURCES resources.qrc)

    if(ANDROID)
        add_library(MagicPacketTool SHARED
            ${PROJECT_SOURCES}
            ${UI_SOURCES}
            ${RESOURCE_SOURCES}
        )
    else()
        add_executable(MagicPacketTool
            ${PROJECT_SOURCES}
            ${UI_SOURCES}
            ${RESOURCE_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

# Link libraries
target_link_libraries(MagicPacketTool PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)

# Set properties
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.MagicPacketTool)
endif()

set_target_properties(MagicPacketTool PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Install targets
include(GNUInstallDirs)
install(TARGETS MagicPacketTool
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalize executable for Qt6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MagicPacketTool)
endif()
