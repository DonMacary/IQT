/*******************************************************
 * 
    Using what you know from C/C++ so far, create a quick and simple print program that accomplishes the following:
        Allows user to add characters to the list
        Allows user to pop off a character
        Print each of the characters on a new line
    Do the same with a fordward_list
    Attempt to use operator[] or at(), note the results.
*********************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <forward_list>

#define doubley
//#define singley

void print_menu();
int get_int_input();
char get_char_input();
void print_list(std::forward_list<char> characters);
void print_list(std::list<char> characters);

#ifdef doubley

int main (void)
{
    std::list<char> characterList = { 'a', 'b', 'c', 'd'};
    print_list(characterList);
    
    int choice = 0;
    char inputLetter;
    int inputNumber =0;
    while(choice != 4)
    {
        print_menu();
        print_list(characterList);
        choice = get_int_input();
        switch(choice)
        {
            //menu option one allows the user to add characters to the list
            case 1:
                std::cout << "Enter 1 to add the character to the front and 2 to add it to the back: "<< std::endl;
                inputNumber = get_int_input();
                inputLetter = get_char_input();
                if(inputNumber == 1)
                {
                    characterList.push_front(inputLetter);
                }
                else if(inputNumber == 2)
                {
                    characterList.push_back(inputLetter);
                }
                else
                {
                    std::cout << "Invalid choice, returning to Main Menu" << std::endl;
                }
                break;
            //menu option 2 allows users to pop characers from the list
            case 2:
                std::cout << "Enter 1 to remove the character from the front and 2 to remove it from the back: "<< std::endl;
                inputNumber = get_int_input();
                if(inputNumber == 1)
                {
                    characterList.pop_front();
                }
                else if(inputNumber == 2)
                {
                    characterList.pop_back();
                }
                else
                {
                    std::cout << "Invalid choice, returning to Main Menu" << std::endl;
                }
                break;
            //menu option 3 allows users to print each character on a new line
            case 3:
                std::cout << "The current list: " << std::endl;
                for (const auto& elem : characterList)
                {
                    std::cout << elem << " " << std::endl;
                }
                break;
            //menu option 4 prints the final linked list and exits
            case 4:
                std::cout << "Final Linked List: " << std::endl;
                for (const auto& elem : characterList)
                {
                    std::cout << elem << " ";
                }
                std::cout << "\nHave a nice day!" << std::endl;
                break;
            //error catching if the user inputs a number not 1-4
            default:
                std::cout << "Invalid Menu Choice, Try Again!" << std::endl;
                break;
            
        }

    }
    

    return 0;
}
#endif
#ifdef singley

void print_list(std::forward_list<char> characters);

int main (void)
{
    std::forward_list<char> characterList = { 'a', 'b', 'c', 'd'};
    print_list(characterList);
    std::cout << "\n";
    int choice = 0;
    char inputLetter;
    while(choice != 4)
    {
        print_menu();
        print_list(characterList);
        choice = get_int_input();

        switch(choice)
        {
            //menu option one allows the user to add characters to the list
            case 1:
                inputLetter = get_char_input();
                characterList.push_front(inputLetter);
                break;
            //menu option 2 allows users to pop characers from the list
            case 2:
                characterList.pop_front();
                break;
            //menu option 3 allows users to print each character on a new line
            case 3:
                std::cout << "The current list: " << std::endl;
                for (const auto& elem : characterList)
                {
                    std::cout << elem << " " << std::endl;
                }
                break;
            //menu option 4 prints the final linked list and exits
            case 4:
                std::cout << "Final Linked List: " << std::endl;
                for (const auto& elem : characterList)
                {
                    std::cout << elem << " ";
                }
                std::cout << "\nHave a nice day!" << std::endl;
                break;
            //error catching if the user inputs a number not 1-4
            default:
                std::cout << "Invalid Menu Choice, Try Again!" << std::endl;
                break;
            
        }

    }
    return 0;
}
    
#endif

void print_menu()
{
        std::cout << "OPTIONS:" << std::endl;
        std::cout << "\t 1.) Add characters to the list" << std::endl;
        std::cout << "\t 2.) Remove a character from the list" << std::endl;
        std::cout << "\t 3.) Print each character on a new line" << std::endl;
        std::cout << "\t 4.) Exit Program" << std::endl;
}

int get_int_input()
{
    int number = 0;
    std::string input = "";
    while (true)
    {
        std::cout << "Please enter an integer: ";
        std::getline(std::cin, input);
        std::stringstream myStream(input);
        if (myStream >> number)
            break;
        std::cout << "Invalid number, please try again" << std::endl;
    }
    return number;
}

char get_char_input()
{
    char letter;
    std::string input = "";
    while (true) 
    {
        std::cout << "Please enter 1 char: ";
        getline(std::cin, input);

        if (input.length() == 1 && input[0] >= 'A' && input[0] <= 'z') 
        {
            letter = input[0];
            break;
        }

        std::cout << "Invalid character, please try again" << std::endl;
    }
    return letter;
}


void print_list(std::forward_list<char> characters)
{
    std::cout << "The current list: ";
    for (const auto& elem : characters)
    {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

void print_list(std::list<char> characters)
{
    std::cout << "The current list: ";
    for (const auto& elem : characters)
    {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}