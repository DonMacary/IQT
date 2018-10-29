#include "mecha.h"
#include "mecha_subs.h"

int main() {
	// TODO: Create your weapons here. 
	Weapon BFF1("051ANNR", "Rifle", 100, 20);
	Weapon BFF2("063ANAR", "Assault Rifle", 50, 10);
	Weapon MSAC1("SALINE05", "Spread Missile", 200, 50);
	Weapon MC1("Machine Cannon", "Automatic Cannon", 300, 50);

	
	// TODO: Create your mechs here

	// White Glint
	NEXT WG("White Glint", "main", 300);
	bool validHP = false;
	while (!validHP) {
		// update with user input
		validHP = WG.setHP(2000);
	}
	WG.set_leftHand_weapon(BFF2);
	WG.set_rightHand_weapon(BFF1);
	WG.set_leftBack_weapon(MSAC1);
	WG.set_rightBack_weapon(MSAC1);

	// Kshatriya
	MobileSuit Ksh("Kshatriya", "NZ-666");
	bool validHP2 = false;
	while (!validHP2) {
		// update with user input
		validHP2 = WG.setHP(500);
	}
	Ksh.set_leftHand_weapon(MC1);
	Ksh.set_rightHand_weapon(MC1);

	// Now we can do our main logic
	WG.display_stats(); 
	// This is where our game gets programmed. I included one method call from WG (White Glint) to demonstrate without giving away too much
	
	getchar();
	getchar();

	return 0;
}