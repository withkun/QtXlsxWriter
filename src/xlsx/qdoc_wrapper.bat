@echo off
SetLocal EnableDelayedExpansion
(set QT_VERSION=0.3.0)
(set QT_VER=0.3)
(set QT_VERSION_TAG=030)
(set QT_INSTALL_DOCS=D:/Qt/Docs/Qt-5.12.9)
(set BUILDDIR=D:/code/QtXlsxWriter64/QtXlsxWriter-master/src/xlsx)
D:\Qt\5.12.9\mingw73_64\bin\qdoc.exe %*
EndLocal
