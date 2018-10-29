/********************************************************************************************************************
/   AUTHOR: ELF
/   COURSE: C++ Programming
/   PROGRAM NAME: lab1A.cpp
/   PROGRAM DESCRIPTION: Performance lab 2A - File IO
/   INSTRUCTIONS:
       Provided a text file, use the STL to read from it and count each occurrence of each word. Once complete, output to **stdout **each word, and the number of times it occurred. Sort the output by words that occured the most to words that occured the least. 

        You will write this program in its entirety. There will be no source code provided by the instructor, only a text file containing the input.

        The instructional goal of this lab is to give you practice using the STL. Use _STL containers_, _algorithms_, and _iterators_ where they would be helpful.


**********************************************************************************************************************/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>



int main (void)
{
    std::ifstream file("lyrics.txt");
    std::string line;
    std::string word;
    std::map<std::string, int> allWords;
    //make sure the file opens
    if(!file.is_open())
    {
        perror("Error opening file");
    }
    //read each line of the file
    while(getline(file, line))
    {
        std::istringstream iss(line); //stores the line in a string stream
        //loops through each word in the string stream
        while(iss >> word)
        {   
            //if the word is in the map then increment the int value by one
            if(allWords.find(word) != allWords.end())
            {
                allWords[word]++;
            }
            //otherwise add it to the map with a value of 1
            else
            {
                allWords.emplace(word, 1);
            }
        }
        
    }
    //sort the results: the first loop determines the most frequent map entry
    std::vector<std::pair<int, std::string> > sortMe;
    for(auto it = allWords.cbegin(); it != allWords.end(); it++)
    {
        sortMe.emplace_back(make_pair(it->second, it->first));
    }
    std::sort(sortMe.rbegin(), sortMe.rend());

    //once we are done reading every line in the file print the results
    std::cout << "RESULTS" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "COUNT\t\tWORD" << std::endl;
    std::cout << "------------------------------" << std::endl;

    for(auto it = sortMe.cbegin(); it != sortMe.end(); it++)
    {
        std::cout << it->first << "\t\t" << it->second << std::endl;
    }
    //if we have trouble reading the file 
    if(file.bad())
    {
        perror("Error when reading file");
    }

    return 0;
}