#ifndef VISITORS_H
#define VISITORS_H

#include <string>
#include <iostream>

class Visitors {
private:
    std::string name;
    int age;
    int ticket;

    static int visitorCount;

public:
    Visitors();
    Visitors(std::string name, int age, int ticket = 0);

    Visitors(const Visitors& other);
    Visitors(Visitors&& other);

    ~Visitors();

    void display() const;

    void setAge(int age);

    static int getCount();

    Visitors operator+(const Visitors& other);

    friend std::ostream& operator<<(std::ostream& os, const Visitors& v);
    friend std::istream& operator>>(std::istream& is, Visitors& v);
};

#endif