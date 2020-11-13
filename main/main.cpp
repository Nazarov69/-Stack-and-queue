#include <iostream>
#include "Queue.h"
#include "Stack.h"
const int LengthStack = 10;
const int LengthQueue = 6;
const int LengthStack1 = 10;
const int LengthStack2 = 5;
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	
	
	cout << "¹1" << endl;
	Stack<int> stack(LengthStack);
	for (int i = 0; i < LengthStack; i++) 
		stack.PushStack(rand());
	stack.DeleteEven();
	
	
	cout << endl << endl << endl;
	
	
	cout << "¹2" << endl;
	Stack<int> twostack1(LengthStack1);
	Stack<int> twostack2(LengthStack2);
	for (int i = 0; i < LengthStack1; i++)
		twostack1.PushStack(rand());

	for (int i = 0; i < LengthStack2; i++)
		twostack2.PushStack(rand());

	twostack1.TwoStack(twostack2);


	cout << endl << endl << endl;
	
	
	cout << "¹3" << endl;
	Queue<int> queue(LengthQueue);
	queue.MaxElement(LengthQueue);
	
	return 0;
/* 
¹1
stack = {24464, 26962, 29358, 11478, 15724, 19169, 26500, 6334, 18467, 41}
new array = {19169, 18467, 41}



¹2
stack1 = {5705, 28145, 23281, 16827, 9961, 491, 2995, 11942, 4827, 5436}
stack2 = {32391, 14604, 3902, 153, 292}
new stack1 = {32391, 14604, 3902, 153, 292}
new stack2 = {5705, 28145, 23281, 16827, 9961, 491, 2995, 11942, 4827, 5436}



¹3
queue = {12382, 17421, 18716, 19718, 19895, 5447}
max element in queue: 19895
*/
}