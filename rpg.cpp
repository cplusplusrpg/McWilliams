#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Monster
{
protected:
    int level;
    int current_health;
    int max_health;
    int damage;
    bool alive;
public:
    Monster();
    Monster(int health, int power);
    int get_level();
    int get_health();
    int get_damage();
    int get_exp_reward();
    int get_gold_reward();
    bool check_life();
    void hurt(int value);
    void check_health();
    void kill();
private:
    int exp_reward;
    int gold_reward;
};

class Player: public Monster
{
private:
    int exp;
    int max_exp;
    int gold;
public:
    Player() : Monster(100, 5)
    {
        exp = 0;
        max_exp = 30;
        gold = 0;
    }
    void rest();
    void add_gold(int value);
    void add_exp(int value);
    void levelup();
    void status();
    int get_exp();
    int get_max_exp();
    int get_gold();
};

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

int menu();

int battle_menu();

void turn(Player& Tim, Monster creature);

void display_battle(int Tim_health, int enemy_health);

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

Monster::Monster() : level(1), max_health(25), current_health(25), damage(7), alive(true), exp_reward(10), gold_reward(5)
{
}

Monster::Monster(int health, int power) : level(1), current_health(health), max_health(health), damage(power), alive(true), exp_reward(0), gold_reward(5)
{
}

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

void Monster::hurt(int value)
{
    current_health -= value;
    check_health();
}

void Monster::check_health()
{
    if(current_health <= 0)
    {
        current_health = 0;
        alive = false;
    }
    else if(current_health > max_health)
    {
        current_health = max_health;
    }
}

bool Monster::check_life()
{
    return alive;
}

void Monster::kill()
{
    alive = false;
}
