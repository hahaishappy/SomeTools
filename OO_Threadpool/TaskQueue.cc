#include "TaskQueue.h"
#include <iostream>

using std::cout;
using std::endl;

namespace xx
{

TaskQueue::TaskQueue(size_t queSize)
:_queSize(queSize)
,_mutex()
,_notEmpty(_mutex)
,_notFull(_mutex)
,_flag(true)
{}

bool TaskQueue::empty()
{
    return _que.size()==0;
}

bool TaskQueue::full()
{
    return _que.size()==_queSize;
}

void TaskQueue::push(ElemType & elem)
{
    MutexLockGuard autoLock(_mutex);
    while(full())//使用while是为了防止虚假唤醒
    {
        _notFull.wait();
    }

    _que.push(elem);
    _notEmpty.notify();
}

ElemType TaskQueue::pop()
{
    MutexLockGuard autoLock(_mutex);
    while(_flag && empty())
    {
        _notEmpty.wait();
    }

    if(_flag)
    {
        ElemType elem=_que.front();
        _que.pop();

        _notFull.notify();
        return elem;
    }
    else
        return nullptr;
}

void TaskQueue::wakeup()
{
    _flag=false;
    _notEmpty.notifyAll();
}

}//end of namespace xx
