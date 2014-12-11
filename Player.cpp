#include <iostream>
#include "Player.h"

using namespace std;

Player::Player() : Monster(100, 5)
{
    exp = 0;
    max_exp = 30;
    gold = 0;
}

int Player::get_exp()
{
    return exp;
}

int Player::get_max_exp()
{
    return max_exp;
}

int Player::get_gold()
{
    return gold;
}

void Player::add_gold(int value)
{
    gold += value;
}

void Player::add_exp(int value)
{
    exp += value;
    while(exp >= max_exp)
    {
        levelup();
    }
}

void Player::levelup()
{
    cout << "Timothy McWilliams has levelled up! Tim grows in power, and he can feel his muscles bulge!" << endl;
    cout << "After experiencing ardous battles, he has grown several callouses, making him tougher." << endl;
    exp -= max_exp;
    level += 1;
    max_exp *= 1.1;
    damage += 2;
    max_health += 10;
    current_health = max_health;
}

void Player::rest()
{
    current_health = max_health;
}

void Player::status()
{
    cout << "Level      | " << level << endl;
    cout << "Health     | " << current_health << " / " << max_health << endl;
    cout << "Damage     | " << damage << endl;
    cout << "Experience | " << exp << " / " << max_exp << endl;
    cout << "Gold       | " << gold << endl;
}
