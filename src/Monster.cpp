//The Monster class will be used to create various monsters with various differnt stats. A different level, gold or exp reward, etc.
//They have a boolean value that will return whether they are alive or not.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Monster.h"

using namespace std;


//A generic monster is just level 1, with 100 health that does 5 damage. It rewards no exp and no gold.
Monster::Monster() : level(1), max_health(100), current_health(100), damage(5), alive(true), exp_reward(0), gold_reward(0)
{
}

//At the moment, monsters can only be created at level 1 that give 10 exp and 5 gold upon defeat. Health and damage is modular.
//This will be changed to allow more control once the game is a bit more developed.
Monster::Monster(int health, int power) : level(1), current_health(health), max_health(health), damage(power), alive(true), exp_reward(10), gold_reward(5)
{
}

Monster::Monster(int lvl, int health, int power, int g_reward, int e_reward)
{
    level = lvl;
    current_health = health;
    max_health = current_health;
    damage = power;
    alive = true;
    exp_reward = e_reward;
    gold_reward = g_reward;
}

//Very simple public member functions that will return the corresponding value.
int Monster::get_level()
{
    return level;
}

int Monster::get_health()
{
    return current_health;
}

int Monster::get_damage()
{
    return damage;
}

int Monster::get_exp_reward()
{
    return exp_reward;
}

int Monster::get_gold_reward()
{
    return gold_reward;
}

//Used to decrease the health of the monster by value. It calls check_health to prevent the health of a monster from reaching odd values.
void Monster::hurt(int value)
{
    current_health -= value;
    check_health();
}

//If the monster has more than max health, change it to max health. If it is less than 0 health, change it to 0.
void Monster::check_health()
{
    if(current_health <= 0)
    {
        current_health = 0;
        alive = false;//If the health is at 0 or less, set the alive flag to false.
    }
    else if(current_health > max_health)
    {
        current_health = max_health;
    }
}

//Another get value function that returns the state of being of the monster.
bool Monster::check_life()
{
    return alive;
}

//Kill function to forcibly set the alive flag of a monster to zero.
//Might be used if an ability kills regardless of hitpoints.
void Monster::kill()
{
    alive = false;
}

//Random damage generation. Can remove fumbles and reduce critical hit chance with this addition.
int Monster::attack()
{
    srand(time(0));
    int r = (rand() % 2) + 1;
    int r2 = (rand() % (damage / 2)) + 1;
    if(r == 1)
    {
        return damage + r2;
    }
    else
    {
        return damage - r2;
    }
}
