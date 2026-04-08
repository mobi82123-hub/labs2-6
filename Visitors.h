#ifndef VISITORS_H
#define VISITORS_H
#include <string>
#include <iostream>
#include "Staff.h"   
#include "Animals.h" 

class Visitors : public Person {
protected:
    int age;
    int ticket;
    Animals* favoriteAnimal;
    static int visitorCount;

public:
    Visitors();
    Visitors(std::string name, int age, int ticket = 0, Animals* fav = nullptr);

    Visitors(const Visitors& other);
    Visitors(Visitors&& other) noexcept;
    Visitors& operator=(const Visitors& other);

    virtual ~Visitors();
    void display() const override;

    std::string getRole() const override { return "Visitor"; }

    void setAge(int age);
    static int getCount();

    Visitors operator+(const Visitors& other);
    friend std::ostream& operator<<(std::ostream& os, const Visitors& v);
    friend std::istream& operator>>(std::istream& is, Visitors& v);
};

class VIPVisitor final : public Visitors {
private:
    std::string loungeAccess;
public:
    VIPVisitor(std::string name, int age, int ticket, std::string lounge, Animals* fav = nullptr);
    void display() const override final;
    std::string getRole() const override { return "VIP Visitor"; }
};

#endif