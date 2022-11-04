//Abdel Elkasaby
//Day Planner

//This program helps users plan their day by asking them a series of questions.
//It asks them how many hours can be spent working on projects today, 
//How many projects they will work on, and how many hours on each project.
//If a total hour greater than 8 or less than zero is entered it will
//ask the user to re enter. The information is echoed back to the user.
//If the user spends less than 50% of the total hours, they will be prompted
//to re enter their information with increased hours. If they use more than
//their total hours they will be notified that there is an overload and asked
//to re enter their information with lower hours. Then it will ask if they want to
//repeat the program until they choose to quit.

#include <iostream>

using namespace std;

int main()
{
	string name = ""; //will hold name of the user
	int totalHours = 0; //total number of hours that can be spent working on projects
	int projectCount = 0; //number of projects the user will work on today
	bool isValid = false; //used in while loop to check for correct inputs
	int counter = 1; //to cycle through the number of projects
	int projectHours; //hours spent on a project
	int totalProjectHours = 0; //sum of the hours spent on each project
	string tryAgain = ""; //to prompt the user if they want to repeat the program
	bool repeat = true; //used to check if user wants to repeat the program

	//welcome the user and ask for their name
	cout << endl << "Hello, Welcome to the Day Planner!" 
	     << " You can use this to track how many hours a day you spend"
	     << endl << "working on projects in order to manage your time." 
	     << " You will be asked to enter how many hours"
	     << endl <<	"you can work today, how many projects you will work on,"
	     << " and how many hours you will spend on each project."
	     << endl << "Then it will tell you if you are spending too much time" 
		     << " or not enough" << endl;
	cout << endl << "Enter your name to continue: ";
	cin >> name;
	
	do {
		
		//prompt the user and get the total hours they can work today
		cout << endl << name << ", how many hours can you spend working on projects today?"
	             << " (Cannot exceed 8 hours): ";
		cin >> totalHours;
		
		//repeat until a valid input is recieved
		while (isValid == false) 
		{
			//check if input is less than/equal to 8 and more than 0
			if (totalHours > 8 || totalHours <= 0) 
			{
				cout << "Number of hours must be less than 8 and more than 0."
				     << " Try again: ";
				cin >> totalHours;
			}
			else 
			{
				isValid = true;
			}
		}
		
		//prompt the user and get the amount of projects they will work on today
		cout << endl << name << ", how many projects will you work on today? ";
		cin >> projectCount;
		
		//to get how many hours the user will spend on each project, then add it to the total
		while (counter <= projectCount) 
		{
			cout << endl << "How many hours will you spend on Project " << counter << ": ";
			cin >> projectHours;
			totalProjectHours += projectHours; 
			counter++;
		}

		//print out final values
		cout << endl << "Available hours: " <<  totalHours;
		cout << endl << "Project count: " <<  projectCount;
		cout << endl << "Hours used: " << totalProjectHours;
		cout << endl << endl;

		//if the time used for projects is more than the time available today
		if (totalProjectHours > totalHours) 
		{
			//prompt the user if they want to try again
			cout << name << ", you don't have enough time for that today."
			<< endl << "Do you want to try again? Y or N: ";
			cin >> tryAgain;
			
			//to quit the program
			if (tryAgain == "n" || tryAgain == "N")
			{
				repeat = false;
			}
		}
		//if the time for projects is less than half of the time available today
		if (totalProjectHours <= totalHours/2)
		{
			//prompt the user if they want to try again
			cout << name << ", you have a lot of extra time today."
			<< endl << "Do you want to try again? Y or N: ";
			cin >> tryAgain;
			
			//to quit the program
			if (tryAgain == "n" || tryAgain == "N")
			{
				repeat = false;
			}
		}
		//if the time for projects more than half and less than the total time available
		else
		{
			//prompt the user if they want to try again
			cout << name << ", congrats you used your time well."
			<< endl << "Do you want to try again? Y or N: ";
			cin >> tryAgain;
			
			//to quit the program
			if (tryAgain == "n" || tryAgain == "N")
			{
				repeat = false;
			}
		}

		//reset variable values
		totalHours = 0;
		projectCount = 0;
		totalProjectHours = 0;
		counter = 1;

	} while (repeat == true); //repeat until user wants to quit
	
	//thank the user for playing
	cout << endl;
	cout << "Thanks for playing, " << name;
	cout << endl << endl;

	return 0;
}

