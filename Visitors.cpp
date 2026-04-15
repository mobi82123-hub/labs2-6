#include "Visitors.h"
#include <fstream>
#include <vector>
#include <cstdio>

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
        std::cout << "Favorite Animal: ";
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
    os << "Visitor: " << v.name << " " << v.age << " " << v.ticket;
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

//  VIP 

VIPVisitor::VIPVisitor(std::string name, int age, int ticket, std::string lounge, Animals* fav)
    : Visitors(name, age, ticket, fav), loungeAccess(lounge) {
}

void VIPVisitor::display() const {
    Visitors::display();
    std::cout << "Lounge Access: " << loungeAccess << std::endl;
}

//  FILE LOGIC

void saveVisitorToFile(const Visitors& v) {
    std::ofstream file("visitors.txt", std::ios::app);
    if (!file) return;

    file << v.getName() << " "
        << v.getAgeValue() << " "
        << v.getTicket() << std::endl;
}

std::vector<std::string> loadVisitorsFromFile() {
    std::vector<std::string> data;
    std::ifstream file("visitors.txt");

    std::string line;
    while (std::getline(file, line)) {
        data.push_back(line);
    }

    return data;
}

//  ВИВІД З ID
void showAllVisitors() {
    auto data = loadVisitorsFromFile();

    if (data.empty()) {
        std::cout << "No visitors found" << std::endl;
        return;
    }

    int id = 1;
    for (const auto& v : data) {
        std::cout << id++ << ". " << v << std::endl;
    }
}

//  ВИДАЛЕННЯ
void deleteVisitorById(int id) {
    std::ifstream file("visitors.txt");
    std::ofstream temp("temp.txt");

    if (!file || !temp) {
        std::cout << "File error\n";
        return;
    }

    std::string line;
    int currentId = 1;
    bool found = false;

    while (std::getline(file, line)) {
        if (currentId != id) {
            temp << line << std::endl;
        }
        else {
            found = true;
        }
        currentId++;
    }

    file.close();
    temp.close();

    remove("visitors.txt");
    rename("temp.txt", "visitors.txt");

    if (found)
        std::cout << "Visitor deleted successfully!\n";
    else
        std::cout << "ID not found\n";
}

//  LOG 

void logAction(const std::string& action) {
    std::ofstream file("history.txt", std::ios::app);
    if (!file) return;

    file << action << std::endl;
}