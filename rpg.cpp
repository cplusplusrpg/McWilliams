#include <iostream>
#include <vector>
#include "Monster.h"
#include "Player.h"
#include "function.h"
#include "Item.h"

using namespace std;

class Inventory
{
public:
    Inventory()
    {
    }
    void add_weapon(string n, int value, int da, int du)
    {
        Weapon tmp(n, value, da, du);
        weapons.push_back(tmp);
    }
    void add_armor(string n, int value, int de, int du)
    {
        Armor tmp(n, value, de, du);
        armors.push_back(tmp);
    }
    void add_potion(string n, int value, int amount)
    {
        Potion tmp(n, value, amount);
        potions.push_back(tmp);
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
