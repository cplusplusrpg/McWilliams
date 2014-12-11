// Quick question: Does the store have to be THIS LONG?! T-T
dgdgd
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void store(vector<string>& inventory, vector<string>& potions);

int main()
{
    vector<string> a;
    vector<string> potions;
    store(a, potions);
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
        while (ans <= 0 || ans > 5)
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
        switch(ans)
        {
            case 1:
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
                if (option1 == 1)
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
                if (option1 == 2)
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
                if (option1 == 3)
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
                if (option1 == 4)
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
                if (option1 == 5)
                {
                    break;
                }
            case 2:
                cout << "Choose a weapon!" << endl;
                cout << "1) Beginner Sword: Damage(2), Durability(100), Cost(50 gold)" << endl;
                cout << "2) Claymore: Damage(10), Durability(300), Cost(150 gold)" << endl;
                cout << "3) Gladius: Damage(20), Durability(400), Cost(500 gold)" << endl;
                cout << "4) Soul Eater: Damage(100), Durability(1000), Cost(1000 gold)" << endl;
                cout << "5) Dance of Flames: Damage(200), Durability(2000), Cost(10000 gold)" << endl;
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
                    cout << "Successfully purchased 1 Dance of Flames, 10000 gold will now be taken out of your account." << endl;
                    inventory.push_back("Dance of Flames");
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
            case 3:
                
            case 4:
                string potion;
                cout << "Type in 1 to sell a potion, 2 to sell an item, or 3 to return to the menu: ";
                cin >> option4;
                while (option4 <= 0 || option4 > 3)
                {
                    cout << "Invalid option." << endl;
                    cout << "Type in 1-3 for the options above: ";
                    cout << option4;
                }
                if (option4 == 1)
                {
                    string potion, potion1, potion2;
                    int count = 0;
                    cout << "What potion would you like to sell? ";
                    cin >> potion1 >> potion2;
                    potion = potion1 + " " + potion2;
                    for (unsigned int i = 0; i < potions.size(); i++)
                    {

                        if (!(potion == potions[i]))
                        {
                            count++;
                        }
                        if (potion == potions[i])
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
                    if (count == 0 || count == 4)
                    {
                        cout << "There is no such potion in your inventory." << endl;
                        cout << "Returning to the menu." << endl;
                    }
                }
                if (option4 == 2)
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
                    if (ans == 1)
                    {
                        string name;
                        cout << "Type in the first part of the name of the weapon you would like to sell "
                        << "(note: with weapons with just one name, type just that one name): ";
                        cin >> name;
                        
                    }
                    if (ans == 2)
                    {
                        
                    }
                }
        }
    } while (ans != 5);
}
