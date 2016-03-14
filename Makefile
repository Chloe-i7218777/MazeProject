#############################################################################
# Makefile for building: Maze
# Generated by qmake (3.0) (Qt 5.5.0)
# Project:  Maze.pro
# Template: app
# Command: /opt/qt/5.5/gcc_64/bin/qmake -spec linux-clang CONFIG+=debug -o Makefile Maze.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = clang
CXX           = clang++
DEFINES       = -DQT5BUILD -DNGL_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -I/usr/local/include/SDL2 -D_REENTRANT -msse -msse2 -msse3 -march=native -g -std=c++11 -Wall -W -Wno-unused-parameter -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -Iinclude -I/home/i7218777/NGL/include -I/opt/qt/5.5/gcc_64/include -I/opt/qt/5.5/gcc_64/include/QtGui -I/opt/qt/5.5/gcc_64/include/QtCore -I. -I/opt/qt/5.5/gcc_64/mkspecs/linux-clang
QMAKE         = /opt/qt/5.5/gcc_64/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = Maze1.0.0
DISTDIR = /home/i7218777/Programming/MazeProject/obj/Maze1.0.0
LINK          = clang++
LFLAGS        = -ccc-gcc-name g++ -Wl,-rpath,/opt/qt/5.5/gcc_64 -Wl,-rpath,/home/i7218777/NGL/lib -Wl,-rpath,/opt/qt/5.5/gcc_64/lib
LIBS          = $(SUBLIBS) -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL2 -L/home/i7218777/NGL/lib -l NGL -ltiff -L/opt/qt/5.5/gcc_64/lib -lQt5Gui -L/usr/lib64 -lQt5Core -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = obj/

####### Files

SOURCES       = src/main.cpp \
		src/Maze.cpp \
		src/Shader.cpp 
OBJECTS       = obj/main.o \
		obj/Maze.o \
		obj/Shader.o
DIST          = Maze.pro include/Maze.h \
		include/Shader.h src/main.cpp \
		src/Maze.cpp \
		src/Shader.cpp
QMAKE_TARGET  = Maze
DESTDIR       = #avoid trailing-slash linebreak
TARGET        = Maze


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Maze.pro .qmake.cache /opt/qt/5.5/gcc_64/mkspecs/linux-clang/qmake.conf /opt/qt/5.5/gcc_64/mkspecs/features/spec_pre.prf \
		/opt/qt/5.5/gcc_64/mkspecs/common/unix.conf \
		/opt/qt/5.5/gcc_64/mkspecs/common/linux.conf \
		/opt/qt/5.5/gcc_64/mkspecs/common/sanitize.conf \
		/opt/qt/5.5/gcc_64/mkspecs/common/gcc-base.conf \
		/opt/qt/5.5/gcc_64/mkspecs/common/gcc-base-unix.conf \
		/opt/qt/5.5/gcc_64/mkspecs/common/clang.conf \
		/opt/qt/5.5/gcc_64/mkspecs/qconfig.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dcore.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dcore_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dinput.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dinput_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dquick.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dquick_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dquickrenderer.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dquickrenderer_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3drenderer.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3drenderer_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_core.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_core_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_declarative.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_designer_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_enginio.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_gui_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_help.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_help_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_location.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_location_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_network.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_network_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_nfc.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_positioning.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_qml_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_quick_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_script.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_script_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_sql_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_svg_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_uiplugin.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webchannel.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webengine.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webengine_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webenginecore.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webenginecore_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webenginewidgets.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webkit.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_websockets.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webview_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_xml_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		/opt/qt/5.5/gcc_64/mkspecs/features/qt_functions.prf \
		/opt/qt/5.5/gcc_64/mkspecs/features/qt_config.prf \
		/opt/qt/5.5/gcc_64/mkspecs/linux-clang/qmake.conf \
		/opt/qt/5.5/gcc_64/mkspecs/features/spec_post.prf \
		.qmake.cache \
		/opt/qt/5.5/gcc_64/mkspecs/features/exclusive_builds.prf \
		/opt/qt/5.5/gcc_64/mkspecs/features/default_pre.prf \
		/home/i7218777/NGL/UseNGL.pri \
		/opt/qt/5.5/gcc_64/mkspecs/features/resolve_config.prf \
		/opt/qt/5.5/gcc_64/mkspecs/features/default_post.prf \
		/opt/qt/5.5/gcc_64/mkspecs/features/c++11.prf \
		/opt/qt/5.5/gcc_64/mkspecs/features/warn_on.prf \
		/opt/qt/5.5/gcc_64/mkspecs/features/qt.prf \
		/opt/qt/5.5/gcc_64/mkspecs/features/resources.prf \
		/opt/qt/5.5/gcc_64/mkspecs/features/moc.prf \
		/opt/qt/5.5/gcc_64/mkspecs/features/unix/opengl.prf \
		/opt/qt/5.5/gcc_64/mkspecs/features/unix/thread.prf \
		/opt/qt/5.5/gcc_64/mkspecs/features/testcase_targets.prf \
		/opt/qt/5.5/gcc_64/mkspecs/features/exceptions.prf \
		/opt/qt/5.5/gcc_64/mkspecs/features/yacc.prf \
		/opt/qt/5.5/gcc_64/mkspecs/features/lex.prf \
		Maze.pro \
		/opt/qt/5.5/gcc_64/lib/libQt5Gui.prl \
		/opt/qt/5.5/gcc_64/lib/libQt5Core.prl
	$(QMAKE) -spec linux-clang CONFIG+=debug -o Makefile Maze.pro
