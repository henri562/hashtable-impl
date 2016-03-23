#include "hash.h"
using namespace std;

Hash::Hash() {
	for (int i = 0; i < TABLESIZE; i++) {
		hashTable[i] = new item;
		hashTable[i]->planet = "empty";
		hashTable[i]->system = "empty";
		hashTable[i]->next = NULL;
	}
}

void Hash::addItem(string planet, string system) {
	int idx = hash(planet);

	//add data to location if it is empty
	if (hashTable[idx]->planet == "empty") {
		hashTable[idx]->planet = planet;
		hashTable[idx]->system = system;
	}
	//if not, resolve collision via chaining
	else {
		item *ptr = hashTable[idx];
		item *newItem = new item;
		newItem->planet = planet;
		newItem->system = system;
		newItem->next = NULL;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = newItem;
	}	
}

int Hash::numberOfItemsInIdx(int idx) {
	int count = 0;

	if (hashTable[idx]->planet == "empty") {
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
		cout << hashTable[i]->planet << endl;
		cout << hashTable[i]->system << endl;
		cout << "# of items = " << number << endl;
		cout << "-----------------\n";
	}
}

void Hash::printItemsInIdx(int idx) {
	item *ptr = hashTable[idx];

	if (ptr->planet == "empty") {
		cout << "Index = " << idx << " is empty." << endl;
	}
	else {
		cout << "Index = " << idx << " contains the following item(s):\n";
		while (ptr != NULL) {
			cout << "-----------------\n";
			cout << ptr->planet << endl;
			cout << ptr->system << endl;
			cout << "-----------------\n";
			ptr = ptr->next;
		}
	}
}

void Hash::findSystem(string planet){
	int idx = hash(planet);
	bool foundPlanet = false;
	string system;

	item *ptr = hashTable[idx];
	while (ptr != NULL) {
		if (ptr->planet == planet) {
			foundPlanet = true;
			system = ptr->system;
		}
		ptr = ptr->next;
	}
	if (foundPlanet) {
		cout << "System = " << system << endl;
	}
	else {
		cout << planet << " not found in hash table." << endl;
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