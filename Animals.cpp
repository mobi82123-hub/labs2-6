#include "Animals.h"
#include <iostream>
#include <utility>

using namespace std;

Animals::Animals() : Animals("Pathera leo", 12, 150) {}

Animals::Animals(string species, int age, int weight)
    : species(species), age(age), weight(weight) {
}

Animals::Animals(const Animals& other)
    : species(other.species), age(other.age), weight(other.weight) {
}

Animals& Animals::operator=(const Animals& other) {
    if (this != &other) {
        species = other.species;
        age = other.age;
        weight = other.weight;
    }
    return *this;
}

Animals::~Animals() {
    cout << "Animals destroyed\n";
}

void Animals::display() const {
    cout << "Species: " << species
        << ", Age: " << age
        << ", Weight: " << weight << endl;
}

Mammal::Mammal(string species, int age, int weight, string furColor)
    : Animals(species, age, weight), furColor(furColor) {
}

void Mammal::display() const {
    Animals::display();
    cout << "Fur Color: " << furColor << endl;
}