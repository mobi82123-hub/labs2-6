#ifndef STAFF_H
#define STAFF_H

#include <string>
using namespace std;

class Staff {
private:
	string name;
	string position;
	int age;

public:
	Staff();
	Staff(string name, string position, int age);

	~Staff();

	// ВИПРАВЛЕНО: було 'conts', має бути 'const'
	void display() const;

};

#endif