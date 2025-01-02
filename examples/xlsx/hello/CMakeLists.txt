qt_add_executable(hello
    main.cpp
)

target_link_libraries(hello PRIVATE
    Qt::Core
    Qt::Gui
    xlsx
)

install(TARGETS hello
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Consider using qt_generate_deploy_app_script() for app deployment if
# the project can use Qt 6.3. In that case rerun qmake2cmake with
# --min-qt-version=6.3.
