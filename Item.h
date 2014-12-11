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
    std::string name;
    int cost;
};

class Weapon : public Item
{
public:
    Weapon();
    Weapon(std::string n, int value, int da, int du);
    int get_damage();
    int get_durability();
    void use_weapon();
private:
    int damage;
    int durability;
};

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

class Potion : public Item
{
public:
    Potion();
    Potion(std::string n, int value, int amount);
private:
    int recovery;
};

#endif
