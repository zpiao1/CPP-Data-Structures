#pragma once
#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H
#include <iostream>
#include <array>
class DataItem {
private:
	int data = DEFAULT_DATA;
	int key = EMPTY_KEY;
public:
	static constexpr int EMPTY_KEY = -1;
	static constexpr int DELETED_KEY = -2;
	static constexpr int DEFAULT_DATA = -1;
	DataItem(int Key = EMPTY_KEY, int Data = DEFAULT_DATA) :
		key(Key), data(Data) {}
	void setKey(int Key);
	void setData(int Data);
	int getKey();
	int getData();
	bool operator== (const DataItem &rhs) const;
	bool operator!= (const DataItem &rhs) const;
};

class HashTable {
private:
	static constexpr size_t SIZE = 20;
	std::array<DataItem, SIZE> hashArray;
	int hashCode(int key);
public:
	static DataItem dummyItem;
	static DataItem emptyItem;
	DataItem &search(int key);
	void insert(int key, int data);
	DataItem remove(int key);
	void display();
	HashTable() = default;
};
#endif // !_HASH_TABLE_H
