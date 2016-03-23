#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Hash {
private:
	static const int TABLESIZE = 40;

	struct item {
		string planet;
		string system;
		item *next;
	};

	item *hashTable[TABLESIZE];

public:
	Hash();
	int hash(string);
	void addItem(string, string);
	int numberOfItemsInIdx(int);
	void printTable();
	void printItemsInIdx(int);
	void findSystem(string);
};