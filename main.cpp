#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include "single_thread/singlethread.h"
#include "std_threads/stdthreadload.h"
#include "openMP/openmpload.h"
#include "PthreadsLoad/pthreadsload.h"
#include "avxLoad/avxload.h"


using namespace std;

std::mutex g_display_mutex;

int foo()
{
    std::thread::id this_id = std::this_thread::get_id();

    g_display_mutex.lock();
    std::cout << "thread " << this_id << " sleeping...\n";
    g_display_mutex.unlock();
    return 2 + 2;
    //std::this_thread::sleep_for(std::chrono::seconds(1));

}


int main(int argc, char *argv[])
{
    AbstractWorkload *st = new SingleThread();
    //st->setPrecision(st->precision::milsec);
    st->setDictPath("D:/Workspace/Qt-cpp/parallels/cpp-threeads/build-Parallell_lab_cppThreads-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/passwords.txt");
    ///st->startLoad(QMap<QString,QVariant>());

    AbstractWorkload *stdtr = new StdThreadLoad();
    stdtr->setDictPath("D:/Workspace/Qt-cpp/parallels/cpp-threeads/build-Parallell_lab_cppThreads-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/passwords.txt");
    ///stdtr->startLoad(QMap<QString,QVariant>());

    AbstractWorkload *omp = new OpenMPLoad();
    omp->setDictPath("D:/Workspace/Qt-cpp/parallels/cpp-threeads/build-Parallell_lab_cppThreads-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/passwords.txt");
    ///omp->startLoad(QMap<QString,QVariant>());

    AbstractWorkload *pthreads = new PthreadsLoad();
    pthreads->setDictPath("D:/Workspace/Qt-cpp/parallels/cpp-threeads/build-Parallell_lab_cppThreads-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/passwords.txt");
    ///pthreads->startLoad(QMap<QString,  QVariant>());

    AbstractWorkload *avx = new AVXLoad();
    avx->setDictPath("D:/Workspace/Qt-cpp/parallels/cpp-threeads/build-Parallell_lab_cppThreads-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/passwords.txt");
    avx->startLoad(QMap<QString, QVariant>());

    std::cout << "finished" << std::endl;
    //tr1.join();
    //tr2.join();
    return 0;
}
