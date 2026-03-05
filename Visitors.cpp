#include "Visitors.h"
#include <iostream>
using namespace std;


Visitors::Visitors() : Visitors("Victor", 69, 81) {}

Visitors::Visitors(string name , int age, int ticket) 
	: name(name), age(age), ticket(ticket) {}

Visitors::~Visitors() {
	cout << "Visitors destroyed\n";
}
void Visitors::display() const {
	cout << "Name: " << name
		<< ", Age: " << age
		<< ", Ticket: " << ticket << endl;

}