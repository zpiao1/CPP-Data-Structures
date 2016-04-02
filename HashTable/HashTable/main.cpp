#include "HashTable.h"
using namespace std;
int main()
{
	HashTable hash_table;
	hash_table.insert(1, 20);
	hash_table.insert(2, 70);
	hash_table.insert(42, 80);
	hash_table.insert(4, 25);
	hash_table.insert(12, 44);
	hash_table.insert(14, 32);
	hash_table.insert(17, 11);
	hash_table.insert(13, 78);
	hash_table.insert(37, 97);
	
	hash_table.display();

	DataItem item = hash_table.search(37);

	if (item != HashTable::emptyItem && item != HashTable::dummyItem)
		cout << "Element found: " << item.getData() << endl;
	else
		cout << "Element not found" << endl;

	hash_table.remove(37);
	item = hash_table.search(37);

	if (item != HashTable::emptyItem && item != HashTable::dummyItem)
		cout << "Element found: " << item.getData() << endl;
	else
		cout << "Element not found" << endl;

	hash_table.display();
	return 0;
}