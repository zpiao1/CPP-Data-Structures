#include <iostream>
#include <vector>
using namespace std;
int find(int data, const vector<int> &vec, int *comp);
int main()
{
	vector<int> list = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 };
	for (size_t i = 0; i < list.size() + 3; i++) {
		int location;
		int comp;
		if (i == list.size())
			location = find(1, list, &comp);
		else if (i == list.size() + 1)
			location = find(100, list, &comp);
		else if (i == list.size() + 2)
			location = find(32, list, &comp);
		else
			location = find(list[i], list, &comp);
		if (location != -1)
			cout << "Element found at " << location << " after " << comp << " comparisons." << endl;
		else
			cout << "Element not found after " << comp << " comparisons." << endl;
	}
	return 0;
}
int find(int data, const vector<int> &vec, int *comp)
{
	int lo = 0;
	int hi = vec.size() - 1;
	int index = -1;
	*comp = 0;
	while (vec[lo] <= vec[hi] && data >= vec[lo] && data <= vec[hi]) {
		(*comp)++;
		int mid = lo + (data - vec[lo]) * (hi - lo) / (vec[hi] - vec[lo]);
		if (vec[mid] < data)
			lo = mid + 1;
		else if (vec[mid] > data)
			hi = mid - 1;
		else {
			index = mid;
			break;
		}
	}
	return index;
}