/opt/qt/5.5/gcc_64/mkspecs/features/spec_pre.prf:
/opt/qt/5.5/gcc_64/mkspecs/common/unix.conf:
/opt/qt/5.5/gcc_64/mkspecs/common/linux.conf:
/opt/qt/5.5/gcc_64/mkspecs/common/sanitize.conf:
/opt/qt/5.5/gcc_64/mkspecs/common/gcc-base.conf:
/opt/qt/5.5/gcc_64/mkspecs/common/gcc-base-unix.conf:
/opt/qt/5.5/gcc_64/mkspecs/common/clang.conf:
/opt/qt/5.5/gcc_64/mkspecs/qconfig.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dcore.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dcore_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dinput.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dinput_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dquick.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dquick_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dquickrenderer.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3dquickrenderer_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3drenderer.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_3drenderer_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_concurrent.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_core.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_core_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_dbus.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_declarative.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_designer.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_designer_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_enginio.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_gui.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_gui_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_help.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_help_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_location.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_location_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_multimedia.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_network.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_network_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_nfc.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_opengl.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_positioning.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_printsupport.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_qml.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_qml_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_qmltest.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_quick.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_quick_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_script.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_script_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_scripttools.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_sensors.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_serialport.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_sql.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_sql_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_svg.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_svg_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_testlib.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_uiplugin.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_uitools.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webchannel.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webengine.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webengine_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webenginecore.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webenginecore_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webenginewidgets.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webkit.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_websockets.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_webview_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_widgets.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_x11extras.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_xml.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_xml_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri:
/opt/qt/5.5/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
/opt/qt/5.5/gcc_64/mkspecs/features/qt_functions.prf:
/opt/qt/5.5/gcc_64/mkspecs/features/qt_config.prf:
/opt/qt/5.5/gcc_64/mkspecs/linux-clang/qmake.conf:
/opt/qt/5.5/gcc_64/mkspecs/features/spec_post.prf:
.qmake.cache:
/opt/qt/5.5/gcc_64/mkspecs/features/exclusive_builds.prf:
/opt/qt/5.5/gcc_64/mkspecs/features/default_pre.prf:
/home/i7218777/NGL/UseNGL.pri:
/opt/qt/5.5/gcc_64/mkspecs/features/resolve_config.prf:
/opt/qt/5.5/gcc_64/mkspecs/features/default_post.prf:
/opt/qt/5.5/gcc_64/mkspecs/features/c++11.prf:
/opt/qt/5.5/gcc_64/mkspecs/features/warn_on.prf:
/opt/qt/5.5/gcc_64/mkspecs/features/qt.prf:
/opt/qt/5.5/gcc_64/mkspecs/features/resources.prf:
/opt/qt/5.5/gcc_64/mkspecs/features/moc.prf:
/opt/qt/5.5/gcc_64/mkspecs/features/unix/opengl.prf:
/opt/qt/5.5/gcc_64/mkspecs/features/unix/thread.prf:
/opt/qt/5.5/gcc_64/mkspecs/features/testcase_targets.prf:
/opt/qt/5.5/gcc_64/mkspecs/features/exceptions.prf:
/opt/qt/5.5/gcc_64/mkspecs/features/yacc.prf:
/opt/qt/5.5/gcc_64/mkspecs/features/lex.prf:
Maze.pro:
/opt/qt/5.5/gcc_64/lib/libQt5Gui.prl:
/opt/qt/5.5/gcc_64/lib/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -spec linux-clang CONFIG+=debug -o Makefile Maze.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents include/Maze.h include/Shader.h $(DISTDIR)/
	$(COPY_FILE) --parents src/main.cpp src/Maze.cpp src/Shader.cpp $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

