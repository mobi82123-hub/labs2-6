#include <iostream>
#include <utility>
#include <vector>
#include "Visitors.h"
#include "Animals.h"
#include "Staff.h"

using namespace std;

int main() {
    cout << "--- 1. Static Method Binding Demo ---" << endl;
    Staff realStaff("Ivan", "Guard", 35);
    Staff* staffPtr = &realStaff;
    staffPtr->info();

    cout << "\n--- 2. Base Class Pointer Polimorphism ---" << endl; // через вказівник
    Manager boss("Alice", "Director", 45, 10);
    Person* p1 = &boss;
    p1->display();
    cout << "Role: " << p1->getRole() << endl;

    cout << "\n--- 3. Base Class Reference Polimorphism ---" << endl; // через посилання
    Mammal lion("Lion", 5, &realStaff, "Golden");
    Animals& animalRef = lion;
    animalRef.display();

    cout << "\n--- 4. Interface (IPrintable) Demo ---" << endl;
    IPrintable* widgets[2];
    widgets[0] = &boss;
    widgets[1] = &lion;

    for (int i = 0; i < 2; i++) {
        widgets[i]->printStatus();
    }

    cout << "\n--- 5. Pure Virtual Functions Result ---" << endl;
    VIPVisitor vip1("Oleg", 25, 999, "Business Lounge", &lion);
    cout << "Visitor Role: " << vip1.getRole() << endl;
    cout << "Animal Sound: " << lion.getSound() << endl;

    cout << "\n--- 6. Copy & Move Logic ---" << endl;
    Visitors v1("Victor", 69, 81, &lion);
    Visitors v2 = v1;
    Visitors v3 = move(v2);

    cout << "Active Visitors: " << Visitors::getCount() << endl;

    cout << "\n--- 7. Virtual Destructor Demo ---" << endl;
    Person* polyPerson = new Staff("Temp", "Worker", 20);
    delete polyPerson;

    cout << "\n--- End of Program ---" << endl;
    return 0;
}