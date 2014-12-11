#include <iostream>
#include "function.h"
#include "Monster.h"
#include "Player.h"

using namespace std;

void turn(Player& Tim, Monster creature)
{
    int choice, Tim_damage, creature_damage;
    bool flee = false;
    cout << "Tim sees a creature! Tim has poor vision, so the identity of the creature is unknown." << endl;
    do
    {
        display_battle(Tim.get_health(), creature.get_health());
        choice = battle_menu();
        if(choice == 1)
        {
            Tim_damage = Tim.get_damage();
            creature_damage = creature.get_damage();
            creature.hurt(Tim_damage);
            cout << "The creature was hurt for " << Tim_damage << " damage!" << endl;
            if(creature.check_life())
            {
                Tim.hurt(creature_damage);
                cout << "Tim was hurt for " << creature_damage << " damage!" << endl;
            }
            else
            {
                creature.kill();
            }
        }
        else if(choice == 2)
        {
            cout << "Tim flees from the creature like a coward!" << endl;
            cout << "The creature is unable to keep up with Tim's cowardly speed." << endl;
            flee = true;
        }
    } while(Tim.check_life() and creature.check_life() and !flee);
    if(!creature.check_life())
    {
        cout << "The battle has ended. Tim has slain the creature with a mighty finishing blow!" << endl;
        cout << "Tim gains " << creature.get_exp_reward() << " experience from slaying the creature!" << endl;
        Tim.add_exp(creature.get_exp_reward());
        cout << "Tim has " << Tim.get_max_exp() - Tim.get_exp() << " experience until he levels up!" << endl;
        cout << "Tim finds some gold pieces on the ground near the creature." << endl;
        Tim.add_gold(creature.get_gold_reward());
        cout << "Tim has " << Tim.get_gold() << " gold pieces." << endl;
        cout << "Feeling empowered, Timothy returns to the village." << endl;
    }
}

int menu()
{
    int response = 0;
    do
    {
        cout << "What would you like to do?" << endl;
        cout << "1) Wander in the wilderness?" << endl;
        cout << "2) Check the local stores for goods?" << endl;
        cout << "3) Take a look at how your adventure has progressed?" << endl;
        cout << "4) Take a moment to catch your breath? (Regain health)" << endl;
        cout << "5) Lay your weary head to rest?" << endl;
        cin >> response;
        if(response < 1 or response > 5)
        {
            cout << "Invalid response. Adventure confused." << endl;
            cin >> response;
        }
    } while(response < 1 or response > 5);

    return response;
}

void display_battle(int Tim_health, int enemy_health)
{
    cout << endl;
    cout << "         Timothy                       Beginner's Slime    " << endl;
    cout << "         HP: " << Tim_health << "                            HP: " << enemy_health << "          " << endl;
    cout << "           ---                                             " << endl;
    cout << "          [. .]                                     ____   " << endl;
    cout << "          [   ]  |                            ______|  |   " << endl;
    cout << "     ----  ---   |                            |     |__|   " << endl;
    cout << "     |  |   |    |                            |            " << endl;
    cout << "     |  |---|----|                     _______|_______     " << endl;
    cout << "     ----   |                          |             |     " << endl;
    cout << "            |                          |  []     []  |     " << endl;
    cout << "         -------                       |             |     " << endl;
    cout << "         |     |                       |  |_______|  |     " << endl;
    cout << "         |     |                       |_____________|     " << endl;
    cout << "-----------------------------------------------------------" << endl;
}

int battle_menu()
{
    int response = 0;
    do
    {
        cout << "What would you like to do?" << endl;
        cout << "1) Attack?" << endl;
        cout << "2) Flee?" << endl;
        cin >> response;
        if(response < 1 or response > 2)
        {
            cout << "Invalid action." << endl;
        }
    } while(response < 1 or response > 2);

    return response;
}
