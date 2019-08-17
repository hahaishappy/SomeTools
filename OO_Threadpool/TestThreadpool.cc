#include "Threadpool.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using std::cout;
using std::endl;

using namespace std;

class Mytask
:public xx::Task
{
public:
    void process()
    {
        ::srand(::time(nullptr));
        int number=::rand() % 100;
        cout<<">>>sub Thread"<<pthread_self()
            <<"Mytask:number="<<number<<endl;
        ::sleep(1);
    }

    ~Mytask(){cout<<"~myTask()"<<endl;}


};

int main()
{
    unique_ptr<xx::Task> task(new Mytask());
    xx::Threadpool threadpool;
    threadpool.start();

    int cnt=20;
    while(cnt--)
    {
        threadpool.addTask(task.get());
        cout<<"man thread"<<pthread_self()
            <<"cnt = "<<cnt<<endl;
    }

    threadpool.stop();

    return 0;
}
