#pragma once

#include "MutexLock.h"
#include "Condition.h"
#include "Task.h"

#include <queue>
using std::cout;
using std::endl;
using std::queue;

namespace xx
{

using ElemType=Task*;

class TaskQueue
{
public:
  TaskQueue(size_t queSize=0);

  bool empty();
  bool full();
  void push(ElemType & elem);
  ElemType pop();

  void wakeup();

private:
    size_t _queSize;
    queue<ElemType> _que;
    MutexLock _mutex;
    Condition _notEmpty;
    Condition _notFull;
    bool _flag;
};

}//end of namespace xx

