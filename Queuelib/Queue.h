#ifndef _MY_VECTOR_
#define _MY_VECTOR_
#include <iostream>
using namespace std;


template <class ValType>
class Queue{
protected:
  int length;
  ValType* pQueue;
  int first;
  int last;
  int count;
public:
    Queue(int size = 1);
    Queue(Queue<ValType>& v);
    ~Queue();

    Queue<ValType>& operator=(Queue<ValType>& v);

    void PushQueue(ValType temp);
    ValType GetQueue();
   
    template <class ValType1>
    friend ostream& operator<< (ostream& ostr, const Queue<ValType1>& p);
    template <class ValType1>
    friend istream& operator>> (istream& istr, Queue<ValType1>& p);

    int Length() {
        return length;
    }
};

template <class T1>
ostream& operator<< (ostream& ostr, const Queue<T1> &p) {
    for (int i = p.first; i < p.last; i++)
        ostr << p.pQueue[i] << endl;
    return ostr;
}

template <class ValType1>
istream& operator >> (istream& istr, Queue<ValType1> &p) {
    int count;
    istr >> count;
    for (int i = 0; i < count; i++){
        ValType1 temp;
        istr >> temp;
        p.PushQueue(temp);
    }
    return istr;
}



template <class ValType>
Queue<ValType>::Queue(int size = 1) {
    if (size > 0) {
        this->length = size;
        pQueue = new ValType[length];
        for (int i = 0; i < length; i++)
            pQueue[i] = 0;
        this->first = 0;
        this->last = 0;
        this->count = 0;
    }
    else
        throw logic_error("Input error: invalide value of Queue length in constructor");
}

template <class ValType>
Queue<ValType>::Queue(Queue<ValType>& v){
    length = v.length;
    first = v.first;
    last = v.last;
    count = v.count;
    pQueue = new ValType[length];
    for (int i = 0; i < length; i++)
        pQueue[i] = v.pQueue[i];
}
template <class T>
Queue<T>::~Queue()
{
  length = 0;
  if (pQueue != 0)
    delete [] pQueue;
  pQueue = nullptr;
}

template <class ValType>
Queue<ValType>& Queue<ValType>::operator=(Queue<ValType>& v)
{
    if (this == &v)
        return *this;
    length = v.length;
    delete[] pQueue;
    pQueue = new ValType[length];
    for (int i = 0; i < length; i++)
        pQueue[i] = v.pQueue[i];
    first = v.first;
    last = v.last;
    count = v.count;
    return *this;
}
template<class ValType>
inline void Queue<ValType>::PushQueue(ValType temp){
    if (count >= length)
        throw logic_error("Input error: invalide value of Queue length in PushQueue");

    pQueue[last] = temp;
    last = (last + 1) % length;
}

template<class ValType>
inline ValType Queue<ValType>::GetQueue(){
    if (count == 0)
        throw logic_error("Input error: invalide value of Queue length in GetQueue");

    ValType temp = pQueue[first];
    first = (first + 1) % length;
    return temp;
}





#endif