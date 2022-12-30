#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//Abdel Elkasaby, CS162
//11/29/22

/* This file contains the struct for this program
 */

const int SIZE = 100;

//game info goes here
struct gameInfo
{
    char name[SIZE];
    int players;
    char type[SIZE];
    char desc[SIZE];
};

struct node
{
    gameInfo info;
    node * next = nullptr;
};

class favorite 
{
    public:
        favorite(); //constructor
        ~favorite(); //destructor
        gameInfo addGame(gameInfo test); //add a game
        void insert(gameInfo newInfo, gameInfo temp); //insert game to linear linked list
        void displayGame(gameInfo newInfo); //display games
        void removeAll(node *& head); //releasing memory
    private:
        node * head;
        node * current;
};
