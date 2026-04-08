#ifndef ANIMALS_H
#define ANIMALS_H
#include <string>
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
};

class Mammal final : public Animals {
private:
    std::string furColor;
public:
    Mammal(std::string species, int age, Staff* caretaker, std::string furColor);
    void display() const override;

    std::string getSound() const override { return "Mammal sound"; }
};

#endif