#include "Stack.h"
using namespace std;
int main()
{
	Stack s;
	s.push(3);
	s.push(5);
	s.push(9);
	s.push(1);
	s.push(12);
	s.push(15);

	cout << "Element at top of the stack: " << s.peek() << endl;
	cout << "Elements: " << endl;
	
	while (!s.isEmpty()) {
		int data = s.pop();
		cout << data << endl;
	}

	cout << "Stack full: " << (s.isFull() ? "true" : "false") << endl;
	cout << "Stack empty: " << (s.isEmpty() ? "true" : "false") << endl;

	return 0;
}