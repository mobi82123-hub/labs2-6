#include <iostream>
#include <utility>
#include "Visitors.h"
#include "Animals.h"
#include "Staff.h"

using namespace std;

int main() {
    Visitors v1;
    Visitors v2("Victor", 69, 81);
    VIPVisitor vip1("Oleg", 25, 999, "Business Lounge");

    cout << "--- Visitors ---" << endl;
    v1.display();
    v2.display();
    vip1.display();

    Visitors v3 = v2;
    Visitors v4 = move(v3);
    Visitors v5 = v1 + v2;

    cout << "\nTotal: " << Visitors::getCount() << endl;

    Animals a1;
    Animals a2("Panthera leo", 12, 150);
    Mammal m1("Lion", 5, 190, "Golden");

    cout << "\n--- Animals ---" << endl;
    a1.display();
    a2.display();
    m1.display();

    Staff st1;
    Staff st2("Vasya", "cleaner", 69);
    Manager man1("Alice", "Project Manager", 30, 15);

    cout << "\n--- Staff ---" << endl;
    st1.display();
    st2.display();
    man1.display();

    return 0;
}