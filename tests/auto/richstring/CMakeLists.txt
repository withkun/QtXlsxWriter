qt_add_executable(tst_richstringtest
    tst_richstringtest.cpp
)
target_compile_definitions(tst_richstringtest PRIVATE
    XLSX_TEST
)

target_link_libraries(tst_richstringtest PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Test
    xlsx
)

install(TARGETS tst_richstringtest
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Consider using qt_generate_deploy_app_script() for app deployment if
# the project can use Qt 6.3. In that case rerun qmake2cmake with
# --min-qt-version=6.3.
