#include <iostream>
#include <vector>
using namespace std;
void printline(int count);
void display(const vector<int> &vi);
void insertionSort(vector<int> &vi);
int main()
{
	vector<int> vi = { 4,6,3,2,1,9,7 };
	cout << "Input Array: ";
	display(vi);
	printline(50);
	insertionSort(vi);
	cout << "Output Array: ";
	display(vi);
	printline(50);
	return 0;
}

void printline(int count)
{
	while (count-- >= 0)
		cout << '=';
	cout << endl;
}

void display(const vector<int>& vi)
{
	cout << '[';
	for (auto i : vi)
		cout << i << ' ';
	cout << ']' << endl;
}

void insertionSort(vector<int>& vi)
{
	// loop through all numbers
	for (auto it = vi.begin() + 1; it != vi.end(); ++it) {
		// select a value to be inserted
		int valueToInsert = *it;
		// select the hold position where number is to be inserted
		auto holePosition = it;
		// check if previous no. is larger than value to be inserted
		while (holePosition != vi.begin() && *(holePosition - 1) > valueToInsert) {
			*holePosition = *(holePosition - 1);
			--holePosition;
			cout << " item moved: " << *holePosition << endl;
		}
		if (holePosition != it) {
			cout << " item inserted: " << valueToInsert << endl;
			// insert the number at hole position
			*holePosition = valueToInsert;
		}
		display(vi);
	}
	
}


