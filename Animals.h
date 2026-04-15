#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
#include <iostream>
#include <vector>
#include "Staff.h"

class Animals : public IPrintable {
protected:
    std::string species;
    int age;
    Staff* caretaker;

public:
    Animals();
    Animals(std::string species, int age, Staff* caretaker = nullptr);

    Animals(const Animals& other);
    Animals& operator=(const Animals& other);

    Animals(Animals&& other) noexcept;
    Animals& operator=(Animals&& other) noexcept;

    virtual ~Animals();

    virtual void display() const;

    virtual std::string getSound() const = 0;

    void printStatus() const override { std::cout << "Animal status: Healthy" << std::endl; }

    std::string getSpecies() const { return species; }
    int getAge() const { return age; }
};

class Mammal final : public Animals {
private:
    std::string furColor;
public:
    Mammal(std::string species, int age, Staff* caretaker, std::string furColor);
    void display() const override;

    std::string getSound() const override { return "Mammal sound"; }

    std::string getFurColor() const { return furColor; }
};

void saveAnimalToFile(const Animals* animal);
std::vector<std::string> loadAnimalsFromFile();
void showAllAnimals();

// видалення
void deleteAnimalById(int id);

#endif