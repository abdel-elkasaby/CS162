#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//Abdel Elkasaby, CS162
//11/13/22

/* This file contains the class for this program
 */

const int SIZE = 100;

//post info goes here
struct postInfo
{
    char author[SIZE];
    char title[SIZE];
    char link[SIZE];
    char text[SIZE];
    int likes;
    int retweets;
};

class tweet
{
    public:
        tweet(); //constructor
        ~tweet(); //destructor
        void addPost(int i); //add a post
        void displayPost(int i); //display all posts
        int getLike(int likeInput, tweet post); //get the points at which the number of likes matches user input
    private:
        postInfo * info; 
        int arraySize;
        int postCount;
};
