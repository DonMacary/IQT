#include "mecha.h"
#include "mecha_subs.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

std::string get_string_input();
int get_int_input();
bool isGameOver(Onyx stoopid, Knight killer, Onyx dummy);

int main() {
	// TODO: Create your weapons here. 
	// Don't over think this step... just create weapon objects. One weapon can be used on multiple mechs
	Weapon ionCannon("Ion Cannon", "Laser", 500, 50);
	Weapon machineGun("Machine Gun", "Automatic", 50, 10);
	Weapon rockets("Rocket launcher", "Explosive", 750, 100);

	// TODO: Create your sub mechs here
	// Ensure you also pass your weapons to your mechs... you can do this via on sub mech creation or through a setter method
	// Don't overthink this one either... reference course and example if needed. 
	Onyx stoopid("Stoopid", "N/A", 50);
	Knight killer("Killer", "N/A", 100);
	Onyx dummy("Dummy:", "N/A", 100);

	stoopid.set_main_weapon(ionCannon);
	killer.set_left_weapon(machineGun);
	killer.set_right_weapon(machineGun);
	dummy.set_main_weapon(rockets);
	
	stoopid.display_stats();
	killer.display_stats();
	dummy.display_stats();

	stoopid.setHP(0);
	killer.setHP(0);
	dummy.setHP(0);
	// Now we can do our main logic
	// This is where our game gets programmed
	// Have fun here 
	// Don't get stuck on requirments... just do it!
	int choice;
	int whoseMove;
	int validChoice = 0;

	//the first loops are to give HP to whichever mechs the players choose and to determine which mech is player 1. 
	//Player 1 will always go first so the game will always start with whichever mech player 1 chooses. 
	while (validChoice == 0)
	{
		std::cout << "Player 1, choose your mech!";
		choice = get_int_input();
		switch (choice)
		{
		case 1:
			whoseMove = 0;
			stoopid.setHP(2000);
			std::cout << std::endl << "Player 1 you are now Stoopid!" << std::endl;
			validChoice = 1;
			break;
		case 2:
			whoseMove = 1;
			std::cout << std::endl << "Player 1 you are now Killer!" << std::endl;
			killer.setHP(1500);
			validChoice = 1;
			break;
		case 3:
			whoseMove = 2;
			dummy.setHP(2000);
			std::cout << std::endl << "Player 1 you are now Dummy!" << std::endl;
			validChoice = 1;
			break;
		default:
			std::cout << "Invalid Choice!" << std::endl;
			break;
		}
	}
	validChoice = 0;
	while (validChoice == 0)
	{
		std::cout << std::endl << "Player 2, choose your mech!";
		choice = get_int_input();
		switch (choice)
		{
		case 1:
			if (stoopid.getHP() > 0)
			{
				std::cout << "You cannot pick the same mech as player 1 try again" << std::endl << std::endl;
				break;
			}
			stoopid.setHP(2000);
			std::cout << std::endl;
			std::cout  << "Player 2 you are now Stoopid!" << std::endl << std::endl;
			validChoice = 1;
			break;
		case 2:
			if (killer.getHP() > 0)
			{
				std::cout << "You cannot pick the same mech as player 1 try again" << std::endl;
				break;
			}
			killer.setHP(1500);
			std::cout << std::endl << "Player 2 you are now Killer!" << std::endl << std::endl;
			validChoice = 1;
			break;
		case 3:
			if (killer.getHP() > 0)
			{
				std::cout << "You cannot pick the same mech as player 1 try again" << std::endl << std::endl;
				break;
			}
			dummy.setHP(2000);
			std::cout << std::endl << "Player 2 you are now Dummy!" << std::endl << std::endl;
			validChoice = 1;
			break;
		default:
			std::cout << "Invalid Choice!" << std::endl;
			break;
		}
	}
	//this checks if the players have chosen a certain mech. If a mech wasnt chosen then it zeroizes their health so that they are not targetable during the game.
	if (stoopid.getHP() <= 0)
	{
		stoopid.setHP(0);
	}
	if (killer.getHP() <= 0)
	{
		killer.setHP(0);
	}
	if (dummy.getHP() <= 0)
	{
		dummy.setHP(0);
	}
	/*
	Error checking
	std::cout << stoopid.getHP() << std::endl;
	std::cout << killer.getHP() <<std::endl;
	std::cout << dummy.getHP() << std::endl;
	*/
	//this loops while there is 1 or less mechs dead (one starts dead so we are waiting for 2 to be dead)
	while (isGameOver(stoopid, killer, dummy) == false)
	{
		int playerChoice = 0;
		//checks if its stoopid's turn and if he is alive
		if (whoseMove % 3 == 0 && stoopid.getHP() > 0)
		{
			//while stoopid has power, or hasnt chosend to kill himself/skip to next turn
			while (stoopid.getPower() > 0 && playerChoice <2)
			{
				std::cout << "OPTIONS FOR STOOPID" << std::endl;
				std::cout << "Remaining power: " << stoopid.getPower() << std::endl;
				if (killer.getHP() > 0)
				{
					std::cout << "1.) Fire at Killer" << std::endl;
				}
				else
				{
					std::cout << "1.) Fire at Dummy" << std::endl;
				}
				std::cout << "2.) Charge and end turn" << std::endl;
				std::cout << "3.) Self-Destruct and end game" << std::endl;
				playerChoice = get_int_input();
				while (playerChoice > 3)
				{
					std::cout << "Invalid Choice, Try again!" << std::endl;
					playerChoice = get_int_input();
				}
				switch (playerChoice)
				{
				case 1:
					//display combat text
					if (stoopid.getPower() < ionCannon.getCost())
					{
						std::cout << "Not enough power!" << std::endl;
						break;
					}
					std::cout << "Stoopid has fired " << ionCannon.getName() << " at ";
					if (killer.getHP() > 0)
					{
						std::cout << "Killer, dealing " << ionCannon.getDamage() << " damage!" << std::endl << std::endl;
						killer.setHP(killer.getHP() - ionCannon.getDamage());
					}
					else
					{
						std::cout << "Dummy, dealing " << ionCannon.getDamage() << " damage!" << std::endl << std::endl;
						dummy.setHP(dummy.getHP() - ionCannon.getDamage());
					}
					//reduce the power that the mech has
					stoopid.reducePower(ionCannon.getCost());
					std::cout << "Remaining power: " << stoopid.getPower() << std::endl;
					break;
				case 2:
					std::cout << "Charging until next turn!" << std::endl << std::endl;
					break;
				case 3:
					std::cout << "STOOPID HAS SELF-DESTRUCTED!" << std::endl << std::endl;
					stoopid.setHP(0);
					break;
				default:
					std::cout << "Something went wrong!" << std::endl;
					break;
				}
			}
			stoopid.charge();
			playerChoice = 0;
		}
		//checks if its killers turn and if he is alive
		else if (whoseMove % 3 == 1 && killer.getHP() > 0)
		{
			while (killer.getPower() > 0 && playerChoice < 2)
			{
				std::cout << "OPTIONS FOR KILLER" << std::endl;
				std::cout << "Remaining power: " << killer.getPower() << std::endl;
				if (dummy.getHP() > 0)
				{
					std::cout << "1.) Fire at Dummy" << std::endl;
				}
				else
				{
					std::cout << "1.) Fire at Stoopid" << std::endl;
				}
				std::cout << "2.) Charge and end turn" << std::endl;
				std::cout << "3.) Self-Destruct and end game" << std::endl;
				playerChoice = get_int_input();
				while (playerChoice > 3)
				{
					std::cout << "Invalid Choice, Try again!" << std::endl;
					playerChoice = get_int_input();
				}
				switch (playerChoice)
				{
				case 1:
					//display combat text
					if (killer.getPower() < machineGun.getCost())
					{
						std::cout << "Not enough power!" << std::endl;
						break;
					}
					std::cout << "Killer has fired his left " << machineGun.getName() << " at ";
					if (stoopid.getHP() > 0)
					{
						std::cout << "Stoopid, dealing " << machineGun.getDamage() << " damage!" << std::endl << std::endl;
						stoopid.setHP(stoopid.getHP() - machineGun.getDamage());
					}
					else
					{
						std::cout << "Dummy, dealing " << machineGun.getDamage() << " damage!" << std::endl << std::endl;
						dummy.setHP(dummy.getHP() - machineGun.getDamage());
					}
					//reduce the power that the mech has
					killer.reducePower(machineGun.getCost());
					if (killer.getPower() == 0)
					{
						break;
					}
					std::cout << "Killer has fired his right " << machineGun.getName() << " at ";
					if (stoopid.getHP() > 0)
					{
						std::cout << "Stoopid, dealing " << machineGun.getDamage() << " damage!" << std::endl << std::endl;
						stoopid.setHP(stoopid.getHP() - machineGun.getDamage());
					}
					else
					{
						std::cout << "Dummy, dealing " << machineGun.getDamage() << " damage!" << std::endl << std::endl;
						dummy.setHP(dummy.getHP() - machineGun.getDamage());
					}
					//reduce the power that the mech has
					killer.reducePower(machineGun.getCost());
					std::cout << "Remaining power: " << killer.getPower() << std::endl << std::endl;
					break;
				case 2:
					std::cout << "Charging until next turn!" << std::endl << std::endl;
					break;
				case 3:
					std::cout << "KILLER HAS SELF-DESTRUCTED!" << std::endl << std::endl;
					killer.setHP(0);
					break;
				default:
					std::cout << "Something went wrong!" << std::endl;
					break;
				}
			}
			killer.charge();
			playerChoice = 0;
		}
		//checks if its dummys turn and if he is alive
		else if (whoseMove % 3 == 2 && dummy.getHP() > 0)
		{
			while (dummy.getPower() > 0 && playerChoice <2)
			{
				std::cout << "OPTIONS FOR DUMMY" << std::endl;
				std::cout << "Remaining power: " << dummy.getPower() << std::endl;
				if (stoopid.getHP() > 0)
				{
					std::cout << "1.) Fire at Stoopid" << std::endl;
				}
				else
				{
					std::cout << "1.) Fire at Killer" << std::endl;
				}
				std::cout << "2.) Charge and end turn" << std::endl;
				std::cout << "3.) Self-Destruct and end game" << std::endl;
				playerChoice = get_int_input();
				while (playerChoice > 3)
				{
					std::cout << "Invalid Choice, Try again!" << std::endl;
					playerChoice = get_int_input();
				}
				switch (playerChoice)
				{
				case 1:
					if (dummy.getPower() < rockets.getCost())
					{
						std::cout << "Not enough power!" << std::endl;
						break;
					}
					//display combat text
					std::cout << "Dummy has fired his " << rockets.getName() << " at ";
					if (stoopid.getHP() > 0)
					{
						std::cout << "Stoopid, dealing " << rockets.getDamage() << " damage!" << std::endl << std::endl;
						stoopid.setHP(stoopid.getHP() - rockets.getDamage());
					}
					else
					{
						std::cout << "Killer, dealing " << rockets.getDamage() << " damage!" << std::endl << std::endl;
						killer.setHP(killer.getHP() - rockets.getDamage());
					}
					//reduce the power that the mech has
					dummy.reducePower(rockets.getCost());
					std::cout << "Remaining power: " << dummy.getPower() << std::endl << std::endl;
					break;
				case 2:
					std::cout << "Charging until next turn!" << std::endl << std::endl;
					break;
				case 3:
					std::cout << "DUMMY HAS SELF DESTRUCTED!" << std::endl << std::endl;
					dummy.setHP(0);
					break;
				default:
					std::cout << "Something went wrong!" << std::endl;
					break;

				}
			}
			
			dummy.charge();
			playerChoice = 0;
		}
		//charge all mechs for next turn

		//display all mechs HP
		std::cout << "Stoopid's HP: " << stoopid.getHP() << std::endl;
		std::cout << "Killer's HP: " << killer.getHP() << std::endl;
		std::cout << "Dummy's HP: " << dummy.getHP() << std::endl;
		std::cout << "=========================================" << std::endl << std::endl;
		whoseMove++;
	}
	std::cout << "Game Over!" << std::endl;

	std::cout << "Winner: "; 
	if (stoopid.getHP() > 0)
	{
		std::cout << "Stoopid" << std::endl;
	}
	else if (killer.getHP() > 0)
	{
		std::cout << "Killer" << std::endl;
	}
	else
	{
		std::cout << "Dummy" << std::endl;
	}


	getchar();
	getchar();

	return 0;
}


//Function to get string input from the user and checks to make sure all characters are letters
std::string get_string_input()
{
	std::string input;
	bool goodString;
	//continue looping until all characters are alphanumeric.. if they arent then get input again
	while (true)
	{
		//gets the string from the input line
		std::getline(std::cin, input);
		//loops through every character
		for (int i = 0; i<input.length(); i++)
		{
			//checks if the character is alphanumeric - if not print an error 
			if (isalpha(input[i]) == false)
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
		if (goodString == true)
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

bool isGameOver(Onyx stoopid, Knight killer, Onyx dummy)
{
	int robotsDead = 0;
	if (stoopid.isAlive() == false)
	{
		robotsDead++;
	}
	if (killer.isAlive() == false)
	{
		robotsDead++;
	}
	if (dummy.isAlive() == false)
	{
		robotsDead++;
	}
	if (robotsDead > 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
