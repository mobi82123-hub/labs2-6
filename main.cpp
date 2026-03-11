#include <iostream>
#include <utility>
#include "Visitors.h"
#include "Animals.h"
#include "Staff.h"

using namespace std;

int main() {
    Visitors v1;
    Visitors v2("Victor", 69, 81);

    Animals a1;
    Animals a2("Panthera leo", 12, 150);

    Staff st1;
    Staff st2("Vasya", "cleaner", 69);

    Visitors v3 = v2;
    Visitors v4 = move(v3);
    Visitors v5 = v1 + v2;

    cout << Visitors::getCount() << endl;

    v1.display();
    v2.display();
    v4.display();
    v5.display();

    a1.display();
    a2.display();

    st1.display();
    st2.display();

    return 0;
}