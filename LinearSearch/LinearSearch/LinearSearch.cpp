#include <iostream>
#include <vector>
#include <cstddef>
#define MAX 20
using namespace std;
void printline(int count);
int find(int data, const vector<int> &vec);
void display(const vector<int> &vec);
int main()
{
	vector<int> intVector{ 1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66 };
	cout << "Input Vector: ";
	display(intVector);
	printline(50);

	// find location of 55
	int location = find(55, intVector);

	// if element was found
	if (location != -1)
		cout << endl << "Element found at location: " << (location + 1);
	else
		cout << "Element not found.";

	return 0;
}

void printline(int count)
{
	while (count-- >= 0)
		cout << '=';
	cout << endl;
}

int find(int data, const vector<int>& vec)
{
	int comparisons = 0;
	int index = -1;
	int i;
	
	// navigate through all items
	for (i = 0; i < MAX; i++) {
		// count the comparisons made
		comparisons++;
		// if data found, break the loop
		if (data == vec[i]) {
			index = i;
			break;
		}
	}
	cout << "Total comparisons made: " << comparisons;
	return index;
}

void display(const vector<int>& vec)
{
	cout << '[';
	for (auto i : vec)
		cout << i << ' ';
	cout << ']' << endl;
}
