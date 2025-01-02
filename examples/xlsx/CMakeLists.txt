cmake_minimum_required(VERSION 3.16)
project(examples VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Set up AUTOMOC and some sensible defaults for runtime execution
# When using Qt 6.3, you can replace the code block below with
# qt_standard_project_setup()
set(CMAKE_AUTOMOC ON)
include(GNUInstallDirs)

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Core)


add_subdirectory(hello)
add_subdirectory(extractdata)
add_subdirectory(style)
add_subdirectory(documentproperty)
add_subdirectory(image)
add_subdirectory(mergecells)
add_subdirectory(rowcolumn)
add_subdirectory(numberformat)
add_subdirectory(datavalidation)
add_subdirectory(definename)
add_subdirectory(formulas)
add_subdirectory(richtext)
add_subdirectory(conditionalformatting)
add_subdirectory(worksheetoperations)
add_subdirectory(hyperlinks)
add_subdirectory(chart)
add_subdirectory(chartsheet)
add_subdirectory(calendar)
add_subdirectory(demo)

if(TARGET Qt::Widgets)
    add_subdirectory(xlsxwidget)
endif()
