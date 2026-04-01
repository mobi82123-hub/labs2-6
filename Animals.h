#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
#include <iostream>

using namespace std;

class Animals {
protected:
    string species;
    int weight;
    int age;

public:
    Animals();
    Animals(string species, int age, int weight);

    Animals(const Animals& other);
    Animals& operator=(const Animals& other);

    virtual ~Animals();

    virtual void display() const;
};

class Mammal : public Animals {
private:
    string furColor;

public:
    Mammal(string species, int age, int weight, string furColor);

    void display() const override;
};

#endif