obj/main.o: src/main.cpp include/Maze.h \
		/home/i7218777/NGL/include/ngl/Vec3.h \
		/home/i7218777/NGL/include/ngl/Types.h \
		/home/i7218777/NGL/include/ngl/glew.h \
		/opt/qt/5.5/gcc_64/include/QtOpenGL/QGLContext \
		/opt/qt/5.5/gcc_64/include/QtOpenGL/qgl.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qopengl.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qglobal.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qconfig.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qfeatures.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qsystemdetection.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qprocessordetection.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qcompilerdetection.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qtypeinfo.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qtypetraits.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qsysinfo.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qlogging.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qflags.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qbasicatomic.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_bootstrap.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qgenericatomic.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_cxx11.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_gcc.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_msvc.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_armv7.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_armv6.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_armv5.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_ia64.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_mips.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_x86.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_unix.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qglobalstatic.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qmutex.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qnumeric.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qt_windows.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qopengles2ext.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qopenglext.h \
		/opt/qt/5.5/gcc_64/include/QtWidgets/qwidget.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qwindowdefs.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qobjectdefs.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qnamespace.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qobjectdefs_impl.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qwindowdefs_win.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qobject.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qstring.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qchar.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qbytearray.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qrefcount.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qarraydata.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qstringbuilder.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qlist.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qalgorithms.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qiterator.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qbytearraylist.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qstringlist.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qregexp.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qstringmatcher.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qcoreevent.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qscopedpointer.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qmetatype.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qvarlengtharray.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qcontainerfwd.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qisenum.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qobject_impl.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qmargins.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpaintdevice.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qrect.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qsize.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qpoint.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpalette.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qcolor.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qrgb.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qbrush.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qpair.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qvector.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qmatrix.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpolygon.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qregion.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qdatastream.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qiodevice.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qline.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qtransform.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpainterpath.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qimage.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpixelformat.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpixmap.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qsharedpointer.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qshareddata.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qhash.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qsharedpointer_impl.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qfont.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qfontmetrics.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qfontinfo.h \
		/opt/qt/5.5/gcc_64/include/QtWidgets/qsizepolicy.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qcursor.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qkeysequence.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qevent.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qvariant.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qmap.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qdebug.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qtextstream.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qlocale.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qset.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qcontiguouscache.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qurl.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qurlquery.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qfile.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qfiledevice.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qvector2d.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qtouchdevice.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpaintengine.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpainter.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qtextoption.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpen.h \
		/opt/qt/5.5/gcc_64/include/QtOpenGL/qglcolormap.h \
		/opt/qt/5.5/gcc_64/include/QtOpenGL/qtopenglglobal.h \
		/opt/qt/5.5/gcc_64/include/QtGui/QSurfaceFormat \
		/opt/qt/5.5/gcc_64/include/QtGui/qsurfaceformat.h \
		/home/i7218777/NGL/include/ngl/Camera.h \
		/home/i7218777/NGL/include/ngl/Vec4.h \
		/home/i7218777/NGL/include/ngl/Vec2.h \
		/home/i7218777/NGL/include/ngl/Mat4.h \
		/home/i7218777/NGL/include/ngl/RibExport.h \
		/home/i7218777/NGL/include/ngl/Plane.h \
		/home/i7218777/NGL/include/ngl/AABB.h \
		/home/i7218777/NGL/include/ngl/BBox.h \
		/home/i7218777/NGL/include/ngl/VertexArrayObject.h \
		/home/i7218777/NGL/include/ngl/Light.h \
		/home/i7218777/NGL/include/ngl/Colour.h \
		/home/i7218777/NGL/include/ngl/Transformation.h \
		/home/i7218777/NGL/include/ngl/NGLassert.h \
		include/Shader.h \
		/home/i7218777/NGL/include/ngl/NGLInit.h \
		/home/i7218777/NGL/include/ngl/Singleton.h \
		/home/i7218777/NGL/include/ngl/VAOPrimitives.h \
		/home/i7218777/NGL/include/ngl/Util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/main.o src/main.cpp

