#include <iostream>
#include <vector>
using namespace std;
using iter = vector<int>::iterator;
void display(iter begin, iter end);
void printline(int count);
iter partition(int pivot, iter left, iter right);
void quickSort(iter left, iter right);
int main()
{
	vector<int> v = { 6,1,7,2,8,3,9,5 };
	cout << "Input Vector: ";
	display(v.begin(), v.end() - 1);
	printline(80);
	quickSort(v.begin(), v.end() - 1);
	printline(80);
	cout << "Output Vector: ";
	display(v.begin(), v.end() - 1);
	return 0;
}
void display(iter begin, iter end)
{
	for (iter it = begin; it <= end; ++it)
		cout << *it << ' ';
	cout << endl;
}
void printline(int count)
{
	while (count-- > 0)
		cout << '=';
	cout << endl;
}
iter partition(int pivot, iter left, iter right)
{
	// [left, right]
	while (true) {
		while (*left < pivot)
			++left;
		// now *left >= pivot
		while (*right > pivot)
			--right;
		// now *right <= pivot
		// can swap left and right now
		if (right <= left)
			break;
		int temp = *right;
		*right = *left;
		*left = temp;
	} 
	return left;
}
void quickSort(iter left, iter right)
{
	// [left, right]
	if (right - left <= 0)
		return;
	else {
		auto pivot = *right;
		auto partitionPoint = partition(pivot, left, right - 1);
		*right = *partitionPoint;
		*partitionPoint = pivot;
		quickSort(left, partitionPoint - 1);
		quickSort(partitionPoint + 1, right);
		display(left, right);
	}
}