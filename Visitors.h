#ifndef VISITORS_H
#define VISITORS_H

#include <string>
#include <iostream>

class Visitors {
protected:
    std::string name;
    int age;
    int ticket;
    static int visitorCount;

public:
    Visitors();
    Visitors(std::string name, int age, int ticket = 0);

    Visitors(const Visitors& other);
    Visitors(Visitors&& other) noexcept;

    Visitors& operator=(const Visitors& other);

    virtual ~Visitors();

    virtual void display() const;

    void setAge(int age);
    static int getCount();

    Visitors operator+(const Visitors& other);

    friend std::ostream& operator<<(std::ostream& os, const Visitors& v);
    friend std::istream& operator>>(std::istream& is, Visitors& v);
};

class VIPVisitor : public Visitors {
private:
    std::string loungeAccess;

public:
    VIPVisitor(std::string name, int age, int ticket, std::string lounge);

    void display() const override;
};

#endif