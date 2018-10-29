# Lab 5: メカ \(Mecha\) Wars

---

## ![](/assets/rgvx0Me.jpg)Instructions:

For this lab, you are going to program a mech fighter! Below is all the details you will need to get you started. This lab will be worked upon until we finsh C++.

#### You have been provided with a few files:

* **mecha.cpp**
  * This file contains cpp code and user implementation
* **mecha.h**
  * This file contains mecha base class
* **mecha\_subs.h**
  * This file contains sub classes of mecha
* **weapons.h**
  * This file contains the weapon base class

#### Class Details:

**mecha.h -&gt; class Mecha:**

* This one has been built for you. Feel free to add onto it. 
* This class contains base stats \(mechaName, variant, type, hitpoints, power, etc\)

**weapon.h -&gt; class Weapon:**

* This one has been built for you. Feel free to add onto it.
* This class contains weapon stats \(weaponName, weaponType, damage, cost\)
* Aside from the constructors, this class also features a method that prints out the weapon's stats
* This class is meant to be created in main then used via composistion inside of a mecha subclass.

**mecha\_subs.h -&gt; class &lt;ClassName&gt;:**

* These subclasses will inherit from **class Mecha. **
* You will need to build these.
* At minimum, they include **Weapon **objects as additional members on top of the included base class members
* You will need to build a default constructor a minimum. 
* Though the more constructors can be useful 
* It's recommended you **create methods to set weapons and HP**
* These subclass's are where additional stats unique to that mech are held \(special stats\)
* There should also be a **method to print out all stats of the mech**. \(base stats, special stats and weapon stats\)

#### Member Info:

* **Mecha-&gt;**mechaName: This is just going to be the name of the mech, needs to be set in the subclass... does nothing logically
* **Mecha-&gt;**variant: This is just the version of that mech, needs to be set in the subclass, does nothing logically
* **Mecha-&gt;**type: This is the type of mech... heavy, small, tank, capital, NEXT, Mobile Suit, Meka \(D.VA\), etc. This needs to be set in the subclass. In a basic implementation... this does nothing. But on a higher implementation this can be used to determine which mechs can fight each other legally. 
* **Mecha-&gt;**hitPoints: This is the number of hitpoints the mech has starting out. This number will be set within the subclass and subtracted, added \(acted on\) within the subclass as well. 
* **Mecha-&gt;**power: Think of this as how many actions that mech can take per turn. Some weapons, movements, etc require more power. Say you have 100 power and both of your guns take 50 power. In one turn, you can shoot both guns. Then your turn is over because you are out of power. When it's your turn again, that power resets allowing you to take action on your next turn. This needs to be set within the subclass and acted on within the subclass/main.
* **Weapon**-&gt;weaponName: This is just the name of your weapon. This is set through the Weapon object \(either at creation or through a method\). This does nothing logicallly.
* **Weapon-&gt;**weaponType: This is just the type of weapon. This is also set through the Weapon object \(either at creation or through a method\). This does nothing logically on the surface. But you can implement it so that it can only be added to hands, or tank slots, etc. 
* **Weapon**-&gt;damage: This is just the number of raw hitpoints a weapon takes from another mech when it strikes it. In it's current implementation... the damage is raw and unmodified. 
* **Weapon**-&gt;cost: This is the cost in **power **that a weapon draws when fired. Refer to **Mecha-&gt;Power **for understanding of what power is.  

### Minimum Requirments:

* Must build two mecha subclasses using inheritance. Think of these subclasses as types of mechs. Some mechs have two arms. Some have weapons on their backs, some have legs and some don't. 
  * These subclasses will be created inside of the **mecha\_subs** header.
  * Aside from the members you inherit from the base... you will at least need to add the weapons \(next bullet\)
* Initialize at least 3 weapons using composition. **\(example below\)**
  * These weapons will be created in main
  * Using composition, include these weapons in the creation of your mecha\_subs. 
  * Not all the weapons need to be included into one mech. 
* Initialize a mech or two for each mech\_subclass you created. 
  * You may have a tankMech subclass of Mech... implement a couple tank mechs.
  * You may also have a flyingMech... implement a couple flying mechs too...
  * These initialized mechs will be picked by the player during mech selection
  * Remember, initializing means to actually create the object. 
* Implement the ability to spit out all stats on a mech using composition. **\(example below\)**
* Take in user input:
  * Ask user1 what mech they want to use
  * Ask user2 what mech they want to use
  * Allow users a chance to take action \(turn by turn\)
    * In the most minimal form... allowing the user to attack.
    * Let them choose which actions to take
    * Prevent actions if they run out of power
    * Allow the player to end their turn regardless of how much power is left
    * End the game if a player's mech hits &lt;= 0

# BE CREATIVE!

There are no rules except for ensuring you have utilized composition and inheritance.

![](/assets/DVa-known-pose.jpg)

### Additional Useful Information:

![](/assets/objectModell.png)

