#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <vector>
#include <thread>


class ThreadPool
{
public:
    ThreadPool();
    //auto getThread(){}

private:
    std::vector<std::thread> pool;
};

#endif // THREADPOOL_H
