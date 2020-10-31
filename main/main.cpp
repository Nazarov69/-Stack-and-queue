#include <iostream>
#include "Queue.h"
#include "Stack.h"

int main()
{
	Stack<int> a(3);
	a.PushStack(10);

	std::cout << a << "\nHi\n";
	return 0;
}