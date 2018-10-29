/********************************************************
 * Using what you know from C/C++ so far, create a quick program that accomplishes the following:

    Feel free to reuse your vector practice code
    Create a UI to accomplish all functionality
    Allow a user to input a series of numbers, which are stored into a deque
    Create functions to add and subtract all numbers within the deque... from lowest index to highest
    Ensure value type is signed (for negative numbers)
    Allow a user to delete the first or last element
    Allow a user to clear the entire deque
    BONUS
        Allow a user to insert a new element at the front or back of the deque
        Allow a user to insert, at a specific element, an additonal number
        Allow a user to delete a specific element
        etc
********************************************************/
#include <iostream>
#include <string>
#include <deque>
#include <sstream>

int main(void)
{
    std::string input = ""; //a string that takes in user input and will be converted to an integer
	signed int myNumber = 0;    //any number that is put in to the deque
	int dequeInitSize = 0; //the initial size the user decides the deque to be
	int currentSize = 0;    //the current size of the deque to make sure we put the correct amount in initially
    std::deque<signed int> myDeque;  //a deque that contains signed integers
    //any while true loops from here are are just to take in user input and then error check it to make sure they type an integer in
	
    while (true)
	{
		std::cout << "Please how many ints to place in the deque: ";
		std::getline(std::cin, input);
		// This code converts from string to number safely.
		std::stringstream myStream(input);
		if (myStream >> dequeInitSize)
			break;
		std::cout << "Invalid number, please try again" << std::endl;
	}
    //this loop puts whatever the user inputs into a deque - it error checks all of the user input to make sure it is a signed int
	while (currentSize < dequeInitSize)
	{
		while (true)
		{
			std::cout << "Please enter a valid number: ";
			std::getline(std::cin, input);

			// This code converts from string to number safely.
			std::stringstream myStream(input);
			if (myStream >> myNumber)
				break;
			std::cout << "Invalid number, please try again" << std::endl;
		}
        //this is the line the puts the number in the deque at the end
		myDeque.push_back(myNumber);
        //print out the deque to show the user the current composition
		for (int i = 0; i< myDeque.size(); i++)
		{
			std::cout << myDeque[i] << " ";
		}
		std::cout << std::endl;
		currentSize++; //iterate the current size so the loop will end when we finish inserting into the deque
	}
    // print the menu options
	std::cout << "OPTIONS: " << std::endl;
	std::cout << "\t 1.) Add all numbers" << std::endl;
	std::cout << "\t 2.) Subtract all numbers" << std::endl;
	std::cout << "\t 3.) Delete first or last element" << std::endl;
	std::cout << "\t 4.) Clear entire deque" << std::endl;
	std::cout << "\t 5.) Insert a new element to end or beginning of deque" << std::endl;
	std::cout << "\t 6.) Insert a new element in a specific location in the deque" << std::endl;
	std::cout << "\t 7.) Delete a specific element in the deque" << std::endl;
	std::cout << "\t 8.) Exit Program" << std::endl;

	int choice = 0; // a value to store the users choice
	while (choice != 8)
	{
		while (true)
		{
			std::cout << "Please enter your choice (1-8): ";
			std::getline(std::cin, input);
			std::stringstream myStream(input);
			if (myStream >> choice)
				break;
			std::cout << "Invalid number, please try again" << std::endl;
		}
		signed int math = 0;    // variable to store the SUM and DIFFERENCE results
		int insertPos = 0;  //value to hold the position a user would want to insert a number to
		int deletePos = 0;  // value to hold the position a user would want to delete a number at
		std::deque<int>::iterator it = myDeque.begin();   //an iterator deque for insertion
        //thhis switch checks the choice the user puts and pairs it with the menu options above
		switch (choice)
		{
        //if a user selects 1 the want to output the sum of all the numbers in the deque
		case 1:
			for (int i = 0; i< myDeque.size(); i++)
			{
				math = math + myDeque[i];
			}
			std::cout << "SUM of deque: " << math << std::endl;
			break;
        //if the user selects 2 they want to output the difference of all the numbers in the deque
		case 2:
			math = myDeque[0];
			for (int i = 1; i< myDeque.size(); i++)
			{
				math = math - myDeque[i];
			}
			std::cout << "Difference of deque: " << math << std::endl;
			break;
        //if the user selects 3 they want to remove the last element
		case 3:
			while (true)
			{
				std::cout << "Would you like to delete the first or last element? (1 for first 2 for last) ";
				std::getline(std::cin, input);

				// This code converts from string to number safely.
				std::stringstream myStream(input);
				if (myStream >> deletePos)
					break;
				std::cout << "Invalid number, please try again" << std::endl;
			}
			if(deletePos == 1)
			{
				myDeque.pop_front();
			}
			else if(deletePos == 2)
			{
				myDeque.pop_back();
			}
			else
			{
				std::cout << "No user deleted, returning to Main Menu" << std::endl;
			}
			break;
        //if the user selects 4 they want to delete the deque
		case 4:
			myDeque.clear();
			break;
        //if the user selects 5 they want to input a number to the end of the deque
		case 5:
			while (true)
			{
				std::cout << "Please enter a valid number: ";
				std::getline(std::cin, input);

				// This code converts from string to number safely.
				std::stringstream myStream(input);
				if (myStream >> myNumber)
					break;
				std::cout << "Invalid number, please try again" << std::endl;
			}
			while(true)
			{
				std::cout << "Please enter 1 to input this number at the front and 2 to put in in the back: ";
				std::getline(std::cin, input);

				// This code converts from string to number safely.
				std::stringstream myStream(input);
				if (myStream >> insertPos)
					break;
				std::cout << "Invalid number, please try again" << std::endl;
			}
			if(insertPos == 1)
			{
				myDeque.push_front(myNumber);
			}
			else if(insertPos == 2)
			{
				myDeque.push_back(myNumber);
			}
			else
			{
				std::cout << "No user inserted, returning to Main Menu" << std::endl;
			}
			break;
        //menu option 6 allows the user to input a nubmer wherever they wannt, it will first ask which number they want to insert and then where
		case 6:
            //asks the user what to insert
			while (true)
			{
				std::cout << "Please enter a valid number you would like to insert: ";
				std::getline(std::cin, input);

				// This code converts from string to number safely.
				std::stringstream myStream(input);
				if (myStream >> myNumber)
					break;
				std::cout << "Invalid number, please try again" << std::endl;
			}
			//asks the user where to insert
			while (true)
			{
				std::cout << "Please enter where you would like to insert this number: ";
				std::getline(std::cin, input);

				// This code converts from string to number safely.
				std::stringstream myStream(input);
				if (myStream >> insertPos)
					break;
				std::cout << "Invalid number, please try again" << std::endl;
			}
			//inserts the number into the position the user specifies
			it = myDeque.insert(it + insertPos, myNumber);
			break;
        //menu option 7 allows the user to delete a specific position in the deque
		case 7:	
			while (true)
			{
				std::cout << "Enter the position of the number in the Deque you want to delete: ";
				std::getline(std::cin, input);

				// This code converts from string to number safely.
				std::stringstream myStream(input);
				if (myStream >> deletePos)
					break;
				std::cout << "Invalid number, please try again" << std::endl;
			}
			myDeque.erase(myDeque.begin() + deletePos);
			break;
        // option 8 prints the final deque and then says have a nice day and ends the program since the while loop is while choice!=8
		case 8:
			std::cout << "Final deque: ";
			for (int i = 0; i< myDeque.size(); i++)
			{
				std::cout << myDeque[i] << " ";
			}
			std::cout << std::endl;
			std::cout << "Have a nice day!" << std::endl;
			break;
        // if the user put any number other than 1-8
		default:
			std::cout << "Not a valid choice, try again!" << std::endl;
			break;
		}
        //print the deque at the end of each function to show the current status
		for (int i = 0; i< myDeque.size(); i++)
		{
			std::cout << myDeque[i] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}