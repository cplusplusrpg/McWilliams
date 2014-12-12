// WHY IS THIS SO LONG T_T
// The store inventory, though long, will be optimized very soon.

#include <iostream>
#include <vector>
#include <string>
#include "Monster.h"
#include "Player.h"
#include "function.h"
#include "Item.h"

using namespace std;

void store(vector<string>& inventory, vector<string>& potions); // The store
void show_inventory(vector<string> inventory, vector<string> potions); // Showing the player's inventory
void show_inventory(vector<string> inventory, vector<string> potions)
{
    cout << "This is your current inventory." << endl;
    cout << "***********" << endl;
    cout << "*Inventory*" << endl;
    cout << "***********" << endl;
    for (unsigned int i = 0; i < potions.size(); i++)
    {
        cout << potions[i] << endl;
    }
    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i] << endl;
    }
}

int main()
{
    vector<string> inventory;
    vector<string> potions;
    store(inventory, potions);
    show_inventory(inventory, potions);
    return 0;
}

void store(vector<string>& inventory, vector<string>& potions)
{
    int ans, option1, option2, option3, option4, quantity;
    cout << "Welcome to the shop." << endl;
    do
    {
        cout << "Type in: " << endl;
        cout << "1 to purchase potions," << endl;
        cout << "2 to purchase weapons," << endl;
        cout << "3 to purchase armor," << endl;
        cout << "4 to sell items from your inventory," << endl;
        cout << "5 to leave the shop: ";
        cin >> ans;
        while (ans <= 0 || ans > 5) // If option is invalid
        {
            cout << "No such option is available." << endl;
            cout << "Type in: " << endl;
            cout << "1 to purchase potions," << endl;
            cout << "2 to purchase weapons," << endl;
            cout << "3 to purchase armor," << endl;
            cout << "4 to sell items from your inventory," << endl;
            cout << "5 to leave the shop: ";
            cin >> ans;
        }
        switch(ans) // Switch statement
        {
            case 1: // For the potions shop
                cout << "Choose a potion!" << endl;
                cout << "1)  Basic Potion (Recovers 30 HP)   10 gold each" << endl;
                cout << "2)  Much-Higher-Than-Basic Potion (Recovers 50 HP)  20 gold each" << endl;
                cout << "3)  Intermediate Potion (Recovers 100 HP)   40 gold each" << endl;
                cout << "4)  Advanced Potion (Recovers full HP)  100 gold each" << endl;
                cout << "or type in 5 to exit: ";
                cin >> option1;
                while (option1 <= 0 || option1 > 5)
                {
                    cout << "Not a valid option." << endl;
                    cout << "Choose from one of the four options above: ";
                    cin >> option1;
                }
                if (option1 == 1) // For Basic Potion
                {
                    cout << "How many would you like to buy? ";
                    cin >> quantity;
                    // Put a while loop here for while the total price is greater than the amount of gold you currently have
                    for (int i = 0; i < quantity; i++)
                    {
                        potions.push_back("Basic Potion");
                    }
                    cout << quantity << " Basic Potions purchased, " << quantity * 10 << " gold will now be taken out of your account." << endl;
                    // Put something here about losing gold.
                    break;
                }
                if (option1 == 2) // For Much-Higher-Than-Basic potion
                {
                    cout << "How many would you like to buy? ";
                    cin >> quantity;
                    // Put a while loop here for while the total price is greater than the amount of gold you currently have
                    for (int i = 0; i < quantity; i++)
                    {
                        potions.push_back("Much-Higher-Than-Basic Potion");
                    }
                    cout << quantity << " Much-Higher-Than-Basic Potions purchased, " << quantity * 20 << " gold will now be taken out of your account." << endl;
                    // Put something here about losing gold.
                    break;
                }
                if (option1 == 3) // For Intermediate potion
                {
                    cout << "How many would you like to buy? ";
                    cin >> quantity;
                    // Put a while loop here for while the total price is greater than the amount of gold you currently have
                    for (int i = 0; i < quantity; i++)
                    {
                        potions.push_back("Intermediate Potion");
                    }
                    cout << quantity << " Intermediate Potions purchased, " << quantity * 40 << " gold will now be taken out of your account." << endl;
                    // Put something here about losing gold.
                    break;
                }
                if (option1 == 4) // For advanced potion
                {
                    cout << "How many would you like to buy? ";
                    cin >> quantity;
                    // Put a while loop here about total price being greater than the amount of gold you currently have
                    for (int i = 0; i < quantity; i++)
                    {
                        potions.push_back("Advanced Potion");
                    }
                    cout << quantity << " Advanced Potions purchased, " << quantity * 100 << " gold will now be taken out of your account." << endl;
                    // Put something here about losing gold.
                    break;
                }
                if (option1 == 5) // To go back to the menu
                {
                    break;
                }
            case 2: // The weapons shop
                cout << "Choose a weapon!" << endl;
                cout << "1) Beginner Sword: Damage(2), Durability(100), Cost(50 gold)" << endl;
                cout << "2) Claymore: Damage(10), Durability(300), Cost(150 gold)" << endl;
                cout << "3) Gladius: Damage(20), Durability(400), Cost(500 gold)" << endl;
                cout << "4) Soul Eater: Damage(100), Durability(1000), Cost(1000 gold)" << endl;
                cout << "5) Flame Dance: Damage(200), Durability(2000), Cost(10000 gold)" << endl;
                cout << "6) Heartless Crusader: Damage(400), Durability(3500), Cost(100000 gold)" << endl;
                cout << "7) Eternal Harmony: Damage(600), Durability(4000), Cost(500000 gold)" << endl;
                cout << "8) Elucidator: Damage(1000), Durability(5000), Cost(1000000 gold)" << endl;
                cout << "or type in -1 to return to the menu: ";
                cin >> option2;
                if (option2 == -1)
                {
                    break;
                }
                while (option2 <= 0 || option2 > 8)
                {
                    cout << "Invalid option." << endl;
                    cout << "Type in options 1-8 for the items above, or -1 to exit: ";
                    cin >> option2;
                    if (option2 == -1)
                    {
                        break;
                    }
                }
                if (option2 == 1)
                {
                    // Say something here about not having enough gold
                    cout << "Successfully purchased 1 Beginner Sword, 50 gold will now be taken out of your account." << endl;
                    inventory.push_back("Beginner Sword");
                    // Deduct gold from the account
                    break;
                }
                if (option2 == 2)
                {
                    // Say something here about not having enough gold
                    cout << "Successfully purchased 1 Claymore, 150 gold will now be taken out of your account." << endl;
                    inventory.push_back("Claymore");
                    // Deduct gold from the account
                    break;
                }
                if (option2 == 3)
                {
                    // Say something here about not having enough gold
                    cout << "Successfully purchased 1 Gladius, 500 gold will now be taken out of your account." << endl;
                    inventory.push_back("Gladius");
                    // Deduct gold from the account
                    break;
                }
                if (option2 == 4)
                {
                    // Say something here about not having enough gold
                    cout << "Successfully purchased 1 Soul Eater, 1000 gold will now be taken out of your account." << endl;
                    inventory.push_back("Gladius");
                    // Deduct gold from the account
                    break;
                }
                if (option2 == 5)
                {
                    // Say something here about not having enough gold
                    cout << "Successfully purchased 1 Flame Dance, 10000 gold will now be taken out of your account." << endl;
                    inventory.push_back("Flame Dance");
                    // Deduct gold from the acoount
                    break;
                }
                if (option2 == 6)
                {
                    // Say something here about not having enough gold
                    cout << "Successfully purchased 1 Heartless Crusader, 100000 gold will now be taken out of your account." << endl;
                    inventory.push_back("Heartless Crusader");
                    // Deduct gold from the account
                    break;
                }
                if (option2 == 7)
                {
                    // Say something here about not having enough gold.
                    cout << "Successfully purchased 1 Eternal Harmony, 500000 gold will now be taken out of your account." << endl;
                    inventory.push_back("Eternal Harmony");
                    // Deduct gold from the account
                    break;
                }
                if (option2 == 8)
                {
                    // Say something here about not having enough gold
                    cout << "Congrats on purchasing the most godly sword in this game! 1000000 gold will now be taken out of your account." << endl;
                    inventory.push_back("Elucidator");
                    // Deduct gold from the account
                    break;
                }
            case 3: // The armor shop
                int a;
                cout << "Choose some armor!" << endl;
                cout << "1) Beginner Armor:     Defense(2)      Durability(100)     Cost(50 gold)" << endl;
                cout << "2) Ebon Armor:         Defense(10)     Durability(300)     Cost(150 gold)" << endl;
                cout << "3) Admin's Armor:      Defense(20)     Durability(400)     Cost(500 gold)" << endl;
                cout << "4) Phantom's Armor:    Defense(100)    Durability(1000)    Cost(1000 gold)" << endl;
                cout << "5) Memory Loss:        Defense(400)    Durability(4000)    Cost(250000 gold)" << endl;
                cout << "6) Frozen Hell:        Defense(800)    Durability(8000)    Cost(750000 gold)" << endl;
                cout << "7) Hero's Redemption:  Defense(1200)   Durability(10000)   Cost(1000000 gold)" << endl;
                cout << "or type in -1 to return to the menu: ";
                cin >> a;
                while (a == 0 || a < -1 || a > 7)
                {
                    cout << "Invalid option." << endl;
                    cout << "Type in options 1-7 or -1: ";
                    cin >> a;
                }
                if (a == 1)
                {
                    // Say something here about not having enough gold
                    cout << "Successfully purchased 1 Beginner Armor, 50 gold will now be taken out of your account." << endl;
                    inventory.push_back("Beginner Armor");
                    // Deduct gold from the account
                    break;
                }
                if (a == 2)
                {
                    // Say something here about not having enough gold
                    cout << "Successfully purchased 1 Ebon Armor, 150 gold will now be taken out of your account." << endl;
                    inventory.push_back("Ebon Armor");
                    // Deduct gold from the account
                    break;
                }
                if (a == 3)
                {
                    // Say something here about not having enough gold
                    cout << "Successfully purchased 1 Admin's Armor, 500 gold will now be taken out of your account." << endl;
                    inventory.push_back("Admin's Armor");
                    // Deduct gold from the account
                    break;
                }
                if (a == 4)
                {
                    // Say something here about not having enough gold
                    cout << "Successfully purchased 1 Phantom's Armor, 1000 gold will now be taken out of your account." << endl;
                    inventory.push_back("Phantom's Armor");
                    // Deduct gold from the account
                    break;
                }
                if (a == 5)
                {
                    // Say something here about not having enough gold
                    cout << "Successfully purchased 1 Memory Loss, 250000 gold will now be taken out of your account." << endl;
                    inventory.push_back("Memory Loss");
                    // Deduct gold from the account
                    break;
                }
                if (a == 6)
                {
                    // Say something here about not having enough gold
                    cout << "Successfully purchased 1 Frozen Hell, 750000 gold will now be taken out of your account." << endl;
                    inventory.push_back("Frozen Hell");
                    // Deduct gold from the account
                    break;
                }
                if (a == 7)
                {
                    // Say something here about not having enough gold
                    cout << "Congrats on purchasing the most god-like armor in the game! 1000000 gold will now be taken out of your account." << endl;
                    inventory.push_back("Hero's Redemption");
                    // Deduct gold from the account
                    break;
                }
            case 4: // For selling items
                cout << "Type in 1 to sell a potion, 2 to sell an item, or 3 to return to the menu: ";
                cin >> option4;
                while (option4 <= 0 || option4 > 3)
                {
                    cout << "Invalid option." << endl;
                    cout << "Type in 1-3 for the options above: ";
                    cout << option4;
                }
                if (option4 == 1) // To sell a potion
                {
                    string potion, potion1, potion2;
                    int count = 0;
                    cout << "What potion would you like to sell? ";
                    cin >> potion1 >> potion2; // Since each potion has two words, take each word as input
                    potion = potion1 + " " + potion2; // and combine them together
                    for (unsigned int i = 0; i < potions.size(); i++) // Search through the potions vector to find a match
                    {
                        if (!(potion == potions[i])) // If there is no potion match, add 1 to count.
                        {
                            count++;
                        }
                        if (potion == potions[i]) // If there is a match
                        {
                            if (potion == "Basic Potion")
                            {
                                cout << "One basic potion has been sold for 5 gold." << endl;
                                // Add the gold into account.
                                potions[i] = " ";
                                break;
                            }
                            if (potion == "Much-Higher-Than-Basic Potion")
                            {
                                cout << "One Much-Higher-Than-Basic potion has been sold for 10 gold." << endl;
                                // Add the gold into account.
                                potions[i] = " ";
                                break;
                            }
                            if (potion == "Intermediate Potion")
                            {
                                cout << "One Intermediate Potion has been sold for 20 gold." << endl;
                                // Add the gold into account.
                                potions[i] = " ";
                                break;
                            }
                            if (potion == "Advanced Potion")
                            {
                                cout << "One Advanced Potion has been sold for 50 gold." << endl;
                                // Add the gold into account.
                                potions[i] = " ";
                                break;
                            }
                        }
                    }
                    if (count == 0 || count == 4) // For cases if there is no such potion in the inventory
                    {
                        cout << "There is no such potion in your inventory." << endl;
                        cout << "Returning to the menu." << endl;
                    }
                }
                if (option4 == 2) // For selling items
                {
                    int ans;
                    cout << "Type in 1 to sell a weapon or 2 to sell armor: ";
                    cin >> ans;
                    while (ans != 1 && ans != 2)
                    {
                        cout << "Invalid option." << endl;
                        cout << "Type in 1 to sell a weapon or 2 to sell armor: ";
                        cin >> ans;
                    }
                    if (ans == 1) // For selling weapons
                    {
                        int ans, count = 0;
                        string name, name1, name2;
                        cout << "Type in 1 for a one-named sword, or 2 for a two-named sword: ";
                        cin >> ans;
                        while (ans <= 0 || ans > 2)
                        {
                            cout << "Not a valid option." << endl;
                            cout << "Type in 1 or 2: ";
                            cin >> ans;
                        }
                        if (ans == 1)
                        {
                            cout << "Enter the name: ";
                            cin >> name;
                        }
                        if (ans == 2)
                        {
                            cout << "Enter the name: ";
                            cin >> name1 >> name2;
                            name = name1 + " " + name2;
                        }
                        for (unsigned int i = 0; i < inventory.size(); i++)
                        {
                            if (!(name == inventory[i]))
                            {
                                count++;
                            }
                            if (name == inventory[i])
                            {
                                if (inventory[i] == "Beginner Sword")
                                {
                                    cout << "One Beginner Sword has been sold for 25 gold." << endl;
                                    // Add the gold into account.
                                    inventory[i] = " ";
                                    break;
                                }
                                if (inventory[i] == "Claymore")
                                {
                                    cout << "One Claymore has been sold for 75 gold." << endl;
                                    // Add the gold into account.
                                    inventory[i] = " ";
                                    break;
                                }
                                if (inventory[i] == "Gladius")
                                {
                                    cout << "One Gladius has been sold for 250 gold." << endl;
                                    // Add the gold into account.
                                    inventory[i] = " ";
                                    break;
                                }
                                if (inventory[i] == "Soul Eater")
                                {
                                    cout << "One Soul Eater has been sold for 500 gold." << endl;
                                    // Add the gold into account.
                                    inventory[i] = " ";
                                    break;
                                }
                                if (inventory[i] == "Flame Dance")
                                {
                                    cout << "One Flame Dance has been sold for 5000 gold." << endl;
                                    // Add the gold into account.
                                    inventory[i] = " ";
                                    break;
                                }
                                if (inventory[i] == "Heartless Crusader")
                                {
                                    cout << "One Heartless Crusader has been sold for 50000 gold." << endl;
                                    // Add the gold into account.
                                    inventory[i] = " ";
                                    break;
                                }
                                if (inventory[i] == "Eternal Harmony")
                                {
                                    cout << "One Eternal Harmony has been sold for 250000 gold." << endl;
                                    // Add the gold into account.
                                    inventory[i] = " ";
                                    break;
                                }
                                if (inventory[i] == "Elucidator")
                                {
                                    cout << "One Elucidator has been sold for 500000 gold." << endl;
                                    // Add the gold into account.
                                    inventory[i] = " ";
                                    break;
                                }
                            }
                        }
                        if (count == inventory.size())
                        {
                            cout << "There is no such weapon in your inventory." << endl;
                            cout << "Returning to the menu." << endl;
                        }
                    }
                    if (ans == 2) // For selling armor
                    {
                        int count = 0;
                        string armor1, armor2, armor;
                        cout << "Type in the name of the armor you wish to sell: ";
                        cin >> armor1 >> armor2;
                        armor = armor1 + " " + armor2;
                        for (unsigned int i = 0; i < inventory.size(); i++)
                        {
                            if (!(armor == inventory[i]))
                            {
                                count++;
                            }
                            if (armor == inventory[i])
                            {
                                if (inventory[i] == "Beginner Armor")
                                {
                                    cout << "One Beginner Armor has been sold for 25 gold." << endl;
                                    // Add gold into account.
                                    inventory[i] = " ";
                                    break;
                                }
                                if (inventory[i] == "Ebon Armor")
                                {
                                    cout << "One Ebon Armor has been sold for 75 gold." << endl;
                                    // Add gold into account.
                                    inventory[i] = " ";
                                    break;
                                }
                                if (inventory[i] == "Admin's Armor")
                                {
                                    cout << "One Admin's Armor has been sold for 250 gold." << endl;
                                    // Add gold into account.
                                    inventory[i] = " ";
                                    break;
                                }
                                if (inventory[i] == "Phantom's Armor")
                                {
                                    cout << "One Phantom's Armor has been sold for 500 gold." << endl;
                                    // Add gold into account.
                                    inventory[i] = " ";
                                    break;
                                }
                                if (inventory[i] == "Memory Loss")
                                {
                                    cout << "One Memory Loss has been sold for 125000 gold." << endl;
                                    // Add gold into account.
                                    inventory[i] = " ";
                                    break;
                                }
                                if (inventory[i] == "Frozen Hell")
                                {
                                    cout << "One Frozen Hell has been sold for 375000 gold." << endl;
                                    // Add gold into account.
                                    inventory[i] = " ";
                                    break;
                                }
                                if (inventory[i] == "Hero's Redemption")
                                {
                                    cout << "One Hero's Redemption has been sold for 500000 gold." << endl;
                                    // Add gold into account.
                                    inventory[i] = " ";
                                    break;
                                }
                            }
                        }
                        if (count == inventory.size())
                        {
                            cout << "No such armor exists." << endl;
                            cout << "Returning to the menu." << endl;
                        }
                    }
                }
        }
    } while (ans != 5); // Do-while loop will repeat until the user exits the shop (aka ans == 5)
}
