cmake_minimum_required(VERSION 3.16)

project(sudoku VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appsudoku
    main.cpp
    sudoku.cpp sudoku.h
    sudoku_exception.h
)

qt_add_executable(test
    test.cpp
    sudoku.cpp sudoku.h
    sudoku_exception.h
)

qt_add_qml_module(appsudoku
    URI sudoku
    VERSION 1.0
    QML_FILES qml/main.qml qml/views/MainMenuWindow.qml qml/views/GameWindow.qml qml/components/SudokuSquare.qml qml/views/LevelSelectionWindow.qml qml/components/CustomButton.qml qml/components/Title.qml
)

set_target_properties(appsudoku PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appsudoku
    PRIVATE Qt6::Quick)

install(TARGETS appsudoku
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
