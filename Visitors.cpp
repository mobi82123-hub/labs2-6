#include "Visitors.h"
#include <iostream>

using namespace std;

int Visitors::visitorCount = 0;

Visitors::Visitors() {
    name = "None";
    age = 0;
    ticket = 0;
    visitorCount++;
}

Visitors::Visitors(string name, int age, int ticket) {
    this->name = name;
    this->age = age;
    this->ticket = ticket;
    visitorCount++;
}

Visitors::Visitors(const Visitors& other) {
    name = other.name;
    age = other.age;
    ticket = other.ticket;
    visitorCount++;
}

Visitors::Visitors(Visitors&& other) {
    name = move(other.name);
    age = other.age;
    ticket = other.ticket;
}

Visitors::~Visitors() {
    visitorCount--;
}

void Visitors::display() const {
    cout << "Name: " << name << ", Age: " << age << ", Ticket: " << ticket << endl;
}

void Visitors::setAge(int age) {
    this->age = age;
}

int Visitors::getCount() {
    return visitorCount;
}

Visitors Visitors::operator+(const Visitors& other) {
    Visitors temp;
    temp.name = this->name + " + " + other.name;
    temp.age = this->age + other.age;
    temp.ticket = this->ticket + other.ticket;
    return temp;
}

ostream& operator<<(ostream& os, const Visitors& v) {
    os << v.name << " " << v.age << " " << v.ticket;
    return os;
}

istream& operator>>(istream& is, Visitors& v) {
    is >> v.name >> v.age >> v.ticket;
    return is;
}