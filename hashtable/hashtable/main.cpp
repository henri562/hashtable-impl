#include "hash.h"
using namespace std;

int main(int argc, char *argv[]) {
	int idx;
	Hash hashObj;

	idx = hashObj.hash("Henry");

	cout << "Index = " << idx << endl;
}