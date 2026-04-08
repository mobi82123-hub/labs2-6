#include "Staff.h"

Staff::Staff() : Person(), position("None"), age(0) {}

Staff::Staff(std::string name, std::string position, int age)
    : Person(name), position(position), age(age) {
}

Staff::Staff(const Staff& other) : Person(other.name), position(other.position), age(other.age) {}

Staff::Staff(Staff&& other) noexcept : Person(std::move(other.name)), position(std::move(other.position)), age(other.age) {
    other.age = 0;
}

Staff& Staff::operator=(const Staff& other) {
    if (this != &other) {
        name = other.name;
        position = other.position;
        age = other.age;
    }
    return *this;
}

Staff::~Staff() {}

void Staff::display() const {
    std::cout << "[" << getRole() << "] ";
    Person::display();
    std::cout << "Position: " << position << ", Age: " << age << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Staff& s) {
    os << "Staff: " << s.name << " (" << s.position << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Staff& s) {
    std::cout << "Enter name: ";
    is >> s.name;
    std::cout << "Enter position: ";
    is >> s.position;
    std::cout << "Enter age: ";
    is >> s.age;
    return is;
}

Manager::Manager(std::string name, std::string position, int age, int teamSize)
    : Staff(name, position, age), teamSize(teamSize) {
}

void Manager::display() const {
    Staff::display();
    std::cout << "Team Size: " << teamSize << std::endl;
}