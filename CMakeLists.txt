cmake_minimum_required(VERSION 3.16)
project(QtXlsx VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Core Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui)

set(XLSX_HEADERS
    include/QtXlsx/qtxlsxversion.h
    include/QtXlsx/xlsxabstractooxmlfile.h
    include/QtXlsx/xlsxabstractsheet.h
    include/QtXlsx/xlsxcell.h
    include/QtXlsx/xlsxcellformula.h
    include/QtXlsx/xlsxcellrange.h
    include/QtXlsx/xlsxcellreference.h
    include/QtXlsx/xlsxchart.h
    include/QtXlsx/xlsxchartsheet.h
    include/QtXlsx/xlsxconditionalformatting.h
    include/QtXlsx/xlsxdatavalidation.h
    include/QtXlsx/xlsxdocument.h
    include/QtXlsx/xlsxformat.h
    include/QtXlsx/xlsxglobal.h
    include/QtXlsx/xlsxrichstring.h
    include/QtXlsx/xlsxworkbook.h
    include/QtXlsx/xlsxworksheet.h
)

set(XLSX_HEADERS_PRIVATE
    include/QtXlsx/private/xlsxabstractooxmlfile_p.h
    include/QtXlsx/private/xlsxabstractsheet_p.h
    include/QtXlsx/private/xlsxcell_p.h
    include/QtXlsx/private/xlsxcellformula_p.h
    include/QtXlsx/private/xlsxchart_p.h
    include/QtXlsx/private/xlsxchartsheet_p.h
    include/QtXlsx/private/xlsxcolor_p.h
    include/QtXlsx/private/xlsxconditionalformatting_p.h
    include/QtXlsx/private/xlsxcontenttypes_p.h
    include/QtXlsx/private/xlsxdatavalidation_p.h
    include/QtXlsx/private/xlsxdocpropsapp_p.h
    include/QtXlsx/private/xlsxdocpropscore_p.h
    include/QtXlsx/private/xlsxdocument_p.h
    include/QtXlsx/private/xlsxdrawing_p.h
    include/QtXlsx/private/xlsxdrawinganchor_p.h
    include/QtXlsx/private/xlsxformat_p.h
    include/QtXlsx/private/xlsxmediafile_p.h
    include/QtXlsx/private/xlsxnumformatparser_p.h
    include/QtXlsx/private/xlsxrelationships_p.h
    include/QtXlsx/private/xlsxrichstring_p.h
    include/QtXlsx/private/xlsxsharedstrings_p.h
    include/QtXlsx/private/xlsxsimpleooxmlfile_p.h
    include/QtXlsx/private/xlsxstyles_p.h
    include/QtXlsx/private/xlsxtheme_p.h
    include/QtXlsx/private/xlsxutility_p.h
    include/QtXlsx/private/xlsxworkbook_p.h
    include/QtXlsx/private/xlsxworksheet_p.h
    include/QtXlsx/private/xlsxzipreader_p.h
    include/QtXlsx/private/xlsxzipwriter_p.h
)

set(XLSX_SOURCES
    src/xlsx/xlsxdocpropscore.cpp
    src/xlsx/xlsxdocpropsapp.cpp
    src/xlsx/xlsxrelationships.cpp
    src/xlsx/xlsxutility.cpp
    src/xlsx/xlsxsharedstrings.cpp
    src/xlsx/xlsxcontenttypes.cpp
    src/xlsx/xlsxtheme.cpp
    src/xlsx/xlsxformat.cpp
    src/xlsx/xlsxstyles.cpp
    src/xlsx/xlsxworkbook.cpp
    src/xlsx/xlsxabstractsheet.cpp
    src/xlsx/xlsxworksheet.cpp
    src/xlsx/xlsxchartsheet.cpp
    src/xlsx/xlsxzipwriter.cpp
    src/xlsx/xlsxdrawing.cpp
    src/xlsx/xlsxzipreader.cpp
    src/xlsx/xlsxdocument.cpp
    src/xlsx/xlsxcell.cpp
    src/xlsx/xlsxdatavalidation.cpp
    src/xlsx/xlsxcellreference.cpp
    src/xlsx/xlsxcellrange.cpp
    src/xlsx/xlsxrichstring.cpp
    src/xlsx/xlsxconditionalformatting.cpp
    src/xlsx/xlsxcolor.cpp
    src/xlsx/xlsxnumformatparser.cpp
    src/xlsx/xlsxdrawinganchor.cpp
    src/xlsx/xlsxmediafile.cpp
    src/xlsx/xlsxabstractooxmlfile.cpp
    src/xlsx/xlsxchart.cpp
    src/xlsx/xlsxsimpleooxmlfile.cpp
    src/xlsx/xlsxcellformula.cpp
)

add_library(QtXlsx STATIC
    ${XLSX_HEADERS}
    ${XLSX_HEADERS_PRIVATE}
    ${XLSX_SOURCES}
)

target_include_directories(QtXlsx PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/QtXlsx
    ${CMAKE_CURRENT_SOURCE_DIR}/include/QtXlsx/private
)

target_link_libraries(QtXlsx PRIVATE
    Qt::Core
    Qt::Gui
    Qt::GuiPrivate
)

target_compile_definitions(QtXlsx PRIVATE
    XLSX_NO_LIB
)

#add_subdirectory(src)
add_library(xlsx ALIAS QtXlsx)

add_subdirectory(tests)
add_subdirectory(examples)
