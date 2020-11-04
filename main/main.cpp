#include <iostream>
#include "Queue.h"
#include "Stack.h"
const int LengthStack = 10;
const int LengthQueue = 6;
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "¹1" << endl;
	Stack<int> stack(LengthStack);
	stack.DeleteEven(LengthStack);
	cout << endl << endl << endl;
	cout << "¹2" << endl;
	Stack<int> twostack(LengthStack);
	twostack.TwoStack(LengthStack);
	cout << endl << endl << endl;
	cout << "¹3" << endl;
	Queue<int> queue(LengthQueue);
	queue.MaxElement(LengthQueue);
	
	return 0;
	
}