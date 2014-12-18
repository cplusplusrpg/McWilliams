//The Monster class. Most member variables are obvious, but some are not, and are explained.
//Member functions are explained in the implementation file: Monster.cpp

#ifndef __MONSTER_H_INCLUDED__
#define __MONSTER_H_INCLUDED__

class Monster
{
protected://These variables will be extended to any derived classes (namely Player).
    int level;
    int current_health;
    int max_health;
    int damage;
    bool alive;//A boolean value to determine status of life or death.
public:
    Monster();
    Monster(int health, int power);
    Monster(int lvl, int health, int power, int g_reward, int e_reward);
    int get_level();
    int get_health();
    int get_damage();
    int get_exp_reward();
    int get_gold_reward();
    bool check_life();
    int attack();
    void hurt(int value);
    void check_health();
    void kill();
private://However, these member variables are unique to monsters, and not any derived classes (*cough* Player *cough*).
    int exp_reward;
    int gold_reward;
};

#endif
