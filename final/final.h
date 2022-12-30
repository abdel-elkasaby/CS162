#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int SIZE = 100;

class node {
    public:
        int data;
        node * next;

        ~node() {
            next = NULL;
        }
};

class linkedList {
    public:
        void insertNode(node *& head, int data); //insert node at end
        int lessThanHead(node * head);  //return number of node data smaller than head data
        void newList(node * head, node *& dest);
        void print(node * head);
        void removeAll(node *& head); //deallocate memory
};
