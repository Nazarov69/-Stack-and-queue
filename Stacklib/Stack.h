#ifndef _STACK_
#define _STACK_
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
    void DeleteEven();

    void TwoStack(Stack<ValType>& v);
};

// будем считать, что LengthStack это длина одного из стеков, а длина второго стека будет задана пользователем
template<class ValType>
inline void Stack<ValType>::TwoStack(Stack<ValType>& v) {
    int tmp;
    int len;
    if (this->length > v.length)
        len = this->length;
    else len = v.length;
    ValType* tmparray = new ValType [len];
    if (len == this->length)
        for (int i = 0; i < len; i++)
            tmparray[i] = this->pStack[i];
    else
        for (int i = 0; i < len; i++)
            tmparray[i] = v.pStack[i];

    cout << "stack1 = {";
    for (int i = 0; i < this->length; i++) {
        tmp = this->pStack[i];
        cout << tmp;
        if (i < this->length - 1) cout << ", ";
    }
    cout << "} " << endl;
    int tmp1;
    cout << "stack2 = {";
    for (int i = 0; i < v.length; i++) {
        tmp1 = v.pStack[i];
        cout << tmp1;
        if (i < v.length - 1) cout << ", ";
    }
    cout << "} " << endl;
    
  

    if (len == this->length) {
        int temp = this->length;
        this->length = v.length;
        v.length = temp;
        delete[] this->pStack;
        this->pStack = new ValType [this->length];
        cout << "new stack1 = {";
        for (int i = 0; i < this->length; i++) {
            this->pStack[i] = v.pStack[i];
            cout << this->pStack[i];
            if (i < this->length - 1) cout << ", ";
        }
        cout << "} " << endl;
    }
    else {
        int temp = v.length;
        v.length = this->length;
        this->length = temp;
        delete[] v.pStack;
        v.pStack = new ValType [v.length];
        cout << "new stack2 = {";
        for (int i = 0; i < v.length; i++) {
            v.pStack[i] = this->pStack[i];
            cout << v.pStack[i];
            if (i < v.length - 1) cout << ", ";
        }
        cout << "} " << endl;
    }

    if (len == v.length) {
        delete[] v.pStack;
        v.pStack = new ValType[v.length];
        cout << "new stack2 = {";
        for (int i = 0; i < len; i++) {
            v.pStack[i] = tmparray[i];
            cout << v.pStack[i];
            if (i < len - 1) cout << ", ";
        }
        cout << "} " << endl;
    }
    else {
        this->length = len;
        delete[] this->pStack;
        this->pStack = new ValType [this->length];
        cout << "new stack1 = {";
        for (int i = 0; i < len; i++) {
            pStack[i] = tmparray[i];
            cout << pStack[i];
            if (i < len - 1) cout << ", ";
        }
        cout << "} " << endl;
    }
}




template<class ValType>
inline void Stack<ValType>::DeleteEven() {
    ValType tmp;
    int sum = length;;
    cout << "stack = {";
    for (int i = 0; i < length; i++) {
        tmp = GetStack();
        cout << tmp;
        if (tmp % 2 == 0) {
            for (int k = (length - 1 - i); k < length; k++)
                pStack[k] = pStack[k + 1];
            sum--;
        }
        if (i < length - 1) cout << ", ";
    }
    cout << "} " << endl;

    cout << "new array = {";
    for (sum; sum > 0; sum--) {
        cout << pStack[sum-1];
        if (sum != 1)cout << ", ";
    }
    cout << "}" << endl;

}



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
    pStack = new ValType[length];
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
    pStack = new ValType[length];
    for (int i = 0; i < top+1; i++)
        pStack[i] = v.pStack[i];
    return *this;
}



template<class ValType>
inline void Stack<ValType>::PushStack(ValType temp){
    if (top >= length-1)
        throw logic_error("Input error: invalide value of Stack length in PushStack");
    top++;
    pStack[top] = temp;
    
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