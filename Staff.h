#ifndef STAFF_H
#define STAFF_H
#include <string>
#include <iostream>

class IPrintable {  // Інтерфейс
public:
    virtual void printStatus() const = 0;
    virtual ~IPrintable() {}
};

class Person : public IPrintable {
protected:
    std::string name;
public:
    Person() : name("Unknown") {}
    Person(std::string name) : name(name) {}
    virtual ~Person() {}
    virtual void display() const { std::cout << "Name: " << name << std::endl; }
    virtual std::string getRole() const = 0;
    void printStatus() const override { std::cout << "Object status: Active" << std::endl; }
};

class Staff : public Person {
protected:
    std::string position;
    int age;
public:
    Staff();
    Staff(std::string name, std::string position, int age);
    Staff(const Staff& other);
    Staff(Staff&& other) noexcept;
    Staff& operator=(const Staff& other);
    virtual ~Staff();
    void display() const override;
    std::string getRole() const override { return "Staff Member"; }
    void info() const { std::cout << "Static Binding: Staff Info" << std::endl; }

    friend std::ostream& operator<<(std::ostream& os, const Staff& s);
    friend std::istream& operator>>(std::istream& is, Staff& s);
};

class Manager final : public Staff {
private:
    int teamSize;
public:
    Manager(std::string name, std::string position, int age, int teamSize);
    void display() const override final;
    std::string getRole() const override { return "Manager"; }
};
#endif