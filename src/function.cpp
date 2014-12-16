//These are several functions that are not member functions of a class, but are used in the core program. They accomplish various tasks and are not necessarily related.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "function.h"
#include "Monster.h"
#include "Player.h"

using namespace std;


//Turn is the function that is called to simulate a battle. At the moment, it only takes 1 Player and 1 Monster. This means no multi-enemy fights for now.
//However, that functionality might be added in later.
void turn(Player& Tim, Monster creature)
{
    srand(time(0));//semi-random generation for chances at critical hits or fumbles.
    int choice, Tim_damage, creature_damage;
    bool flee = false;
    cout << "Tim sees a creature! Tim has poor vision, so the identity of the creature is unknown." << endl;
    do
    {
        int chance1 = (rand() % 100) + 1, chance2 = (rand() % 100) + 1;
        display_battle(Tim.get_health(), creature.get_health());
        choice = battle_menu();//battle_menu just gets the answer for what the Player wants to do on their turn.
        if(choice == 1)//If they chose to attack, then:
        {
            Tim_damage = Tim.attack();
            creature_damage = creature.attack();
            if(chance1 <= 5)//First determine how the attack went
            {
                creature.hurt(Tim_damage * 3 / 2);
                cout << "Tim lands a critical hit! The creature was hurt for " << Tim_damage * 3 / 2 << " damage!" << endl;
            }
            else
            {
                creature.hurt(Tim_damage);
                cout << "The creature was hurt for " << Tim_damage << " damage!" << endl;
            }
            if(creature.check_life())//If creature is still alive, they get to retaliate.
            {
                if(chance2 <= 5)
                {
                    Tim.hurt(creature_damage * 2);
                    cout << "The creature lands a critical hit! Tim was hurt for " << creature_damage * 2 << " damage!" << endl;
                }
                else
                {
                    Tim.hurt(creature_damage);
                    cout << "Tim was hurt for " << creature_damage << " damage!" << endl;
                }
            }
            else
            {
                creature.kill();//Otherwise, the creature is dead.
            }
        }
        else if(choice == 2)//Or the Player might choose to flee the battle.
        {
            cout << "Tim flees from the creature like a coward!" << endl;
            cout << "The creature is unable to keep up with Tim's cowardly speed." << endl;
            flee = true;
        }
    } while(Tim.check_life() and creature.check_life() and !flee);//The battle will continue until someone is dead or the Player fled the battle.
    if(!creature.check_life())//If the creature is the dead one, display the battle results.
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

//Menu is just the main menu, and it returns the user's choice of what the wish to do. Evaluation of the user's response is taken care of in the core program.
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

//Currently, we only have 1 Monster, which is a Slime. The way we are displaying the creatures is currently being worked on, so this is just temporary.
//As this method of display will ONLY work while we only have the Slime to work with.
void display_battle(int Tim_health, int enemy_health)
{
    Player Tim;
    Monster creature;
    int max_health = creature.get_health();
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

//A menu for when the user is in battle. Currently there are only 2 options: fight or flee.
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
