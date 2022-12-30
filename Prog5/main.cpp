#include "prog5.h"

//Abdel Elkasaby, CS162
//11/29/22

/*
 * This file is the menu for the user and allows them
 * to select what they want to do. The user can add games,
 * and input the name of the game, the number of players,
 * the type of game, and a description. This is then inserted into a linear
 * linked list. The user can choose to display all of the games added. When the user
 * decides to quit, all the memory is released.
 */

int main()
{
    favorite game;
    bool running = true;
    int response = 0;
    gameInfo newInfo;

    while (running)
    {
        //menu options
        cout << endl << "1. Add games" << endl;
        cout << "2. Display games" << endl;
        cout << "3. Quit" << endl;
        cout << endl << "What would you like to do? Enter a number: ";

        cin >> response;
        cin.clear();
        cin.ignore(SIZE, '\n');
      
        //add game
        if (response == 1)
        {
            gameInfo temp = game.addGame(newInfo);
            game.insert(newInfo, temp);
        }
        //display games
        else if (response == 2)
        {
            game.displayGame(newInfo);
        }
        else
        {   
            cout << endl << "Thanks for playing!" << endl << endl;
            running = false;
        }
    }
}
