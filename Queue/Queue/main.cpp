#include "Queue.h"
using namespace std;
int main()
{
	Queue q;
	q.insert(3);
	q.insert(5);
	q.insert(9);
	q.insert(1);
	q.insert(12);

	q.insert(15);

	if (q.isFull())
		cout << "Queue is full!" << endl;

	int num = q.removeData();

	cout << "Element removed: " << num << endl;

	q.insert(16);

	q.insert(17);
	q.insert(18);

	cout << "Element at front: " << q.peek() << endl;

	while (!q.isEmpty()) {
		int n = q.removeData();
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}