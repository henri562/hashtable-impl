#include "hash.h"
using namespace std;

Hash::Hash() {
	for (int i = 0; i < TABLESIZE; i++) {
		hashTable[i] = new item;
		hashTable[i]->name = "empty";
		hashTable[i]->drink = "empty";
		hashTable[i]->next = NULL;
	}
}

void Hash::addItem(string name, string drink) {
	int idx = hash(name);

	//add data to location if it is empty
	if (hashTable[idx]->name == "empty") {
		hashTable[idx]->name = name;
		hashTable[idx]->drink = drink;
	}
	//if not, resolve collision via chaining
	else {
		item *ptr = hashTable[idx];
		item *newItem = new item;
		newItem->name = name;
		newItem->drink = name;
		newItem->next = NULL;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = newItem;
	}	
}

int Hash::numberOfItemsInIdx(int idx) {
	int count = 0;

	if (hashTable[idx]->name == "empty") {
		return count;
	}
	count++;
	item *ptr = hashTable[idx];
	while (ptr->next != NULL) {
		count++;
		ptr = ptr->next;
		}
	return count;
}

void Hash::printTable() {
	int number;
	for (int i = 0; i < TABLESIZE; i++) {
		number = numberOfItemsInIdx(i);
		cout << "-----------------\n";
		cout << "Index = " << i << endl;
		cout << hashTable[i]->name << endl;
		cout << hashTable[i]->drink << endl;
		cout << "# of items = " << number << endl;
		cout << "-----------------\n";
	}
}

int Hash::hash(string key) {
	int hash = 0;
	int idx;

	for (int i = 0; i < key.length(); i++) {
		hash += (int)key[i];
	}

	idx = hash % TABLESIZE;

	return idx;
}