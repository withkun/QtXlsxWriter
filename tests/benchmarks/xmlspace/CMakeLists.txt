qt_add_executable(tst_xmlspacetest
    tst_xmlspacetest.cpp
)

target_compile_definitions(tst_xmlspacetest PRIVATE
    XLSX_TEST
)

target_link_libraries(tst_xmlspacetest PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Test
)

install(TARGETS tst_xmlspacetest
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Consider using qt_generate_deploy_app_script() for app deployment if
# the project can use Qt 6.3. In that case rerun qmake2cmake with
# --min-qt-version=6.3.
