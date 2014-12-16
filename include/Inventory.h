//The Inventory class. A Player will have an Inventory to store any and all Items he has.
//At the moment, the only Items that exist are Weapons, Armors, and Potions, but as more are created, the Inventory class will be given more vectors.
//All member functions are explained in the implementation file: Inventory.cpp

#ifndef __INVENTORY_H_INCLUDED__
#define __INVENTORY_H_INCLUDED__

#include <vector>
#include <string>
#include "Item.h"

class Inventory
{
public:
    Inventory();
    void add_weapon(std::string n, int value, int da, int du);
    void add_armor(std::string n, int value, int de, int du);
    void add_potion(std::string n, int value, int amount);
private:
    std::vector<Weapon> weapons;
    std::vector<Armor> armors;
    std::vector<Potion> potions;
};
//The Inventory class contains a vector that contains a subset of Items. 1 vector for each type.
//1 vector that contains Items was considered, but such an implementation would lead to an overall lack of organization.
//So, multiple vectors of different derived Items are used instead.

#endif
