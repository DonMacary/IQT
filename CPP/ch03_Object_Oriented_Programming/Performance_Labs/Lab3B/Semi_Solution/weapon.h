#pragma once
class Weapon {
private:
	std::string weaponName;
	std::string weaponType;
	int damage;					// How much damage this weapon does
	int cost;					// Cost to use weapon on turn
public:
	Weapon() {}
	Weapon(std::string name, std::string type, int dmg, int ct) {
		weaponName = name;
		weaponType = type;
		damage = dmg;
		cost = ct;
	}
	void display_weapon_stats() {
		std::cout << "Model: " << weaponName << std::endl;
		std::cout << "Type: " << weaponType << std::endl;
		std::cout << "Damage: " << damage << std::endl;
		std::cout << "Cost: " << cost << std::endl;
	}
};