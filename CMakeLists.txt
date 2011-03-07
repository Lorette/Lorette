  PROJECT( lorette )
  
  SET( lorette_SRCS
       ./src/lorette.cpp
       ./src/main.cpp
       ./src/matrice.cpp
       ./src/resultat.cpp
       ./src/label.cpp
       ./src/settings.cpp
  )
  
  SET( lorette_MOC_HDRS
       ./src/lorette.h
       ./src/matrice.h
       ./src/resultat.h      
       ./src/label.h      
       ./src/settings.h      
  )

  SET( lorette_UIS
       ./src/lorette.ui
       ./src/resultat.ui
       ./src/settings.ui
  )
  
  SET( lorette_RCS
       ./lorette.qrc
  )
  
  ADD_DEFINITIONS( -Wall )
  
  SET( QT_USE_QT3SUPPORT TRUE )   
  SET( QT_USE_QTXML TRUE )
  
  FIND_PACKAGE( Qt4 REQUIRED )
  
  INCLUDE( ${QT_USE_FILE} )
  
  QT4_ADD_RESOURCES( lorette_RC_SRCS ${lorette_RCS} )
  
  QT4_WRAP_UI( lorette_UI_HDRS ${lorette_UIS} )
  
  QT4_WRAP_CPP( lorette_MOC_SRCS ${lorette_MOC_HDRS} )
  
  INCLUDE_DIRECTORIES( ${CMAKE_BINARY_DIR} )
  
  ADD_EXECUTABLE( lorette ${lorette_SRCS} ${lorette_MOC_SRCS} ${lorette_RC_SRCS} ${lorette_UI_HDRS} )
  
  TARGET_LINK_LIBRARIES( lorette ${QT_LIBRARIES} )

