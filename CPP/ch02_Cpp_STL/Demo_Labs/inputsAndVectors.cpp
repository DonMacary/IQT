/*******************************************************************************************************
Using what you know from C/C++ so far, create a quick program that accomplishes the following:

Create a UI to accomplish all functionality
Allow a user to input a series of numbers, which are stored into a vector
Create functions to add and subtract all numbers within the vector... from lowest index to highest
Ensure value type is signed (for negative numbers)
Allow a user to delete the last element
Allow a user to clear the entire vector
BONUS
Allow a user to insert a new element at the back of vector
Allow a user to insert, at a specific element, an additonal number
Allow a user to delete a specific element
etc
********************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(void)
{
    
	string input = ""; //a string that takes in user input and will be converted to an integer
	signed int myNumber = 0;    //any number that is put in to the vector
	std::vector <signed int> myVector;  //a vector that contains signed integers
	int vectorInitSize = 0; //the initial size the user decides the vector to be
	int currentSize = 0;    //the current size of the vector to make sure we put the correct amount in initially

    //any while true loops from here are are just to take in user input and then error check it to make sure they type an integer in
	while (true)
	{
		cout << "Please how many ints to place in the vector: ";
		std::getline(std::cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> vectorInitSize)
			break;
		cout << "Invalid number, please try again" << endl;
	}
    //this loop puts whatever the user inputs into a vector - it error checks all of the user input to make sure it is a signed int
	while (currentSize < vectorInitSize)
	{
		while (true)
		{
			cout << "Please enter a valid number: ";
			std::getline(std::cin, input);

			// This code converts from string to number safely.
			stringstream myStream(input);
			if (myStream >> myNumber)
				break;
			cout << "Invalid number, please try again" << endl;
		}
        //this is the line the puts the number in the vector
		myVector.push_back(myNumber);
        //print out the vector to show the user the current composition
		for (int i = 0; i< myVector.size(); i++)
		{
			std::cout << myVector[i] << " ";
		}
		std::cout << std::endl;
		currentSize++; //iterate the current size so the loop will end when we finish inserting into the vector
	}
    // print the menu options
	std::cout << "OPTIONS: " << std::endl;
	std::cout << "\t 1.) Add all numbers" << std::endl;
	std::cout << "\t 2.) Subtract all numbers" << std::endl;
	std::cout << "\t 3.) Delete last element" << std::endl;
	std::cout << "\t 4.) Clear entire vector" << std::endl;
	std::cout << "\t 5.) Insert a new element to end of vector" << std::endl;
	std::cout << "\t 6.) Insert a new element in a specific location in the vector" << std::endl;
	std::cout << "\t 7.) Delete a specific element in the vector" << std::endl;
	std::cout << "\t 8.) Exit Program" << std::endl;

	int choice = 0; // a value to store the users choice
	while (choice != 8)
	{
		while (true)
		{
			std::cout << "Please enter your choice (1-8): ";
			std::getline(std::cin, input);
			stringstream myStream(input);
			if (myStream >> choice)
				break;
			cout << "Invalid number, please try again" << endl;
		}
		signed int math = 0;    // variable to store the SUM and DIFFERENCE results
		int insertPos = 0;  //value to hold the position a user would want to insert a number to
		int deletePos = 0;  // value to hold the position a user would want to delete a number at
		std::vector<int>::iterator it = myVector.begin();   //an iterator vector for insertion
        //thhis switch checks the choice the user puts and pairs it with the menu options above
		switch (choice)
		{
        //if a user selects 1 the want to output the sum of all the numbers in the vector
		case 1:
			for (int i = 0; i< myVector.size(); i++)
			{
				math = math + myVector[i];
			}
			std::cout << "SUM of vector: " << math << endl;
			break;
        //if the user selects 2 they want to output the difference of all the numbers in the vector
		case 2:
			math = myVector[0];
			for (int i = 1; i< myVector.size(); i++)
			{
				math = math - myVector[i];
			}
			std::cout << "Difference of vector: " << math << endl;
			break;
        //if the user selects 3 they want to remove the last element
		case 3:
			myVector.pop_back();
			break;
        //if the user selects 4 they want to delete the vector
		case 4:
			myVector.clear();
			break;
        //if the user selects 5 they want to input a number to the end of the vector
		case 5:
			while (true)
			{
				cout << "Please enter a valid number: ";
				std::getline(std::cin, input);

				// This code converts from string to number safely.
				stringstream myStream(input);
				if (myStream >> myNumber)
					break;
				cout << "Invalid number, please try again" << endl;
			}
			myVector.push_back(myNumber);
			break;
        //menu option 6 allows the user to input a nubmer wherever they wannt, it will first ask which number they want to insert and then where
		case 6:
            //asks the user what to insert
			while (true)
			{
				cout << "Please enter a valid number you would like to insert: ";
				std::getline(std::cin, input);

				// This code converts from string to number safely.
				stringstream myStream(input);
				if (myStream >> myNumber)
					break;
				cout << "Invalid number, please try again" << endl;
			}
			//asks the user where to insert
			while (true)
			{
				cout << "Please enter where you would like to insert this number: ";
				std::getline(std::cin, input);

				// This code converts from string to number safely.
				stringstream myStream(input);
				if (myStream >> insertPos)
					break;
				cout << "Invalid number, please try again" << endl;
			}
			//inserts the number into the position the user specifies
			it = myVector.insert(it + insertPos, myNumber);
			break;
        //menu option 7 allows the user to delete a specific position in the vector
		case 7:	
			while (true)
			{
				cout << "Please enter which position you would like to delete: ";
				std::getline(std::cin, input);

				// This code converts from string to number safely.
				stringstream myStream(input);
				if (myStream >> deletePos)
					break;
				cout << "Invalid number, please try again" << endl;
			}
			myVector.erase(myVector.begin() + deletePos);
			break;
        // option 8 prints the final vector and then says have a nice day and ends the program 9since the while loop is while choice!=8
		case 8:
			std::cout << "Final Vector: ";
			for (int i = 0; i< myVector.size(); i++)
			{
				std::cout << myVector[i] << " ";
			}
			std::cout << std::endl;
			std::cout << "Have a nice day!" << std::endl;
			break;
        // if the user put any number other than 1-8
		default:
			std::cout << "Not a valid choice, try again!" << std::endl;
			break;
		}
        //print the vector at the end of each function to show the current status
		for (int i = 0; i< myVector.size(); i++)
		{
			std::cout << myVector[i] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}