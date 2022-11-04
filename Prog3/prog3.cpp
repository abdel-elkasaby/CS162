//Abdel Elkasaby, CS162
//11-3-2022

//Twitter Post Saver

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int SIZE = 100;
const int MAXPOST = 9;

struct tweet
{
	char author[SIZE] = {'\0'};
	char title[SIZE] = {'\0'};
	char link[SIZE] = {'\0'};
	char text[SIZE] = {'\0'};
	int likes;
	int retweets;
};

void welcomeUser(); //welcome the user
void addPost(tweet post[], int postCount); //allow user to input post information
void displayPost(tweet post[], int postCount); //display the post information of all tweets
void savePost(tweet post[]); //save post information to external file
void loadPost(tweet post[]); //load post information from external file
void displayAuthor(tweet post[]); //display all post that have a given author's name

int main()
{
	tweet post[MAXPOST];
	int postCount;

	welcomeUser();
	addPost(post, postCount);
	displayPost(post, postCount);
}

//welcome the user
void welcomeUser()
{
	cout << endl << "Hello! Welcome to Save-A-Tweet! This program allows you to"
		     << " save the information"
	     << endl << "from any tweet and view it at any time. What would you like to do?"
	     << endl << endl;
}

//allow user to input post information
void addPost(tweet post[], int postCount)
{
	cout << "How many posts would you like to add? (max is 10 posts): ";
	cin >> postCount;

	for (int i = 0; i < postCount; i++)
	{
		cout << "Enter the name of the author: ";
		cin.getline(post[i].author, SIZE, '\n');
		cin.ignore();
		cout << endl;

		cout << "Enter the title of the tweet: ";
		cin.getline(post[i].title, SIZE, '\n');
		cin.ignore();
		cout << endl;

		cout << "Enter the link of the tweet: ";
		cin.getline(post[i].link, SIZE, '\n');
		cin.ignore();
		cout << endl;

		cout << "Enter the text of the tweet: ";
		cin.getline(post[i].text, SIZE, '\n');
		cin.ignore();
		cout << endl;

		cout << "Enter the number of likes: ";
//		cin >> likes;
		cin.ignore();
		cout << endl;

	}
}

//display post information for all tweets
void displayPost(tweet post[], int postCount)
{
	for (int i = 0; i < postCount; i++)
	{
		cout << post[i].author;
	}

}
