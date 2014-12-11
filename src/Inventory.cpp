#include <iostream>
#include "Inventory.h"

using namespace std;

Inventory::Inventory()
{
}

void Inventory::add_weapon(string n, int value, int da, int du)
{
    Weapon tmp(n, value, da, du);
    weapons.push_back(tmp);
}

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
