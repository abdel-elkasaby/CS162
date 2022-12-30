#include "final.h"

void linkedList::insertNode(node *& head, int data) {
    
    node * newNode = new node;
    newNode -> data = data;
    
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

int linkedList::lessThanHead(node * head) {
    
    node * temp = head;
    int smaller = 0;

    while (temp -> next != NULL) {
        temp = temp -> next;
        
        if (temp -> data < head -> data) {
            smaller++;
        }
    }

    return smaller;
}

void linkedList::removeAll(node *& head) {

    if (!head)
          return;

    if (head -> next) {
        removeAll(head -> next);
        head -> next = NULL;
    }

    if (head) {
        delete head;
        head = NULL;
    }
}

void linkedList::newList(node * head, node *& dest) {
    
    node * temp = head;

    if (head == NULL) {
        cout << endl << "List empty" << endl;
        return;
    }

    //second node
    temp = temp -> next;
    
    //insert in dest
    insertNode(dest, temp -> data);

    //reset temp
    temp = head;

    //traverse to second to last node
    while (temp -> next -> next != NULL) {
        temp = temp -> next;
    }
  
    //insert in dest
    insertNode(dest, temp -> data);
}

void linkedList::print(node * test) {
    
    //if list is empty
    if (test == NULL) {
        cout << endl << "List empty" << endl;
        return;
    }
    
    //print
    while (test != NULL) {    
        cout << endl << test -> data << "\t";
    
        test = test -> next;
    }

    cout << endl << endl;
}
