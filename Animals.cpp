#include "Animals.h"

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

Mammal::Mammal(std::string species, int age, Staff* caretaker, std::string furColor)
    : Animals(species, age, caretaker), furColor(furColor) {
}

void Mammal::display() const {
    Animals::display();
    std::cout << "Fur Color: " << furColor << std::endl;
}