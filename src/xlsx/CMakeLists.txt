cmake_minimum_required(VERSION 3.16)
project(QtXlsx VERSION 1.0 LANGUAGES C CXX)

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Core Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui)

set(XLSX_HEADERS
    xlsxdocpropscore_p.h
    xlsxdocpropsapp_p.h
    xlsxrelationships_p.h
    xlsxutility_p.h
    xlsxsharedstrings_p.h
    xlsxcontenttypes_p.h
    xlsxtheme_p.h
    xlsxformat.h
    xlsxworkbook.h
    xlsxstyles_p.h
    xlsxabstractsheet.h
    xlsxabstractsheet_p.h
    xlsxworksheet.h
    xlsxworksheet_p.h
    xlsxchartsheet.h
    xlsxchartsheet_p.h
    xlsxzipwriter_p.h
    xlsxworkbook_p.h
    xlsxformat_p.h
    xlsxglobal.h
    xlsxdrawing_p.h
    xlsxzipreader_p.h
    xlsxdocument.h
    xlsxdocument_p.h
    xlsxcell.h
    xlsxcell_p.h
    xlsxdatavalidation.h
    xlsxdatavalidation_p.h
    xlsxcellreference.h
    xlsxcellrange.h
    xlsxrichstring_p.h
    xlsxrichstring.h
    xlsxconditionalformatting.h
    xlsxconditionalformatting_p.h
    xlsxcolor_p.h
    xlsxnumformatparser_p.h
    xlsxdrawinganchor_p.h
    xlsxmediafile_p.h
    xlsxabstractooxmlfile.h
    xlsxabstractooxmlfile_p.h
    xlsxchart.h
    xlsxchart_p.h
    xlsxsimpleooxmlfile_p.h
    xlsxcellformula.h
    xlsxcellformula_p.h
)

set(XLSX_SOURCES
    xlsxdocpropscore.cpp
    xlsxdocpropsapp.cpp
    xlsxrelationships.cpp
    xlsxutility.cpp
    xlsxsharedstrings.cpp
    xlsxcontenttypes.cpp
    xlsxtheme.cpp
    xlsxformat.cpp
    xlsxstyles.cpp
    xlsxworkbook.cpp
    xlsxabstractsheet.cpp
    xlsxworksheet.cpp
    xlsxchartsheet.cpp
    xlsxzipwriter.cpp
    xlsxdrawing.cpp
    xlsxzipreader.cpp
    xlsxdocument.cpp
    xlsxcell.cpp
    xlsxdatavalidation.cpp
    xlsxcellreference.cpp
    xlsxcellrange.cpp
    xlsxrichstring.cpp
    xlsxconditionalformatting.cpp
    xlsxcolor.cpp
    xlsxnumformatparser.cpp
    xlsxdrawinganchor.cpp
    xlsxmediafile.cpp
    xlsxabstractooxmlfile.cpp
    xlsxchart.cpp
    xlsxsimpleooxmlfile.cpp
    xlsxcellformula.cpp
)

qt_add_library(QtXlsx STATIC
    ${XLSX_HEADERS}
    ${XLSX_SOURCES}
)

add_library(xlsx ALIAS QtXlsx)

target_include_directories(QtXlsx PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(QtXlsx PRIVATE
    Qt::Core
    Qt::Gui
    Qt::GuiPrivate
)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    target_compile_definitions(QtXlsx PRIVATE
        XLSX_TEST
    )
endif()

if(NOT build_xlsx_lib)
    target_compile_definitions(QtXlsx PRIVATE
        XLSX_NO_LIB
    )
endif()

install(TARGETS QtXlsx
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Consider using qt_generate_deploy_app_script() for app deployment if
# the project can use Qt 6.3. In that case rerun qmake2cmake with
# --min-qt-version=6.3.
# qt_internal_add_docs(QtXlsx
#     doc/qtxlsx.qdocconf
# )

