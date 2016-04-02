#include <iostream>
#include <vector>
using namespace std;
void printline(size_t count);
void display(const vector<int> &v);
void selectionSort(vector<int> &v);
int main()
{
	vector<int> v = { 4,6,3,2,1,9,7 };
	cout << "Input Array: ";
	display(v);
	printline(50);
	selectionSort(v);
	cout << "Output Array: ";
	display(v);
	printline(50);
	return 0;
}

void printline(size_t count)
{
	for (size_t i = 0; i < count; ++i)
		cout << '=';
	cout << endl;
}

void display(const vector<int> &v)
{
	for (auto i : v)
		cout << i << ' ';
	cout << endl;
}

void selectionSort(vector<int> &v)
{
	size_t count = 1;
	// loop through all numbers
	for (auto iterI = v.begin(); iterI != v.end() - 1; ++iterI) {
		// set current element as minimum
		auto iterMin = iterI;
		// check the element to be minimum
		for (auto iterJ = iterI + 1; iterJ != v.end(); ++iterJ)
			if (*iterJ < *iterMin)
				iterMin = iterJ;
		if (iterMin != iterI) {
			cout << "Items swapped: [" << *iterI << ", " << *iterMin << ']' << endl;
			// swap the numbers
			int temp = *iterMin;
			*iterMin = *iterI;
			*iterI = temp;
		}
		cout << "Iteration " << count++ << '#' << endl;
		display(v);
	}
}
