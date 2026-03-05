#include "Visitors.h"
#include "Animals.h"
#include "Staff.h"

int main() {

    Visitors v1;
    Visitors v2("Victor", 69, 81);

    Animals a1;
    Animals a2("Pathera leo", 12, 150);

    Staff s1;
    Staff s2("Vasya", "cleaner", 69);

    v1.display();
    v2.display();

    a1.display();
    a2.display();

    s1.display();
    s2.display();

    return 0;
}