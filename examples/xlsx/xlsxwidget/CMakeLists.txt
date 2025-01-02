qt_add_executable(xlsxwidget WIN32 MACOSX_BUNDLE
    main.cpp
    xlsxsheetmodel.cpp xlsxsheetmodel.h xlsxsheetmodel_p.h
)

target_link_libraries(xlsxwidget PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets
    xlsx
)

install(TARGETS xlsxwidget
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Consider using qt_generate_deploy_app_script() for app deployment if
# the project can use Qt 6.3. In that case rerun qmake2cmake with
# --min-qt-version=6.3.
