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

#endif
