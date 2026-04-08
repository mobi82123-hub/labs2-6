#include "Visitors.h"

int Visitors::visitorCount = 0;

Visitors::Visitors() : Person("Unknown"), age(0), ticket(0), favoriteAnimal(nullptr) {
    visitorCount++;
}

Visitors::Visitors(std::string name, int age, int ticket, Animals* fav)
    : Person(name), age(age), ticket(ticket) {
    if (fav) {
        this->favoriteAnimal = fav;
    }
    else {
        this->favoriteAnimal = nullptr;
    }
    visitorCount++;
}

Visitors::Visitors(const Visitors& other)
    : Person(other.name), age(other.age), ticket(other.ticket) {
    this->favoriteAnimal = other.favoriteAnimal;
    visitorCount++;
}

Visitors::Visitors(Visitors&& other) noexcept
    : Person(std::move(other.name)), age(other.age), ticket(other.ticket), favoriteAnimal(other.favoriteAnimal) {
    other.favoriteAnimal = nullptr;
    other.age = 0;
    other.ticket = 0;
}

Visitors& Visitors::operator=(const Visitors& other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
        ticket = other.ticket;
        favoriteAnimal = other.favoriteAnimal;
    }
    return *this;
}

Visitors::~Visitors() {
    visitorCount--;
}

void Visitors::display() const {
    std::cout << "[" << getRole() << "] ";
    Person::display();
    std::cout << "Age: " << age << ", Ticket ID: " << ticket << std::endl;
    if (favoriteAnimal) {
        std::cout << "Favorite Animal species: ";
        favoriteAnimal->display();
    }
}

void Visitors::setAge(int age) {
    this->age = age;
}

int Visitors::getCount() {
    return visitorCount;
}

Visitors Visitors::operator+(const Visitors& other) {
    return Visitors("Group", this->age, this->ticket + other.ticket);
}

std::ostream& operator<<(std::ostream& os, const Visitors& v) {
    os << "Visitor: " << v.name << " (Ticket: " << v.ticket << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Visitors& v) {
    std::cout << "Enter visitor name: ";
    is >> v.name;
    std::cout << "Enter age: ";
    is >> v.age;
    std::cout << "Enter ticket number: ";
    is >> v.ticket;
    return is;
}

VIPVisitor::VIPVisitor(std::string name, int age, int ticket, std::string lounge, Animals* fav)
    : Visitors(name, age, ticket, fav), loungeAccess(lounge) {
}

void VIPVisitor::display() const {
    Visitors::display();
    std::cout << "Lounge Access: " << loungeAccess << std::endl;
}