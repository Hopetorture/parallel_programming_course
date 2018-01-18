TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG += qt
#CONFIG += -lOpenCL
QMAKE_CXXFLAGS += -fopenmp
QMAKE_CXXFLAGS += -mavx2
#QMAKE_CXXFLAGS += -lOpenCL
#QMAKE_CFLAGS += -mavx2
#QMAKE_LFLAGS += -mavx2
QMAKE_LFLAGS +=  -fopenmp
#QMAKE_CXXFLAGS += $$QMAKE_CFLAGS_AVX
#INCLUDEPATH += D:\DevTools\Opencl-Intel\OpenCL\sdk\include\
#LIBS += -LD:\DevTools\Opencl-Intel\OpenCL\sdk\lib\x64\OpenCL.lib -lOpenCL
#DEPENDPATH += D:\DevTools\Opencl-Intel\OpenCL\sdk\lib\x64\


SOURCES += main.cpp \
    threadpool.cpp \
    abstractworkload.cpp \
    single_thread/singlethread.cpp \
    std_threads/stdthreadload.cpp \
    openMP/openmpload.cpp \
    MPILoad/mpiload.cpp \
    PthreadsLoad/pthreadsload.cpp \
    #avxLoad/avxload.cpp \
    OpenCLLoad/openclload.cpp \
    #avxLoad/md5_avx2.cpp
    avxLoad/avxload.cpp \
    avxLoad/md5_avx2.cpp \
    ##openmpi/main.cpp

HEADERS += \
    threadpool.h \
    abstractworkload.h \
    single_thread/singlethread.h \
    std_threads/stdthreadload.h \
    openMP/openmpload.h \
    MPILoad/mpiload.h \
    PthreadsLoad/pthreadsload.h \
    #avxLoad/avxload.h \
    OpenCLLoad/openclload.h \
    #avxLoad/md5_avx2.h \
    #avxLoad/md5_loc.h
    avxLoad/avxload.h \
    avxLoad/md5_avx2.h \
    avxLoad/md5_loc.h

#INCLUDEPATH += "D:\DevTools\MPI_MS\Include"
#LIBS += "D:\DevTools\MPI_MS\Lib\x64\msmpi.lib"


#SUBDIRS += \
 #   openmpi/qt-hash.pro

#DISTFILES += \
#   openmpi/a.out \
#    openmpi/0 \
 #   openmpi/1 \
#    openmpi/2 \
#    openmpi/run.py \
#    openmpi/readme
