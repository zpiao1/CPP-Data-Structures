#include <iostream>
#include <vector>
using namespace std;
using it = vector<int>::iterator;
void merging(vector<int> &a, it low, it mid, it high);
void sort(vector<int> &a, it low, it high);
int main()
{
	vector<int> a = {  26, 14, 35, 19, 21, 33, 42, 7, 44, 10, 31, 0 };
	cout << "List before sorting" << endl;
	for (auto i : a)
		cout << i << ' ';
	cout << endl;
	cout << "List after sorting" << endl;
	sort(a, a.begin(), a.end());
	for (auto i : a)
		cout << i << ' ';
	cout << endl;
	return 0;
}

void merging(vector<int>& a, it low, it mid, it high)
{
	// l1 is in [low, mid), l2 is in [mid, high)
	vector<int> b;
	auto l1 = low;
	auto l2 = mid;
	while (l1 != mid && l2 != high)
		if (*l1 <= *l2)
			b.push_back(*l1++);
		else
			b.push_back(*l2++);
	// first while ends, either l1 == mid or l2 == high
	while (l1 != mid)
		b.push_back(*l1++);
	while (l2 != high)
		b.push_back(*l2++);
	// assign the sorted elements
	auto itA = low;
	auto itB = b.cbegin();
	while (itA != high && itB != b.cend())
		// assign corresponding values
		*itA++ = *itB++;
}

void sort(vector<int>& a, it low, it high)
{
	// Notice the terminating condition is like this
	// 1 element left is the base case
	// where [low, high) contains 1 element
	// therefore low + 1 == high
	if (low + 1 != high) {
		it mid = low + (high - low) / 2;
		// again, the range of sorting is [low, min)
		sort(a, low, mid);
		sort(a, mid, high);
		merging(a, low, mid, high);
	}
}
