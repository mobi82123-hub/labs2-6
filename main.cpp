#include <iostream>
#include <utility>
#include <vector>
#include <limits>
#include <cstdlib>
#include <fstream>

#include "Visitors.h"
#include "Animals.h"
#include "Staff.h"

using namespace std;


// ОГОЛОШЕННЯ ФУНКЦІЙ ВИДАЛЕННЯ
// (вони десь в інших файлах реалізовані)

void deleteAnimalById(int id);
void deleteStaffById(int id);
void deleteVisitorById(int id);


// ЗМІННА ДЛЯ ТЕКУЩОГО КОРИСТУВАЧА
// сюди зберігаємо хто зайшов як user

string currentUser = "";



// ПЕРЕВІРКА ЧИ Є ТАКИЙ ВІЗІТОР У ФАЙЛІ
// якщо є - user може зайти
// якщо нема - доступ заборонений

bool visitorExists(const string& name) {
    ifstream file("visitors.txt");

    if (!file.is_open()) return false;

    string vName;
    int age, id;

    // читаємо файл построчно
    while (file >> vName >> age >> id) {
        if (vName == name) {
            return true; // знайшли людину
        }
    }

    return false; // не знайшли
}



// ЛОГІН АДМІНА
// просто перевірка пароля

bool adminLogin() {
    string pass;
    cout << "Enter admin password: ";
    cin >> pass;
    return pass == "1234";
}



// ЛОГІН ЮЗЕРА
// тут перевіряємо чи є він у системі

bool userLogin() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string name;
    cout << "Enter your nickname: ";
    getline(cin, name);

    // якщо такого visitor нема — не пускаємо
    if (!visitorExists(name)) {
        cout << "❌ Visitor not found. Ask admin to register you.\n";
        return false;
    }

    // якщо є — зберігаємо як активного користувача
    currentUser = name;

    cout << "✅ Welcome, " << name << "!\n";
    return true;
}



// МЕНЮ АДМІНА
// тут адмін керує зоопарком

void adminMenu() {
    if (!adminLogin()) {
        cout << "Wrong password\n";
        return;
    }

    int choice;

    do {
        cout << "\n=== ADMIN MENU ===\n";
        cout << "1. Add Animal\n";
        cout << "2. Show Animals\n";
        cout << "3. Add Staff\n";
        cout << "4. Show Staff\n";
        cout << "5. Show Visitors\n";
        cout << "6. Add Visitor\n";
        cout << "7. Delete Menu\n";
        cout << "0. Back\n";
        cout << "Choose: ";

        cin >> choice;

        // перевірка на неправильний ввід
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input\n";
            continue;
        }

        switch (choice) {

            
            // ДОДАВАННЯ ТВАРИНИ
           
        case 1: {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string name, color;
            int age;

            cout << "Enter animal name: ";
            getline(cin, name);

            cout << "Enter age: ";
            cin >> age;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter color: ";
            getline(cin, color);

            Animals* a = new Mammal(name, age, nullptr, color);
            saveAnimalToFile(a);
            logAction("Admin added animal");

            delete a;

            cout << "Animal added!\n";
            break;
        }

        case 2:
            showAllAnimals();
            break;

            
            // ДОДАВАННЯ ПРАЦІВНИКА
            
        case 3: {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string name, position;
            int age;

            cout << "Enter name: ";
            getline(cin, name);

            cout << "Enter position: ";
            getline(cin, position);

            cout << "Enter age: ";
            cin >> age;

            Staff s(name, position, age);
            saveStaffToFile(s);
            logAction("Admin added staff");

            cout << "Staff added!\n";
            break;
        }

        case 4:
            showAllStaff();
            break;

        case 5:
            showAllVisitors();
            break;

            
            // ДОДАВАННЯ ВІЗІТОРА (ЮЗЕРА)
            
        case 6: {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string name;
            int age;

            cout << "Enter visitor nickname: ";
            getline(cin, name);

            cout << "Enter age: ";
            cin >> age;

            Visitors v(name, age, rand() % 1000 + 1, nullptr);

            saveVisitorToFile(v);
            logAction("Admin added visitor: " + name);

            cout << "Visitor added!\n";
            break;
        }

              
              // ВИДАЛЕННЯ
              
        case 7: {
            int delChoice;

            cout << "\n=== DELETE MENU ===\n";
            cout << "1. Delete Animal\n";
            cout << "2. Delete Staff\n";
            cout << "3. Delete Visitor\n";
            cout << "0. Back\n";
            cout << "Choose: ";

            cin >> delChoice;

            switch (delChoice) {

            case 1: {
                int id;
                cout << "Enter Animal ID: ";
                cin >> id;
                deleteAnimalById(id);
                cout << "Done.\n";
                break;
            }

            case 2: {
                int id;
                cout << "Enter Staff ID: ";
                cin >> id;
                deleteStaffById(id);
                cout << "Done.\n";
                break;
            }

            case 3: {
                int id;
                cout << "Enter Visitor ID: ";
                cin >> id;
                deleteVisitorById(id);
                cout << "Done.\n";
                break;
            }
            }
            break;
        }

        case 0:
            cout << "Returning...\n";
            break;

        }

    } while (choice != 0);
}



// МЕНЮ ЮЗЕРА
// звичайний відвідувач зоопарку

void userMenu() {
    int choice;

    do {
        cout << "\n=== USER MENU ===\n";
        cout << "1. View Animals\n";
        cout << "2. Visit Zoo\n";
        cout << "3. Show Visitors\n";
        cout << "0. Back\n";
        cout << "Choose: ";

        cin >> choice;

        switch (choice) {

        case 1:
            showAllAnimals();
            break;

            
            // ВІЗИТ У ЗООПАРК
            
        case 2: {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int age;
            cout << "Enter your age: ";
            cin >> age;

            Visitors v(currentUser, age, rand() % 1000 + 1, nullptr);

            saveVisitorToFile(v);
            logAction("Visitor entered: " + currentUser);

            cout << "🎉 Welcome to zoo, " << currentUser << "!\n";
            break;
        }

        case 3:
            showAllVisitors();
            break;

        case 0:
            cout << "Back...\n";
            break;
        }

    } while (choice != 0);
}



// MAIN MENU
// тут вибір адмін чи юзер

int main() {
    int choice;

    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "0. Exit\n";
        cout << "Choose: ";

        cin >> choice;

        switch (choice) {

        case 1:
            adminMenu();
            break;

        case 2:
            if (userLogin())
                userMenu();
            break;

        case 0:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}