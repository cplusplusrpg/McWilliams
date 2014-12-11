#include <iostream>
#include <string>
#include <vector>
#include "Monster.h"
#include "Player.h"
#include "function.h"
using namespace std;

class Item
{
public:
    Item() : name(""), cost(0)
    {
    }
    Item(string n, int v) : name(n), cost(v)
    {
    }
    string get_name()
    {
        return name;
    }
    int get_cost()
    {
        return cost;
    }
protected:
    string name;
    int cost;
};

class Weapon : public Item
{
public:
    Weapon() : damage(0), durability(1)
    {
    }
    Weapon(int da, int du) : damage(da), durability(du)
    {
    }
    int get_damage()
    {
        return damage;
    }
    int get_durability()
    {
        return durability;
    }
    void use_weapon()
    {
        durability -= 1;
    }
private:
    int damage;
    int durability;
};

class Armor : public Item
{
public:
    Armor() : defence(0), durability(1)
    {
    }
    Armor(int de, int du) : defence(de),durability(du)
    {
    }
    int get_defence()
    {
        return defence;
    }
    int get_durability()
    {
        return durability;
    }
private:
    int defence;
    int durability;
};

class Potion : public Item
{
public:
    Potion() : recovery(0)
    {
    }
    Potion(int amount) : recovery(amount)
    {
    }
private:
    int recovery;
};

class Inventory
{
public:
    Inventory()
    {
    }
    void add_weapon(Weapon w)
    {
        weapons.push_back(w);
    }
    void add_armor(Armor a)
    {
        armors.push_back(a);
    }
    void add_potion(Potion p)
    {
        potions.push_back(p);
    }
private:
    vector<Weapon> weapons;
    vector<Armor> armors;
    vector<Potion> potions;
};

int main()
{
    Player Tim;
    Monster Slime;
    int choice;

    cout << "These are the Adventures of Timothy McWilliams. The greatest story ever told." << endl;
    cout << "The fate of Timothy McWilliams depends on you." << endl << endl;
    do
    {
        choice = menu();
        
        if(choice == 1)
        {
            turn(Tim, Slime);
        }
        else if(choice == 2)
        {
            cout << "Tim walks to the store, and sees a sign that reads \"Closed for lunch\"." << endl;
        }
        else if(choice == 3)
        {
            Tim.status();
        }
        else if(choice == 4)
        {
            Tim.rest();
            cout << "Timothy rests for a moment and he can feel his muscles relax." << endl;
            cout << "Tim has " << Tim.get_health() << " health." << endl;
        }
    } while(choice < 5 and choice > 0);
	return 0;
}
