#include "practice.h"

void linkedList::read(intel & employee) {
    cout << endl;

    cout << "Name: ";
    cin.get(employee.name, SIZE, '\n');
    cin.clear();
    cin.ignore(SIZE, '\n');
    cout << endl;

    cout << "Age: ";
    cin >> employee.age;
    cin.clear();
    cin.ignore(SIZE, '\n');
    cout << endl;

    cout << "SSN: ";
    cin >> employee.ssn;
    cin.clear();
    cin.ignore(SIZE, '\n');
}

void linkedList::insertNode(intel & employee) {
    
    node * newNode = new node;
    newNode -> employee = employee;

    //if list is empty
    if (head == NULL) {
        head = newNode;
        return;
    }

    node * temp = head;
    
    //traverse
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    
    //insert at last position
    temp -> next = newNode; 
}

void linkedList::deleteNode(int pos) {
    
    node * temp1 = head;
    node * temp2 = NULL;
    int len = 0;

    //if list is empty
    if (head == NULL) {
        cout << endl << "List empty" << endl;
        return;
    }

    //traverse to find length of list
    while (temp1 != NULL) {
        temp1 = temp1 -> next;
        len++;
    }

    //if input is greater than length of list
    if (len < pos) {
        cout << endl << "Index out of range" << endl;
        return;
    }

    temp1 = head;

    //if user wants to delete the first
    if (pos == 1) {
        head = head -> next;
        delete temp1;
        return;
    }

    //if user wants to delete other than first
    while (pos-- > 1) {
        temp2 = temp1;
        temp1 = temp1 -> next;
    }

    //temp2 points at what temp1 was pointing at
    temp2 -> next = temp1 -> next;
    delete temp1;
}

void linkedList::print(intel employee) {

    node * temp = head;
    int count = 1;

    //if list is empty
    if (head == NULL) {
        cout << endl << "List empty" << endl;
        return;
    }

    //print
    while (temp != NULL) {
        cout << endl;
        
        cout << "Employee " << count << endl << endl;
        cout << "Name: " << temp -> employee.name << endl;
        cout << "Age: " << temp -> employee.age << endl;
        cout << "SSN: " << temp -> employee.ssn << endl;

        count++;
        temp = temp -> next;
    }
}

void linkedList::removeAll(node *& head) {

    if (!head)
        return;

    if (head -> next)
    {
        removeAll(head -> next);
        head -> next = NULL;
    }

    if (head)
    {
        delete head;
        head = NULL;
    }
}
