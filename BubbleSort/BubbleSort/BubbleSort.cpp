#include <iostream>
#include <vector>
using namespace std;
void display(const vector<int> &vi);
void bubbleSort(vector<int> &vi);

int main()
{
	vector<int> vi = { 1,8,4,6,0,3,5,2,7,9 };
	display(vi);
	cout << endl;

	bubbleSort(vi);
	cout << endl << "Output Array: ";
	display(vi);
	return 0;
}

void display(const vector<int>& vi)
{
	cout << '[';
	for (auto i : vi)
		cout << i << ' ';
	cout << ']' << endl;
}

void bubbleSort(vector<int> &vi)
{
	int temp;
	// loop through all numbers
	for (decltype(vi.size()) i = 0; i != vi.size() - 1; ++i) {
		bool swapped = false;
		// loop through numbers falling ahead
		for (auto it = vi.begin(); it != vi.end() - 1 - i; ++it) {
			cout << "    Items compared: [" << *it << ", " << *(it + 1) << "] ";
			// check if next number is lesser than current no
			// swap the numbers.
			// (Bubble up the highest number)
			if (*it > *(it + 1)) {
				temp = *it;
				*it = *(it + 1);
				*(it + 1) = temp;
				swapped = true;
				cout << " => swapped [" << *it << ", " << *(it + 1) << "]" << endl;
			}
			else
				cout << " => not swapped" << endl;
		}
		// if no number was swapped that means
		// array is sorted now, break the loop.
		if (!swapped)
			break;
		cout << "Iteration " << i + 1 << "#: ";
		display(vi);
	}
}