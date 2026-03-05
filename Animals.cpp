#include "Animals.h"
#include <iostream>
using namespace std;


Animals::Animals() : Animals("Pathera leo", 12, 150) {}

Animals::Animals(string species , int age , int weight)
	: species(species), age(age), weight(weight) {
}

Animals::~Animals() {
	cout << "Animals destroyed\n";
}
void Animals::display() const {
	cout << "Species: " << species
		<< ", Age: " << age
		<< ", Weight: " << weight << endl;

}