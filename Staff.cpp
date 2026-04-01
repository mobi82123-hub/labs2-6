#include "Staff.h"
#include <iostream>
#include <utility>

using namespace std;

Staff::Staff() : Staff("Vasya", "cleaner", 69) {}

Staff::Staff(string name, string position, int age)
    : name(name), position(position), age(age) {
}

Staff::Staff(const Staff& other)
    : name(other.name), position(other.position), age(other.age) {
}

Staff& Staff::operator=(const Staff& other) {
    if (this != &other) {
        name = other.name;
        position = other.position;
        age = other.age;
    }
    return *this;
}

Staff::~Staff() {
    cout << "Staff destroyed" << endl;
}

void Staff::display() const {
    cout << "Name: " << name
        << ", Position: " << position
        << ", Age: " << age << endl;
}

Manager::Manager(string name, string position, int age, int teamSize)
    : Staff(name, position, age), teamSize(teamSize) {
}

void Manager::display() const {
    Staff::display();
    cout << "Team Size: " << teamSize << endl;
}