#ifndef _Steck_
#define _Steck_
#include <iostream>
using namespace std;

template <class ValType>
class Stack {
protected:
    int top;
    int length;
    ValType* pStack;
public:
    Stack(int size = 1);
    Stack(Stack<ValType>& v);
    void PushStack(ValType temp);
    ValType GetStack();
    ~Stack();

    Stack<ValType>& operator=(Stack<ValType>& v);
   
    template <class ValType1>
    friend ostream& operator<< (ostream& ostr, const Stack<ValType1>& A);
    template <class ValType1>
    friend istream& operator >> (istream& istr, Stack<ValType1>& A);

    int GetLength() {
        return length;
    }
};

template <class ValType1>
ostream& operator<< (ostream& ostr, const Stack<ValType1> &p) {
  for (int i = 0; i < p.length; i++) 
    ostr << p.pStack[i] << endl;
  return ostr;
}

template <class ValType1>
istream& operator >> (istream& istr, Stack<ValType1> &p) {
    int count;
    istr >> count;
    for (int i = 0; i < count; i++){
        ValType1 time;
        istr >> time;
        p.PushStack(time);
    }
    return istr;
}


template <class ValType>
Stack<ValType>::Stack(int size = 1) {
    if (size > 0) {
        this->length = size;
        pStack = new ValType[length];
        for (int i = 0; i < length; i++)
            pStack[i] = 0;
        this->top = -1;
    }
    else
        throw logic_error("Input error: invalide value of Stack length in constructor");
}


template <class ValType>
Stack<ValType>::Stack(Stack<ValType>& v){
    length = v.length;
    top = v.top;
    pStack = new ValType[top+1];
    for (int i = 0; i < top+1; i++)
        pStack[i] = v.pStack[i];
}
template <class T>
Stack<T>::~Stack()
{
    length = 0;
    if (pStack != 0)
        delete[] pStack;
    pStack = nullptr;
}

template <class ValType>
Stack<ValType>& Stack<ValType>::operator=(Stack<ValType>& v)
{
    if (this == &v)
        return *this;
    length = v.length;
    top = v.top;
    delete[] pStack;
    pStack = new ValType[top+1];
    for (int i = 0; i < top+1; i++)
        pStack[i] = v.pStack[i];
    return *this;
}

template<class ValType>
inline void Stack<ValType>::PushStack(ValType temp){
    if (top >= length-1)
        throw logic_error("Input error: invalide value of Stack length in PushStack");
    pStack[top + 1] = temp;
    top++;
}

template<class ValType>
inline ValType Stack<ValType>::GetStack(){
    if (top == -1)
        throw logic_error("Input error: invalide value of Stack length in GetStack");
    ValType temp = pStack[top];
    top--;
    return temp;
}


#endif