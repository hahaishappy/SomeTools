#pragma once

#include "Thread.h"

namespace xx
{

class Threadpool;
class WorkerThread
:public Thread
{
public:
    WorkerThread(Threadpool & threadpool);
    ~WorkerThread();

    void run();
private:
    Threadpool & _threadpool;
};

}//end of namespace xx
