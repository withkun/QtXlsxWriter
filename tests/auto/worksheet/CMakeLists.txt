qt_add_executable(tst_worksheet
    tst_worksheet.cpp
)
target_compile_definitions(tst_worksheet PRIVATE
    XLSX_TEST
)

target_link_libraries(tst_worksheet PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Test
    xlsx
)

install(TARGETS tst_worksheet
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Consider using qt_generate_deploy_app_script() for app deployment if
# the project can use Qt 6.3. In that case rerun qmake2cmake with
# --min-qt-version=6.3.
