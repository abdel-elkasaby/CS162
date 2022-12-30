#include "prog5.h"

//Abdel Elkasaby, CS162
//11/29/22

/* This file contains the functions used in the class "favorite"
 *
 */

favorite::favorite() //constructor, initialize data members
{
    head = nullptr;
    current = nullptr;
}

favorite::~favorite() //destructor, deallocate memory
{
    removeAll(head);
    head = nullptr;
    current = nullptr;
}

void favorite::removeAll(node *& head) //releases all dynamic memory
{
    if (!head)
        return;
    
    if (head -> next)
    {
        removeAll(head -> next);
        head -> next = nullptr;
    }
    
    if (head)
    {
        delete head;
        head = nullptr;
    }
}

//allow user to input all game info
gameInfo favorite::addGame(gameInfo test)
{
    cout << endl;

    //get input
    cout << "Game name: ";
    cin.get(test.name, SIZE, '\n');
    cin.clear();
    cin.ignore(SIZE, '\n');
    cout << endl;

    cout << "Number of players: ";
    cin >> test.players;
    cin.clear();
    cin.ignore(SIZE, '\n');
    cout << endl;

    cout << "Type of game (board game, xbox, etc.): ";
    cin.get(test.type, SIZE, '\n');
    cin.clear();
    cin.ignore(SIZE, '\n');
    cout << endl;
   
    cout << "Description: ";
    cin.get(test.desc, SIZE, '\n');
    cin.clear();
    cin.ignore(SIZE, '\n');

    cout << endl;
    
    return test;
}

//insert game info to linear linked list
void favorite::insert(gameInfo newInfo, gameInfo temp)
{     
    if (NULL == head)
    {
        head = new node;
        head -> info = temp;
        head -> next = NULL;
    }
    
    else
    {
        node * current = head;
        while (current -> next != NULL)
        {
            current = current -> next;
        }

        current -> next = new node;
        current = current -> next;
        current -> info = temp;
        current -> next = NULL;
    }
}

//display game info to console
void favorite::displayGame(gameInfo newInfo)
{
    node * current = head;

    while (current != NULL)
    {
        if (!head)
            cout << "Nothing is in the list" << endl << endl;
        else
        {
            cout << endl;
            cout << "Game name: " << current -> info.name << endl;
            cout << "Number of players: " << current -> info.players << endl;
            cout << "Type: " << current -> info.type << endl;
            cout << "Description: " << current -> info.desc << endl;

            current = current -> next;
        }
    }
}
