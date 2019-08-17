#pragma once

namespace xx
{

class Noncopyable
{
protected:
    Noncopyable(){}
    ~Noncopyable(){}

    Noncopyable(const Noncopyable&) = delete;
    Noncopyable & operator=(const Noncopyable &) = delete;
};

}
