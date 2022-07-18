cmake_minimum_required(VERSION 3.21.1)
project(Playing_With_Fire_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.2.4/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        REQUIRED)

add_executable(Playing_With_Fire_2 main.cpp src/windows/Home.cpp src/windows/Game.h src/windows/Game.cpp src/windows/Home.h src/windows/Start.h src/windows/Start.cpp src/windows/Setting.cpp src/windows/Setting.h src/windows/Guide.cpp src/windows/Guide.h src/windows/Final.cpp src/windows/Final.h src/views/TextField.cpp src/views/TextField.h src/views/Label.cpp src/views/Label.h src/views/Button.h src/views/Button.cpp resources.qrc src/views/Block.cpp src/views/Block.h src/views/Wall.cpp src/views/Wall.h src/views/Box.cpp src/views/Box.h src/views/Player.cpp src/views/Player.h src/views/Bomb.cpp src/views/Bomb.h)
target_link_libraries(Playing_With_Fire_2
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Multimedia
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
