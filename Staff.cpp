#include "Staff.h"
#include <iostream>
using namespace std;


Staff::Staff() : Staff("Vasya", "cleaner", 69) {}

Staff::Staff(string name, string position, int age)
	: name(name), position(position), age(age) {
}

Staff::~Staff() {
	cout << "Staff destroyed\n";
}
void Staff::display() const {
	cout << "Name: " << name
		<< ", Position: " << position
		<< ", Age: " << age << endl;

}