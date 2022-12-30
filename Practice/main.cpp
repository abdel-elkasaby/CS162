#include "practice.h"

int main() {
    linkedList list;
    intel employee;
    
    bool running = true;
    int response = 0;
    int del = 0;

    while (running) {
        
        cout << endl;
        cout << "1. Add employee" << endl;
        cout << "2. Delete employee" << endl;
        cout << "3. Display employees" << endl;
        cout << "4. Quit" << endl;
        cout << endl << "What would you like to do? Enter a number: ";

        cin >> response;
        cin.clear();
        cin.ignore(SIZE, '\n');

        if (response == 1) {
            list.read(employee);
            list.insertNode(employee);
        }

        else if (response == 2) {
            cout << endl;
            cout << "Which employee do you want to delete? Enter a number: ";

            cin >> del;
            cin.clear();
            cin.ignore(SIZE, '\n');
            
            list.deleteNode(del);
        }
        
        else if (response == 3) {
            list.print(employee);
        }

        else {
            cout << endl << "Thanks for playing!" << endl << endl;
            running = false;
        }

    }
    
}
