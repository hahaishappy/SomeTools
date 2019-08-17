#include "Thread.h"

#include <iostream>

using std::cout;
using std::endl;

namespace xx
{

void Thread::start()
{
    pthread_create(&_pthid,nullptr,threadfunc,this);
    _isRunning=true;
}

void * Thread::threadfunc(void * arg)
{
    Thread * pthread=static_cast<Thread *>(arg);
    if(pthread)
        pthread->run();

    return nullptr;
}

void Thread::join()
{
    if(_isRunning)
        pthread_join(_pthid,nullptr);
}

Thread::~Thread()
{
    if(_isRunning)
        pthread_detach(_pthid);
}

}//end of namespace xx

