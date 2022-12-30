#include "final.h"

int main() {
    linkedList list;
    int output = 0;
    
    node * head = NULL;
    node * dest = NULL;

    list.insertNode(head, 9);
    list.insertNode(head, 2);
    list.insertNode(head, 1);
    list.insertNode(head, 6);
    list.insertNode(head, 8);

    output = list.lessThanHead(head);
    cout << endl << "Number of nodes with values less than head value: " << output << endl << endl;

    list.print(head);
    list.print(dest);
    list.newList(head, dest);
    list.print(dest);

    list.removeAll(head);
    list.removeAll(dest);
}
