#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int SIZE = 100;

class intel {
    public:
        char name[SIZE];
        int age;
        int ssn;
};

class node {
    public:
        intel employee;
        node * next;
        
        node() {
            next = NULL;
        }

        ~node() {
            next = NULL;
        }
};

class linkedList {
    public:
       
        linkedList() {
            head = NULL;
        }

        ~linkedList() {
            removeAll(head);
        }

        void read(intel & employee); //get input from user
        void insertNode(intel & employee); //insert node at end
        void deleteNode(int pos); //delete node
        void print(intel employee); //print
        void removeAll(node *& head); //deallocate memory
    private:
        node * head;
};
