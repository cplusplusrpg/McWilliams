#include <iostream>
#include "Item.h"

using namespace std;

Item::Item() : name(""), cost(0)
{
}

Item::Item(string n, int v) : name(n), cost(v)
{
}

string Item::get_name()
{
   return name;
}

int Item::get_cost()
{
   return cost;
}

Weapon::Weapon() : Item()
{
    damage = 0;
    durability = 1;
}

Weapon::Weapon(string n, int value, int da, int du) : Item(n, value)
{
    damage = da;
    durability = du;
}

int Weapon::get_damage()
{
    return damage;
}

int Weapon::get_durability()
{
    return durability;
}

void Weapon::use_weapon()
{
    durability -= 1;
}

Armor::Armor() : Item()
{
    defence = 0;
    durability = 1;
}

Armor::Armor(string n, int value, int de, int du) : Item(n, value)
{
    defence = de;
    durability = du;
}

int Armor::get_defence()
{
    return defence;
}

int Armor::get_durability()
{
    return durability;
}

Potion::Potion() : Item()
{
    recovery = 0;
}

Potion::Potion(string n, int value, int amount) : Item(n, value)
{
    recovery = amount;
}
