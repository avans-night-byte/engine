#pragma once
#include <queue>
#include <functional>

template <typename tArg0>
class Event {


private:
    typedef std::function<void(tArg0)> funcPtr;
    typedef std::deque<funcPtr> funcPtrSeq;

    funcPtrSeq list;

public:
    Event& operator +=(funcPtr function) {
        list.push_back(function);
        return *this;
    };

    void operator()(tArg0 arg){
        for(typename funcPtrSeq::iterator it(list.begin()); it != list.end(); ++it){
            (*it)(arg);
        }
    }
};


