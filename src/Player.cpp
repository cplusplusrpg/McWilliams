//Player class is a derived class from Monster. A player is basically a more complex monster.
//In addition to having similar properties as a Monster (with notable exceptions of exp and gold reward), A player will have exp, gold, an Inventory, etc. A player is also capable of levelling up. This ability might want to be extended to Monster for certain situations, but for time being, they cannot.

#include <iostream>
#include "Player.h"

using namespace std;

Player::Player() : Monster("Timothy McWilliams", 1, 100, 5, 0, 0)
{
    exp = 0;
    max_exp = 30;
    gold = 0;//A player will start out at level 1 with no money and 30 exp to level up.
}

int Player::get_exp()
{
    return exp;//Again, a few simple get functions that return the corresponding value.
}

int Player::get_max_exp()
{
    return max_exp;
}

int Player::get_gold()
{
    return gold;
}

//Every once in a while, a player will need to earn money. Currently, only by killing monsters.
void Player::add_gold(int value)
{
    gold += value;
}

void Player::add_exp(int value)//The player will also need to gain exp, and level up under certain circumstances.
{
    exp += value;
    while(exp >= max_exp)
    {
        levelup();
    }
}

void Player::levelup()//If the player's exp is >= to max_exp, then they can level up, and max_exp increases. At the moment, by 10%.
{
    cout << "Timothy McWilliams has levelled up! Tim grows in power, and he can feel his muscles bulge!" << endl;
    cout << "After experiencing ardous battles, he has grown several callouses, making him tougher." << endl;
    exp -= max_exp;
    level += 1;
    max_exp *= 1.1;
    damage += 2;
    max_health += 10;
    current_health = max_health;
}//The current bonuses from levelling up are +2 damage and +10 health. And the player is fully healed.


//The player needs some rest every now and then to recover their hitpoints. If they didn't, their adventures would be very short-lived. Literally.
void Player::rest()
{
    current_health = max_health;
}


//And the player should be allowed to view all of his abilities in one place.
void Player::status()
{
    cout << "Level      | " << level << endl;
    cout << "Health     | " << current_health << " / " << max_health << endl;
    cout << "Damage     | " << damage << endl;
    cout << "Experience | " << exp << " / " << max_exp << endl;
    cout << "Gold       | " << gold << endl;
}
