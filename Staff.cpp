#include "Staff.h"
#include <fstream>
#include <vector>
#include <cstdio>

Staff::Staff() : Person(), position("None"), age(0) {}

Staff::Staff(std::string name, std::string position, int age)
    : Person(name), position(position), age(age) {
}

Staff::Staff(const Staff& other)
    : Person(other.name), position(other.position), age(other.age) {
}

Staff::Staff(Staff&& other) noexcept
    : Person(std::move(other.name)), position(std::move(other.position)), age(other.age) {
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
    os << "Staff: " << s.name << " " << s.position << " " << s.age;
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

//  MANAGER 

Manager::Manager(std::string name, std::string position, int age, int teamSize)
    : Staff(name, position, age), teamSize(teamSize) {
}

void Manager::display() const {
    Staff::display();
    std::cout << "Team Size: " << teamSize << std::endl;
}

//  FILE LOGIC 

void saveStaffToFile(const Staff& s) {
    std::ofstream file("staff.txt", std::ios::app);
    if (!file) return;

    file << s.getName() << " "
        << s.getPosition() << " "
        << s.getAge() << std::endl;
}

std::vector<std::string> loadStaffFromFile() {
    std::vector<std::string> staffList;
    std::ifstream file("staff.txt");

    std::string line;
    while (std::getline(file, line)) {
        staffList.push_back(line);
    }

    return staffList;
}

//  ВИВІД З ID
void showAllStaff() {
    auto staffList = loadStaffFromFile();

    if (staffList.empty()) {
        std::cout << "No staff found" << std::endl;
        return;
    }

    int id = 1;
    for (const auto& s : staffList) {
        std::cout << id++ << ". " << s << std::endl;
    }
}

//  ВИДАЛЕННЯ
void deleteStaffById(int id) {
    std::ifstream file("staff.txt");
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

    remove("staff.txt");
    rename("temp.txt", "staff.txt");

    if (found)
        std::cout << "Staff deleted successfully!\n";
    else
        std::cout << "ID not found\n";
}