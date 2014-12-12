//A classic RPG of course needs to have an inventory system.
//How long would poor Tim last if he had to fight a dragon brandishing only his fists and nothing to protect his cowardly skin from fire?
//The Inventory class needs a bit more work before it is fully functioning, but at the moment, we have a way to store different items.

#include <iostream>
#include "Inventory.h"

using namespace std;

Inventory::Inventory()
{
}
//Vectors are already initialized empty, so the default constructor doesn't have any work to do for the time being.

void Inventory::add_weapon(string n, int value, int da, int du)
{
    Weapon tmp(n, value, da, du);
    weapons.push_back(tmp);
}//Create an Item of the corresponding type, with the correct stats, and add it to the appropriate vector.

void Inventory::add_armor(string n, int value, int de, int du)
{
    Armor tmp(n, value, de, du);
    armors.push_back(tmp);
}

void Inventory::add_potion(string n, int value, int amount)
{
    Potion tmp(n, value, amount);
    potions.push_back(tmp);
}

//The Inventory system technically is functional, but it has yet to be implemented within the core program.
//This class can be expanded as needed while we move forward.
