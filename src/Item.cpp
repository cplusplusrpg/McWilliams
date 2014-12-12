//The Item class contains various different types of objects that a player or monster might use. The Item class itself currently only offers a name and cost.
//Any further information is applied to the derived classes, Weapon, Armor, and Potion.
//Currently, Weapons and Armor have a damage/defence value and a durability. This durability will at least serve as way to remove money from the game.

#include <iostream>
#include "Item.h"

using namespace std;

//All Items in the game will have a name and a cost at least.
Item::Item() : name(""), cost(0)
{
}

//The default constructor is not of much use as far as the RPG is concerned, so this constructor is available to make useful Items.
Item::Item(string n, int v) : name(n), cost(v)
{
}

string Item::get_name()
{
   return name;
}
//And of course a way to refer to these Item's name and cost.
int Item::get_cost()
{
   return cost;
}

//Classes derived from Item will be available for use in game. Again, default constructor is not of much use, unfortunately.
Weapon::Weapon() : Item()
{
    damage = 0;
    durability = 1;
}

//So, this constructor will be used to create any useful Weapon in the game. It needs to know the Weapon's name, cost, damage, and durability.
Weapon::Weapon(string n, int value, int da, int du) : Item(n, value)
{
    damage = da;
    durability = du;
}

//Simple get functions that return the corresponding value.
int Weapon::get_damage()
{
    return damage;
}

int Weapon::get_durability()
{
    return durability;
}

//Whenever a weapon is used, it's durability will need to be decreased.
void Weapon::use_weapon()
{
    durability -= 1;
}

//Armor is another type of Item. An Armor will have a defence value, and a durability.
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

//Potions are the last type of Item that have been added so far. They only have a recovery value.
Potion::Potion(string n, int value, int amount) : Item(n, value)
{
    recovery = amount;
}

//Potions need to be developed a bit further.
//Considerations for potions that do more than just heal have been made, but those can be created later.
