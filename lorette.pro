######################################################################
# Automatically generated by qmake (2.01a) lun. 21. f�vr. 17:49:45 2011
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . src
INCLUDEPATH += .

# Input
HEADERS += src/label.h src/lorette.h src/matrice.h src/resultat.h \
    src/settings.h
FORMS += src/lorette.ui \
    src/resultat.ui \
    src/settings.ui
SOURCES += src/label.cpp \
           src/lorette.cpp \
           src/main.cpp \
           src/matrice.cpp \
           src/resultat.cpp \
    src/settings.cpp

RESOURCES += \
    lorette.qrc

win32:RC_FILE += ico.rc
