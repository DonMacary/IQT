#pragma once
#include "weapons.h"
#include <string>
#include <iostream>

// Sub Classes
class Onyx : public Mecha
{
private:
	Weapon mainGun;

public:
	Onyx()
	{
		mechaName = "Onyx";
		variant = "N/A";
		type = "Onyx";
		power = 50;
	}
	Onyx(std::string mn, std::string va, int pwr = 75)
	{
		mechaName = mn;
		variant = va;
		type = "Onyx";
		power = pwr;
	}

	void set_main_weapon(Weapon wp)
	{
		mainGun = wp;
	}
	bool setHP(int hp) {
		// Onyx units can only have 2000 health
		if (hp <= 2000) {
			hitPoints = hp;
			return true;
		}
		return false;
	}
	void display_stats() {
		std::cout << "Displaying Stats" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====" << std::endl;
		std::cout << "Main Gun:" << std::endl;
		mainGun.display_weapon_stats();
		std::cout << "\n\n";
	}
	void charge()
	{
		power = power + 50;
	}
};

class Knight : public Mecha
{
private:
	Weapon leftGun;
	Weapon rightGun;

public:
	Knight()
	{
		mechaName = "Knight";
		variant = "N/A";
		type = "Knight";
		power = 100;
	}
	Knight(std::string mn, std::string va, int pwr = 100)
	{
		mechaName = mn;
		variant = va;
		type = "Knight";
		power = pwr;
	}

	void set_left_weapon(Weapon wp)
	{
		leftGun = wp;
	}
	void set_right_weapon(Weapon wp)
	{
		rightGun = wp;
	}
	bool setHP(int hp) {
		// Knight units can only have 1500 health
		if (hp <= 1500) {
			hitPoints = hp;
			return true;
		}
		return false;
	}
	void display_stats() {
		std::cout << "Displaying Stats" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====" << std::endl;
		std::cout << "Left Gun:" << std::endl;
		leftGun.display_weapon_stats();
		std::cout << "Right Gun:" << std::endl;
		rightGun.display_weapon_stats();
		std::cout << "\n\n";
	}

	void charge()
	{
		power = power + 50;
	}
};





