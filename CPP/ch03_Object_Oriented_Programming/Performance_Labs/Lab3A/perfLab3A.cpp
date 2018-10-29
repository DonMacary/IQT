/********************************************************************************************************************
/   AUTHOR: ELF
/   COURSE: C++ Programming
/   PROGRAM NAME: perfLab3A.cpp
/   PROGRAM DESCRIPTION: Performance lab 3A - Classes
/   INSTRUCTIONS:
     
Inside of **person.h **design a class Person, that has private data members for first name, last name, age and gender.
Implement public functions to get and set the values of these private data members (example: std::string getFname(), void setName(std::string fName), as well as your constructor(s) and destructor.
Inside of main.cpp, you will find the function, **generate_roster() **that you will need to write. This funciton will recieve user input to populate an array of Person objects, 
    with each person being an individual in the class roster. Return the number of students recorded.
You will also find a function called **log_roster(). **Write this function to print each user out to roster.txt.
Compile person.h and roster.cpp into an executable to test your work.
If you are lost, please reach out for help.

       
**********************************************************************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "person.h"
#include <sstream>

//using namespace IQT;

int log_roster(std::vector<Person>& , std::ofstream&);
int generate_roster(std::vector<Person>&);
std::string get_string_input();
int get_int_input();

int main()
{
    //opens a file to output to
    std::ofstream outfile("roster.txt");
    std::vector<Person> roster; //roster object that all new students are stored into

    //generate the roster and store the size
    int roster_size = generate_roster(roster);
    //log the roster into the output file and store the amount of users added
    int logged_count = log_roster(roster, outfile);

    
    if(roster_size == logged_count)
        std::cout<<"Roster logged successfully" << std::endl;
    //return an error if the size of the roster doesnt match the number of students added to the output file
    else
        std::cout<<"Roster size and logged count mismatch. Error!" << std::endl;

    //clear out the roster at the end of output
    roster.clear();
    outfile.close();
    return 0;
    
}
//Arguments: std::vector<person>& roster - reference a vector containing the list of students in the class
//           std::ofstream& - a reference to the ofstream outfile object you will write too 
//Returns:  int count of the number of records written out 
//Purpose: write out the logic
int log_roster(std::vector<Person>& roster, std::ofstream& outfile)
{
    int count = 0; //counts the number of entries put into the roster
    //loops through the roster vector and prints the the full entry to the file
    for(int i = 0; i < roster.size(); i++)
    {
        outfile << roster[i].getFName() << " " << roster[i].getLName() << " " << roster[i].getGender() << " " << roster[i].getAge() << std::endl;
        count++;
    }

    return count;
}

//Arguments: std::vector<Person>& roster - a reference to a vector that will contain the students you input 
//Returns: int count of the number of records input 
//Purpose: receive input and load the vector 
int generate_roster(std::vector<Person>& roster)
{
    int choice = 0; //menu choice
    int count = 0;  //counts how many students added to roster
    //four temp variables to store user input and put into the roster
    std::string firstName;
    std::string lastName;
    std::string gender;
    int age;
    //Person object that will be added to the roster
    Person newPerson(firstName, lastName, gender, age);

    //Menu choice that gives an option to exit after each user is added
    while(choice != 2)
    {
        std::cout << "Would you like to add a person to the roster? 1 for yes 2 for no";
        choice = get_int_input();

        switch(choice)
        {
            //if the user wants to add students get the data from them and store into our temp varaibles
        case 1:
            {
                int goodInput =0;
                std::cout << "Enter the first Name of the person you would like to add: ";
                firstName = get_string_input();

                std::cout << "Enter the last Name of the person you would like to add: ";
                lastName = get_string_input();

                std::cout << "Enter the gender of the person you would like to add: ";
                gender = get_string_input();

                std::cout << "Enter the age of the person you would like to add";
                age = get_int_input();

                //take temp variables and store into our new person object
                newPerson.setFName(firstName);
                newPerson.setLName(lastName);
                newPerson.setGender(gender);
                newPerson.setAge(age);
                
                //push new person into our roster object (which was passed by reference)
                roster.push_back(newPerson);
                count++;
                break;
            }
        //if they dont want to add more users
        case 2:
            std::cout << "No more users will be added!" << std::endl;
            break;

        //error checking
        default:
            std::cout << "Invalid Choice!" << std::endl;
            break;
        }
       
    }
    //returns thhe number of users added to the roster
    return count;

}

//Function to get string input from the user and checks to make sure all characters are letters
std::string get_string_input()
{
    std::string input;
    bool goodString;
    //continue looping until all characters are alphanumeric.. if they arent then get input again
    while(true)
    {
        //gets the string from the input line
        std::getline(std::cin, input);
        //loops through every character
        for(int i =0; i<input.length(); i++)
        {
            //checks if the character is alphanumeric - if not print an error 
            if(isalpha(input[i]) == false)
            {
                std::cout << "input contains invalid chatacters!" << std::endl;
                goodString = false;
                break;
            }
            else 
            {
                goodString = true;
            }
        }
        if(goodString == true)
        {
            break;
        }
    }
    return input;
}

//function to get user integer input and error checking to make sure it is a valid integer. 
int get_int_input()
{
    int number = 0;
    std::string input = "";
    while (true)
    {
        std::cout << ": ";
        std::getline(std::cin, input);
        std::stringstream myStream(input);
        if (myStream >> number)
            break;
        std::cout << "Invalid number, please try again" << std::endl;
    }
    return number;
}