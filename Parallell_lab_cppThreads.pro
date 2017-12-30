TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG += qt
QMAKE_CXXFLAGS+= -fopenmp
QMAKE_LFLAGS +=  -fopenmp


SOURCES += main.cpp \
    threadpool.cpp \
    abstractworkload.cpp \
    single_thread/singlethread.cpp \
    std_threads/stdthreadload.cpp \
    openMP/openmpload.cpp \
    MPILoad/mpiload.cpp \
    PthreadsLoad/pthreadsload.cpp \
    avxLoad/avxload.cpp \
    OpenCLLoad/openclload.cpp

HEADERS += \
    threadpool.h \
    abstractworkload.h \
    single_thread/singlethread.h \
    std_threads/stdthreadload.h \
    openMP/openmpload.h \
    MPILoad/mpiload.h \
    PthreadsLoad/pthreadsload.h \
    avxLoad/avxload.h \
    OpenCLLoad/openclload.h

INCLUDEPATH += "D:\DevTools\MPI_MS\Include"
LIBS += "D:\DevTools\MPI_MS\Lib\x64\msmpi.lib"
