#pragma once

namespace xx
{

class Task
{
public:
    virtual
    void process()=0;

    virtual ~Task(){}
};

}//end of namespace

