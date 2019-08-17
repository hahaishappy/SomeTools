#pragma once

#include "TaskQueue.h"

#include <vector>
#include <memory>
using std::vector;
using std::unique_ptr;

namespace xx
{

class Task;
class Thread;

class Threadpool
{
    friend class WorkerThread;

public:
    Threadpool(size_t threadNum=4,size_t queSize=10);
    ~Threadpool();

    void start();
    void addTask(Task * task);

    void stop();

private:
    Task * getTask();
    void threadfunc();

private:
    size_t _threadNum;
    size_t _queSize;
    vector<unique_ptr<Thread>> _threads;
    TaskQueue _taskque;
    bool _isExit;
};

}//end of namespace std
