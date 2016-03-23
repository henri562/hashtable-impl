#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Hash {
private:
	static const int TABLESIZE = 10;

	struct item {
		string name;
		string drink;
		item *next;
	};

	item *hashTable[TABLESIZE];

public:
	Hash();
	int hash(string);
	void addItem(string, string);
	int numberOfItemsInIdx(int);
	void printTable();
};