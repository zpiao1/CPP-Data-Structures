#include <iostream>
#include <vector>
using namespace std;
void printline(int count)
{
	while (count-- >= 0)
		cout << '=';
	cout << endl;
}

int find(int data, const vector<int> &vec)
{
	int lowerBound = 0;
	int upperBound = vec.size() - 1;
	int midPoint = -1;
	int comparisons = 0;
	int index = -1;

	while (lowerBound <= upperBound) {
		cout << "Comparison " << comparisons + 1 << endl;
		cout << "lowerBound: " << lowerBound << ", vec[" << lowerBound << "] = " << vec[lowerBound] << endl;
		cout << "upperBound: " << upperBound << ", vec[" << upperBound << "] = " << vec[upperBound] << endl;
		comparisons++;
		// midpoint = (lowerBound + upperBound) / 2;
		midPoint = lowerBound + (upperBound - lowerBound) / 2;
		
		// data found
		if (vec[midPoint] == data) {
			index = midPoint;
			break;
		} else {
			// if data is larger
			if (vec[midPoint] < data)
				// data is in upper half
				lowerBound = midPoint + 1;
			// data is smaller
			else
				// data is in lower half
				upperBound = midPoint - 1;
		}
	}
	cout << "Total comparisons made: " << comparisons << endl;
	return index;
}

void display(const vector<int> &vec)
{
	cout << '[';
	// navigate through all items
	for (auto i : vec)
		cout << i << ' ';
	cout << ']' << endl;
}

int main()
{
	vector<int> intVector{ 1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66 };
	display(intVector);
	printline(50);

	// find location of 1
	int location = find(55, intVector);

	// if element was found
	if (location != -1)
		cout << endl << "Element found at location: " << location + 1;
	else
		cout << endl << "Element not found.";

	return 0;
}