#include "Visitors.h"
#include <iostream>
#include <utility>

using namespace std;

int Visitors::visitorCount = 0;

Visitors::Visitors() : Visitors("None", 0, 0) {}

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

Visitors::Visitors(Visitors&& other) noexcept {
    name = move(other.name);
    age = other.age;
    ticket = other.ticket;
}

Visitors& Visitors::operator=(const Visitors& other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
        ticket = other.ticket;
    }
    return *this;
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
    return Visitors(this->name + " + " + other.name, this->age + other.age, this->ticket + other.ticket);
}

ostream& operator<<(ostream& os, const Visitors& v) {
    os << v.name << " " << v.age << " " << v.ticket;
    return os;
}

istream& operator>>(istream& is, Visitors& v) {
    is >> v.name >> v.age >> v.ticket;
    return is;
}

VIPVisitor::VIPVisitor(string name, int age, int ticket, string lounge)
    : Visitors(name, age, ticket), loungeAccess(lounge) {
}

void VIPVisitor::display() const {
    Visitors::display();
    cout << "Lounge Access: " << loungeAccess << endl;
}