obj/Maze.o: src/Maze.cpp include/Maze.h \
		/home/i7218777/NGL/include/ngl/Vec3.h \
		/home/i7218777/NGL/include/ngl/Types.h \
		/home/i7218777/NGL/include/ngl/glew.h \
		/opt/qt/5.5/gcc_64/include/QtOpenGL/QGLContext \
		/opt/qt/5.5/gcc_64/include/QtOpenGL/qgl.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qopengl.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qglobal.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qconfig.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qfeatures.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qsystemdetection.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qprocessordetection.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qcompilerdetection.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qtypeinfo.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qtypetraits.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qsysinfo.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qlogging.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qflags.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qbasicatomic.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_bootstrap.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qgenericatomic.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_cxx11.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_gcc.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_msvc.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_armv7.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_armv6.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_armv5.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_ia64.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_mips.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_x86.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_unix.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qglobalstatic.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qmutex.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qnumeric.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qt_windows.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qopengles2ext.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qopenglext.h \
		/opt/qt/5.5/gcc_64/include/QtWidgets/qwidget.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qwindowdefs.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qobjectdefs.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qnamespace.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qobjectdefs_impl.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qwindowdefs_win.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qobject.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qstring.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qchar.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qbytearray.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qrefcount.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qarraydata.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qstringbuilder.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qlist.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qalgorithms.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qiterator.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qbytearraylist.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qstringlist.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qregexp.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qstringmatcher.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qcoreevent.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qscopedpointer.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qmetatype.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qvarlengtharray.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qcontainerfwd.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qisenum.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qobject_impl.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qmargins.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpaintdevice.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qrect.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qsize.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qpoint.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpalette.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qcolor.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qrgb.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qbrush.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qpair.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qvector.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qmatrix.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpolygon.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qregion.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qdatastream.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qiodevice.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qline.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qtransform.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpainterpath.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qimage.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpixelformat.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpixmap.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qsharedpointer.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qshareddata.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qhash.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qsharedpointer_impl.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qfont.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qfontmetrics.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qfontinfo.h \
		/opt/qt/5.5/gcc_64/include/QtWidgets/qsizepolicy.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qcursor.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qkeysequence.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qevent.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qvariant.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qmap.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qdebug.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qtextstream.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qlocale.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qset.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qcontiguouscache.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qurl.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qurlquery.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qfile.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qfiledevice.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qvector2d.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qtouchdevice.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpaintengine.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpainter.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qtextoption.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpen.h \
		/opt/qt/5.5/gcc_64/include/QtOpenGL/qglcolormap.h \
		/opt/qt/5.5/gcc_64/include/QtOpenGL/qtopenglglobal.h \
		/opt/qt/5.5/gcc_64/include/QtGui/QSurfaceFormat \
		/opt/qt/5.5/gcc_64/include/QtGui/qsurfaceformat.h \
		/home/i7218777/NGL/include/ngl/Camera.h \
		/home/i7218777/NGL/include/ngl/Vec4.h \
		/home/i7218777/NGL/include/ngl/Vec2.h \
		/home/i7218777/NGL/include/ngl/Mat4.h \
		/home/i7218777/NGL/include/ngl/RibExport.h \
		/home/i7218777/NGL/include/ngl/Plane.h \
		/home/i7218777/NGL/include/ngl/AABB.h \
		/home/i7218777/NGL/include/ngl/BBox.h \
		/home/i7218777/NGL/include/ngl/VertexArrayObject.h \
		/home/i7218777/NGL/include/ngl/ShaderLib.h \
		/home/i7218777/NGL/include/ngl/Colour.h \
		/home/i7218777/NGL/include/ngl/Shader.h \
		/home/i7218777/NGL/include/ngl/ShaderProgram.h \
		/home/i7218777/NGL/include/ngl/Util.h \
		/home/i7218777/NGL/include/ngl/Singleton.h \
		/home/i7218777/NGL/include/ngl/Mat3.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/Maze.o src/Maze.cpp

