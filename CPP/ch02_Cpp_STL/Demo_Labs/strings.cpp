/***************************************************************************
Let's create a short program that does the following:

    Print out "Hello World!"
    Print the length of the string
    Create a substring of "Hello World!" and make it only contain "Hello"
        Print that substring out
    Find the "r" in "Hello World!"
        Print out it's position
    On the "Hello" substring, append your name.
        Print out the substring
***************************************************************************/

#include <iostream>
#include <string>

int main(void)
{
    //create a string
    std::string string1 = ("Hello World");

    //print the string
    std::cout << string1 << std::endl;

    //print the length of the string
    std::cout << "The length of the string is: " << string1.length() << std::endl;

    //find the position of the space and store it in a variable
    auto position = string1.find(" ");

    //create a new string with just the first word
    auto string2 = string1.substr(0, position);

    //print the new string
    std::cout << string2 << std::endl;

    //print the position of the letter r
    std::cout << "Location of 'r' in word: " << string1.find("r") << std::endl;

    //add my name to the end of string2
    string2.append(" Donnie!");

    //print string 2
    std::cout << string2 << std::endl;
    
    //print out the substring of string2 and just print my name
    std::cout << string2.substr(string2.find("Donnie")) << std::endl;

    return 0;
}