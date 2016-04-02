#include <iostream>
#include <vector>
using namespace std;
void printline(size_t count);
void display(const vector<int> &v);
void shellSort(vector<int> &v);
int main()
{
	vector<int> v = { 4,6,3,2,1,9,7 };
	cout << "Input Vector: ";
	display(v);
	printline(50);
	shellSort(v);
	cout << "Output Vector: ";
	display(v);
	printline(50);
	return 0;
}
void printline(size_t count)
{
	for (size_t i = 0; i < count; i++)
		cout << '=';
	cout << endl;
}

void display(const vector<int>& v)
{
	for (auto i : v)
		cout << i << ' ';
	cout << endl;
}

void shellSort(vector<int>& v)
{
	int interval = 1;
	int elements = v.size();
	int i = 0;
	while (interval <= elements / 3)
		interval = interval * 3 + 1;
	while (interval > 0) {
		cout << "Iteration " << i << '#' << endl;
		display(v);
		
		for (int outer = interval; outer < elements; outer++) {
			int valueToInsert = v[outer];
			int inner = outer - interval;
			while (inner >= 0 && v[inner] > valueToInsert) {
				v[inner + interval] = v[inner];
				inner -= interval;
			}
			v[inner + interval] = valueToInsert;
		}
		cout << "After iteration: " << i++ << ": " << endl;
		display(v);
		interval = (interval - 1) / 3;
	}
}
