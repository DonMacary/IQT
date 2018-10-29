/*************************************************************************************************
   Using what you know from C/C++ so far, create a quick program that accomplishes the following:

    Create a UI to accomplish all functionality
    Allow a user to input a person and their associated job title
    Allow a user to find a person based on name
        Allow a user to delete this person
    Allow the user to input more people
**************************************************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <sstream>


int main(void)
{
    std::map<std::string, std::string> workPlace; //a map that takes in a name as the key and a job title
    //inserting some BS in the map
    workPlace.emplace("Donnie Macary", "Cyber Person");
    workPlace.emplace("Don Macary", "CEO");
    workPlace.emplace("John Macary", "Manager");
    workPlace.emplace("Susan Macary", "Bookie");

    std::string input = "";
    int choice = 0;

    

    while(choice != 5)
    {
        //Print the menu
        std::cout << "OPTIONS:" <<std::endl;
        std::cout << "\t1.) Add a person to the work place" << std::endl;
        std::cout << "\t2.) Find person by name" <<std::endl;
        std::cout << "\t3.) Delete person" <<std::endl;
        std::cout << "\t4.) Print entire map" << std::endl;
        std::cout << "\t5.) Exit program" << std::endl;
        //accpets the persons menu input and makes converts it to an int
        while (true)
		{
			std::cout << "Please enter your choice (1-5): ";
			std::getline(std::cin, input);
			std::stringstream myStream(input);
			if (myStream >> choice)
				break;
			std::cout << "Invalid number, please try again" << std::endl;
		}
        std::string name = "";
        std::string job = "";
        bool goodString = false;
        switch (choice)
        {
            //menu option one is to add a person to the map
            case 1:
                //the first loop takes in the persons name and makes sure it only contains letters and spaces
                while(true)
                {
                    std::cout << "Enter the name of the person you would like to add: ";
                    std::getline(std::cin, name);
                    for(int i =0; i<name.length(); i++)
                    {
                        if(isalpha(name[i]) == false && isspace(name[i]) == false)
                        {
                            std::cout << "Name contains invalid chatacters!" << std::endl;
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
                //this loop takes in a persons job and makes sure it only contains letters and spaces
                while(true)
                {
                    std::cout << std::endl << "Enter this person's job: ";
                    std::getline(std::cin, job);
                    for(int i =0; i<job.length(); i++)
                    {
                        if(isalpha(job[i]) == false && isspace(job[i]) == false)
                        {
                            std::cout << "Job contains invalid chatacters!" << std::endl;
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
                //once we have good name and job put them in the map!
                workPlace.emplace(name,job);
                break;
            //menu option 2 is to look someone up by their name
            case 2:
                //the first loop takes in the persons name and makes sure it only contains letters and spaces
                while(true)
                {
                    std::cout << "Enter the name of the person you would like to add: ";
                    std::getline(std::cin, name);
                    for(int i =0; i<name.length(); i++)
                    {
                        if(isalpha(name[i]) == false && isspace(name[i]) == false)
                        {
                            std::cout << "Name contains invalid chatacters!" << std::endl;
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
                //once we have the name we want to search for we loop through to map until we find that name
                if(workPlace.find(name) != workPlace.end())
                {
                    std::cout << name << " has a job of: " << workPlace[name] << std::endl;
                }
                else{
                    std::cout << "Nobody found with the name of: " << name << std::endl;
                }
                break;
            // Menu option 3 is to delete a person - it will search for their name then delete the entry
            case 3:
                //prompts the user for the name of the person they want to delete
                while(true)
                {
                    std::cout << "Enter the name of the person you would like to delete: ";
                    std::getline(std::cin, name);
                    for(int i =0; i<name.length(); i++)
                    {
                        if(isalpha(name[i]) == false && isspace(name[i]) == false)
                        {
                            std::cout << "Name contains invalid chatacters!" << std::endl;
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
                if(workPlace.find(name) != workPlace.end())
                {
                    std::cout << "Deleting " << name << std::endl;
                    workPlace.erase(workPlace.find(name));
                }
                else
                {
                    std::cout << "Nobody found with the name of: " << name << std::endl;
                }

                break;

            //Menu option 4 prints the entire map
            case 4:
                std::cout << "Name\t" << "\tJob" << std::endl;
                std::cout << "--------------------------------" << std::endl;
                for(auto it = workPlace.cbegin(); it != workPlace.end(); ++it)
                {
                    std::cout << it->first << "\t" << it->second << std::endl;
                }
                break;
            case 5:
                std::cout << "Have a nice day!" << std::endl;
                break;
            default:
                std::cout << "Invalid number!" << std::endl;

        }

    }
    return 0;
}