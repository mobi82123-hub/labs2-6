#ifndef VISITORS_H
#define VISITORS_H

#include <string>
using namespace std;

class Visitors {
private:
	string name;
	int age;
	int ticket;

public:
	Visitors();
	Visitors(string name, int age, int ticket);

	~Visitors();

	
	void display() const;

};

#endif