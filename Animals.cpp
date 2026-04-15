#include "Animals.h"
#include <fstream>
#include <vector>
#include <cstdio>

Animals::Animals() : species("Unknown"), age(0), caretaker(nullptr) {}

Animals::Animals(std::string species, int age, Staff* caretaker)
    : species(species), age(age) {
    if (caretaker) {
        this->caretaker = new Staff(*caretaker);
    }
    else {
        this->caretaker = nullptr;
    }
}

Animals::Animals(const Animals& other) : species(other.species), age(other.age) {
    if (other.caretaker) {
        this->caretaker = new Staff(*other.caretaker);
    }
    else {
        this->caretaker = nullptr;
    }
}

Animals::Animals(Animals&& other) noexcept
    : species(std::move(other.species)), age(other.age), caretaker(other.caretaker) {
    other.caretaker = nullptr;
    other.age = 0;
}

Animals& Animals::operator=(const Animals& other) {
    if (this != &other) {
        delete caretaker;
        species = other.species;
        age = other.age;
        if (other.caretaker) {
            caretaker = new Staff(*other.caretaker);
        }
        else {
            caretaker = nullptr;
        }
    }
    return *this;
}

Animals& Animals::operator=(Animals&& other) noexcept {
    if (this != &other) {
        delete caretaker;
        species = std::move(other.species);
        age = other.age;
        caretaker = other.caretaker;
        other.caretaker = nullptr;
        other.age = 0;
    }
    return *this;
}

Animals::~Animals() {
    delete caretaker;
}

void Animals::display() const {
    std::cout << "--- Animal Card (" << getSound() << ") ---" << std::endl;
    std::cout << "Species: " << species << ", Age: " << age << std::endl;
    if (caretaker) {
        std::cout << "Caretaker info: ";
        caretaker->display();
    }
}

// MAMMAL

Mammal::Mammal(std::string species, int age, Staff* caretaker, std::string furColor)
    : Animals(species, age, caretaker), furColor(furColor) {
}

void Mammal::display() const {
    Animals::display();
    std::cout << "Fur Color: " << furColor << std::endl;
}

//  FILE LOGIC 

void saveAnimalToFile(const Animals* animal) {
    std::ofstream file("animals.txt", std::ios::app);
    if (!file) return;

    file << animal->getSpecies() << " "
        << animal->getAge() << " "
        << animal->getSound();

    const Mammal* m = dynamic_cast<const Mammal*>(animal);
    if (m) {
        file << " " << m->getFurColor();
    }

    file << std::endl;
}

std::vector<std::string> loadAnimalsFromFile() {
    std::vector<std::string> animals;
    std::ifstream file("animals.txt");

    std::string line;
    while (std::getline(file, line)) {
        animals.push_back(line);
    }

    return animals;
}

//  ВИВІД З ID
void showAllAnimals() {
    auto animals = loadAnimalsFromFile();

    if (animals.empty()) {
        std::cout << "No animals found" << std::endl;
        return;
    }

    int id = 1;
    for (const auto& a : animals) {
        std::cout << id++ << ". " << a << std::endl;
    }
}

//  ВИДАЛЕННЯ
void deleteAnimalById(int id) {
    std::ifstream file("animals.txt");
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

    remove("animals.txt");
    rename("temp.txt", "animals.txt");

    if (found)
        std::cout << "Animal deleted successfully!\n";
    else
        std::cout << "ID not found\n";
}