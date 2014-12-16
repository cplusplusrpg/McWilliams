//The Item class and classes derived from Item.
//So far, only Weapon, Armor, and Potion exist, but they will be expanded as development progresses.
//All member functions are explained in the implementation file: Item.cpp

#ifndef __ITEM_H_INCLUDED__
#define __ITEM_H_INCLUDED__

#include <string>

class Item
{
public:
    Item();
    Item(std::string n, int v);
    std::string get_name();
    int get_cost();
protected:
    std::string name;//All Items will need a name to refer by.
    int cost;//And a cost, in case the Player wishes to sell an Item.
};

//Weapons are an Item that have a damage value and a durability.
class Weapon : public Item
{
public:
    Weapon();
    Weapon(std::string n, int value, int da, int du);
    int get_damage();
    int get_durability();
    void use_weapon();
private:
    int damage;//An equipped Weapon's damage will increase the Player's damage output by some amount.
    int durability;//The durability will decrease every time it is used and the weapon will break when it reaches zero.
};

//Armor is very similar to Weapon, except that it increases a Player's defensive abilities.
class Armor : public Item
{
public:
    Armor();
    Armor(std::string n, int value, int de, int du);
    int get_defence();
    int get_durability();
private:
    int defence;
    int durability;
};

//Currently Potions are very basic. There are only Potions that heal a flat amount of health.
//This class will likely be expanded in the future to contain different Potions, perhaps some that grant status effects.
class Potion : public Item
{
public:
    Potion();
    Potion(std::string n, int value, int amount);
private:
    int recovery;//A Potion will heal the Player by a flat amount of hitpoints.
};
//The Potion class still needs to be implemented. While a Potion may contain a recovery value, that value is unused. For now.

#endif
