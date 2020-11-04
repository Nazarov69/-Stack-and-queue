#ifndef _Stack_
#define _Stack_
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
    void DeleteEven(int LengthStack);

    void TwoStack(int LengthStack);
};

// будем считать, что LengthStack это длина одного из стеков, а длина второго стека будет задана пользователем
template<class ValType>
inline void Stack<ValType>::TwoStack(int LengthStack){
    cout << "введите длину первого стека (не больше : " << LengthStack << ")" << endl;
    int len1;
    cin >> len1;
   cout << "введите длину второго стека (длина стека не должна превышать : " << LengthStack - len1 << ")" << endl;
   int len2;
   cin >> len2;
   ValType* array1 = new ValType[len1];
   for (int i = 0; i < len1; i++) PushStack(rand());
   cout << "stack1 = {";
   for (int i = 0; i < len1; i++) {
       array1[i] = GetStack();
       cout << array1[i];
       if (i < len1 - 1) cout << ", ";
   }
   cout << "} " << endl;

    
    ValType* array2 = new ValType[len2];
    for (int i = 0; i < len2; i++) PushStack(rand());
    cout << "stack2 = {";
    for (int i = 0; i < len2; i++) {
        array2[i] = GetStack();
        cout << array2[i];
        if (i < len2 - 1) cout << ", ";
    }
    cout << "} " << endl;

    int len3;
    if (len1 > len2)
        len3 = len1;
    else len3 = len2;

    ValType* array3 = new ValType[len3];
    // копируем в третий созданный стек тот, у которого длина больше (между первым и вторым)
    
    if (len3 == len1) {
        cout << "new stack2 = {";
        for (int i = 0; i < len3; i++) {
            array3[i] = array1[i];
            cout << array3[i];
            if (i < len3 - 1) cout << ", ";
        }
        cout << "} " << endl;
    }
    else {
        cout << "new stack1 = {";
        for (int i = 0; i < len2; i++) {
            array3[i] = array2[i];
            cout << array3[i];
            if (i < len2 - 1) cout << ", ";
        }
        cout << "} " << endl;
    }
    // копируем в стек наибольшей длины тот стек, у которого длина меньше

    if (len3 == len1) {
        cout << "new stack1 = {";
        for (int i = 0; i < len2; i++) {
            array1[i] = array2[i];
            cout << array1[i];
            if (i < len2 - 1) cout << ", ";
        }
        cout << "} " << endl;
    }
    else {
        cout << "new stack2 = {";
        for (int i = 0; i < len1; i++) {
            array2[i] = array1[i];
            cout << array2[i];
            if (i < len1 - 1) cout << ", ";
        }
        cout << "} " << endl;
    }



    

}




template<class ValType>
inline void Stack<ValType>::DeleteEven(int LengthStack){
    int tmp = 0;
    int sum = 0; // будет отвечать за количество элементов в новом массиве из нечетных чисел
    ValType* array = new ValType[LengthStack];
    for (int i = 0; i < LengthStack; i++)
        array[i] = NULL;
    for (int i = 0; i < LengthStack; i++)
        PushStack(rand());

    cout << "stack = {";
    for (int i = 0; i < LengthStack; i++) {
        tmp = GetStack();
        cout << tmp;
        if (tmp % 2 == 1) {
                array[sum] = tmp;
                sum++;  
        }
            if (i < LengthStack - 1) cout << ", ";
    }
    cout << "} " << endl;

    cout << "new array = {";
    for (int i = 0; i < sum; i++) {
        cout << array[i];
        if (i < sum - 1) cout << ", ";
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