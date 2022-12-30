#include "prog4.h"

//Abdel Elkasaby, CS162
//11/13/22

/* This file contains the functions used for this program.
 * This includes the constructor, destructor, addPost(),
 * displayPost(), and getLike().
 */

tweet::tweet() //constructor, initialize data members
{
    //prompt user for array size
    cout << endl << "Enter the number of posts you want to add: ";
    cin >> arraySize;
    cin.clear();
    cin.ignore(SIZE, '\n');
    
    info = new postInfo[arraySize];
    postCount = 0;
}

tweet::~tweet() //destructor, deallocate memory
{
    if (NULL != info)
    {
        delete [] info;
    }

    info = 0;
    arraySize = 0;
    postCount = 0;
}

//allow user to input all post information
void tweet::addPost(int i)
{
    cout << endl;
    
    for (i = 0; i < arraySize; i++)
    {
        cout << endl << "Post " << i + 1 << ":" << endl << endl;
        
        //get input
        cout << "Author: ";
        cin.get(info[i].author, SIZE, '\n');
        cin.clear();
        cin.ignore(SIZE, '\n');
        cout << endl;

        cout << "Title: ";
        cin.get(info[i].title, SIZE, '\n');
        cin.clear();
        cin.ignore(SIZE, '\n');
        cout << endl;

        cout << "Link: ";
        cin.get(info[i].link, SIZE, '\n');
        cin.clear();
        cin.ignore(SIZE, '\n');
        cout << endl;

        cout << "Text: ";
        cin.get(info[i].text, SIZE, '\n');
        cin.clear();
        cin.ignore(SIZE, '\n');
        cout << endl;

        cout << "Number of likes: ";
        cin >> info[i].likes;
        cin.clear();
        cin.ignore(SIZE, '\n');
        cout << endl;

        cout << "Number of retweets: ";
        cin >> info[i].retweets;
        cin.clear();
        cin.ignore(SIZE, '\n');
        cout << endl;
    }
}

//display all post information
void tweet::displayPost(int i)
{
    cout << endl;    

    for (i = 0; i < arraySize; i++)
    {    
        //print post to console 
        cout << endl << "Post " << i + 1 << ":" << endl;
        
        cout << "Author: " << info[i].author << endl;
        cout << "Title: " << info[i].title << endl;
        cout << "Link: " << info[i].link << endl;
        cout << "Text: " << info[i].text << endl;
        cout << "Number of likes: " << info[i].likes << endl;
        cout << "Number of retweets: " << info[i].retweets << endl << endl;
    }
}

//get the indexes at which the number of likes matches the user input
int tweet::getLike(int likeInput, tweet post)
{
    int likeMatch = -1; //point at which number of likes matches user input
    
    for (int i = 0; i < arraySize; i++) //loop through posts
    {
        if (likeInput == info[i].likes) //if user input is equal to post likes
        {
              //display post info
              cout << endl << "Post " << i + 1 << ":" << endl;

              cout << "Author: " << info[i].author << endl;
              cout << "Title: " << info[i].title << endl;
              cout << "Link: " << info[i].link << endl;
              cout << "Text: " << info[i].text << endl;
              cout << "Number of likes: " << info[i].likes << endl;
              cout << "Number of retweets: " << info[i].retweets << endl << endl;
        }
    }
    return likeMatch;
}
