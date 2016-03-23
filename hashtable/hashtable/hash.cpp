#include "hash.h"
using namespace std;

int Hash::hash(string key) {
	int hash = 0;
	int idx = key.length();

	for (int i = 0; i < key.length(); i++) {
		hash += (int)key[i];
		cout << "hash = " << hash << endl;
	}

	/*cout << "key[0] = " << (int)key[0] << endl;
	cout << "key[1] = " << (int)key[1] << endl;
	cout << "key[2] = " << (int)key[2] << endl;
	cout << "key[3] = " << (int)key[3] << endl;
	cout << "key[4] = " << (int)key[4] << endl;*/

	return idx;
}