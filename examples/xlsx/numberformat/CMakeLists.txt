qt_add_executable(numberformat
    main.cpp
)

target_link_libraries(numberformat PRIVATE
    Qt::Core
    Qt::Gui
    xlsx
)

install(TARGETS numberformat
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Consider using qt_generate_deploy_app_script() for app deployment if
# the project can use Qt 6.3. In that case rerun qmake2cmake with
# --min-qt-version=6.3.
