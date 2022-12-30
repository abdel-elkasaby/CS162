#include "prog4.h"

//Abdel Elkasaby, CS162
//11/13/22

/* This program allows users to input post information from a tweet.
 * This includes the name of the author, and the title of the post, 
 * the text of the post, the link of the post, the number of lakes,
 * and the number of retweets.The program then allows the user to display 
 * all of the posts that were entered in. It also allows the user to
 * display all of the posts that have a certain number of likes.
 * The user is able to quit the program at any time.
 */

//main serves as the menu
int main()
{
    tweet post;
    bool running = true;
    int response = 0; //which option they select in the menu
    int adding = 0; //how many posts the user is adding
    int likeInput = 0; //the number of likes they want to search for
    int i = 0;

    while (running) //will loop until user wants to quit
    {
        //menu options
        cout << endl << "1. Add posts" << endl;
        cout << "2. Display posts" << endl;
        cout << "3. Display posts with likes" << endl;
        cout << "4. Quit" << endl;
        cout << endl << "What would you like to do? Enter a number: ";
        
        cin >> response;
        cin.clear();
        cin.ignore(SIZE, '\n');
        
        //add post
        if (response == 1)
        {
            post.addPost(i);
        }
        //display post
        else if (response == 2)
        {   
            post.displayPost(i);
        }
        //display posts with certain number of likes
        else if (response == 3)
        {
            cout << endl << "Enter the number of likes: ";
            cin >> likeInput;
            cin.clear();
            cin.ignore(SIZE, '\n');

            int likeMatch = post.getLike(likeInput, post);   
            
            if (likeMatch == -1) //if no matches are found
            {
                cout << endl << "No matches found" << endl;
            }
        }
        //quit
        else
        {
            cout << endl << "Thanks for playing!" << endl << endl;
            running = false;
        }
    }
}
