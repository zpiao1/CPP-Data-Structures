#include "HashTable.h"
DataItem HashTable::dummyItem(DataItem::DELETED_KEY);
DataItem HashTable::emptyItem;
int HashTable::hashCode(int key)
{
	return key % SIZE;
}

DataItem & HashTable::search(int key)
{
	// get the hash
	int hashIndex = hashCode(key);

	// move in array until an empty
	while (hashArray[hashIndex] != emptyItem) {
		if (hashArray[hashIndex].getKey() == key)
			return hashArray[hashIndex];
		// go to next cell
		++hashIndex;
		// wrap around the table
		hashIndex %= SIZE;
	}
	return dummyItem;
}

void HashTable::insert(int key, int data)
{
	DataItem item(key, data);
	// get the hash
	int hashIndex = hashCode(key);

	// move in array until an empty or deleted cell
	while (hashArray[hashIndex] != emptyItem && hashArray[hashIndex] != dummyItem) {
		// go to next cell
		++hashIndex;
		// wrap around the table
		hashIndex %= SIZE;
	}
	hashArray[hashIndex] = item;
}

DataItem HashTable::remove(int key)
{
	// get the hash
	int hashIndex = hashCode(key);
	// move in array until an empty
	while (hashArray[hashIndex] != emptyItem) {
		if (hashArray[hashIndex].getKey() == key) {
			DataItem temp = hashArray[hashIndex];
			// assign a dummy item at deleted position
			hashArray[hashIndex] = dummyItem;
			return temp;
		}
		// go to next cell
		++hashIndex;
		// wrap around the table
		hashIndex %= SIZE;
	}
	return emptyItem;
}

void HashTable::display()
{
	for (auto it = hashArray.begin(); it != hashArray.end(); ++it) {
		if (*it == emptyItem || *it == dummyItem)
			std::cout << " ~~ ";
		else
			std::cout << " (" << it->getKey() << ", " << it->getData() << ") ";
	}
	std::cout << std::endl;
}

void DataItem::setKey(int Key)
{
	key = Key;
}

void DataItem::setData(int Data)
{
	data = Data;
}

int DataItem::getKey()
{
	return key;
}

int DataItem::getData()
{
	return data;
}

bool DataItem::operator==(const DataItem & rhs) const
{
	return (this->data == rhs.data && this->key == rhs.key);
}

bool DataItem::operator!=(const DataItem & rhs) const
{
	return !(*this == rhs);
}