obj/Shader.o: src/Shader.cpp /home/i7218777/NGL/include/ngl/Shader.h \
		/home/i7218777/NGL/include/ngl/Types.h \
		/home/i7218777/NGL/include/ngl/glew.h \
		/opt/qt/5.5/gcc_64/include/QtOpenGL/QGLContext \
		/opt/qt/5.5/gcc_64/include/QtOpenGL/qgl.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qopengl.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qglobal.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qconfig.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qfeatures.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qsystemdetection.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qprocessordetection.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qcompilerdetection.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qtypeinfo.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qtypetraits.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qsysinfo.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qlogging.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qflags.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qbasicatomic.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_bootstrap.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qgenericatomic.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_cxx11.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_gcc.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_msvc.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_armv7.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_armv6.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_armv5.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_ia64.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_mips.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_x86.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qatomic_unix.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qglobalstatic.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qmutex.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qnumeric.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qt_windows.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qopengles2ext.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qopenglext.h \
		/opt/qt/5.5/gcc_64/include/QtWidgets/qwidget.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qwindowdefs.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qobjectdefs.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qnamespace.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qobjectdefs_impl.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qwindowdefs_win.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qobject.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qstring.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qchar.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qbytearray.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qrefcount.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qarraydata.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qstringbuilder.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qlist.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qalgorithms.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qiterator.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qbytearraylist.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qstringlist.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qregexp.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qstringmatcher.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qcoreevent.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qscopedpointer.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qmetatype.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qvarlengtharray.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qcontainerfwd.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qisenum.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qobject_impl.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qmargins.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpaintdevice.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qrect.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qsize.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qpoint.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpalette.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qcolor.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qrgb.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qbrush.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qpair.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qvector.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qmatrix.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpolygon.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qregion.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qdatastream.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qiodevice.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qline.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qtransform.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpainterpath.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qimage.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpixelformat.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpixmap.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qsharedpointer.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qshareddata.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qhash.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qsharedpointer_impl.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qfont.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qfontmetrics.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qfontinfo.h \
		/opt/qt/5.5/gcc_64/include/QtWidgets/qsizepolicy.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qcursor.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qkeysequence.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qevent.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qvariant.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qmap.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qdebug.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qtextstream.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qlocale.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qset.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qcontiguouscache.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qurl.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qurlquery.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qfile.h \
		/opt/qt/5.5/gcc_64/include/QtCore/qfiledevice.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qvector2d.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qtouchdevice.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpaintengine.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpainter.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qtextoption.h \
		/opt/qt/5.5/gcc_64/include/QtGui/qpen.h \
		/opt/qt/5.5/gcc_64/include/QtOpenGL/qglcolormap.h \
		/opt/qt/5.5/gcc_64/include/QtOpenGL/qtopenglglobal.h \
		/opt/qt/5.5/gcc_64/include/QtGui/QSurfaceFormat \
		/opt/qt/5.5/gcc_64/include/QtGui/qsurfaceformat.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/Shader.o src/Shader.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

