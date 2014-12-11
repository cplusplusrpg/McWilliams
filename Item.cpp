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

Weapon::Weapon() : damage(0), durability(1)
{
}

Weapon::Weapon(int da, int du) : damage(da), durability(du)
{
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

Armor::Armor() : defence(0), durability(1)
{
}

Armor::Armor(int de, int du) : defence(de), durability(du)
{
}

int Armor::get_defence()
{
    return defence;
}

int Armor::get_durability()
{
    return durability;
}

Potion::Potion() : recovery(0)
{
}

Potion::Potion(int amount) : recovery(amount)
{
}
