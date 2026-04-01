#ifndef STAFF_H
#define STAFF_H

#include <string>
#include <iostream>

using namespace std;

class Staff {
protected:
    string name;
    string position;
    int age;

public:
    Staff();
    Staff(string name, string position, int age);

    Staff(const Staff& other);
    Staff& operator=(const Staff& other);

    virtual ~Staff();

    virtual void display() const;
};

class Manager : public Staff {
private:
    int teamSize;

public:
    Manager(string name, string position, int age, int teamSize);

    void display() const override;
};

#endif