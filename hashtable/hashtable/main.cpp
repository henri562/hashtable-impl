#include "hash.h"
using namespace std;

int main(int argc, char *argv[]) {
	Hash hashObj;
	string planet = "";

	hashObj.addItem("Ageko", "Antaeus");
	hashObj.addItem("Benda", "Grissom");
	hashObj.addItem("Camaron", "Century");
	hashObj.addItem("Derneuca", "Amazon");
	hashObj.addItem("Earth", "Sol");
	hashObj.addItem("Faringor", "Cacus");
	hashObj.addItem("Gremar", "Dis");
	hashObj.addItem("Hunsalra", "Tereshkova");
	hashObj.addItem("Intai'sei", "Phoenix");
	hashObj.addItem("Juntauma", "Farinata");
	hashObj.addItem("Klendagon", "Century");
	hashObj.addItem("Loki", "Asgard");
	hashObj.addItem("Maganlis", "Fortuna");
	hashObj.addItem("Nausicaa", "Athens");
	hashObj.addItem("Nepmos", "Erebus");
	hashObj.addItem("Ontarom", "Newton");

	while (planet != "exit") {
		cout << "Search for ";
		cin >> planet;
		if (planet != "exit")
			hashObj.findSystem(planet);
	}

	return 0;
}