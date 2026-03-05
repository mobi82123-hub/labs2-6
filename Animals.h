#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
using namespace std;

class Animals {
private:
	string species;
	int weight;
	int age;

public:
	Animals();
	Animals(string species, int age, int weight);

	~Animals();

	
	void display() const;

};

#endif
