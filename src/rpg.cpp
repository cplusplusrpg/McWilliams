//The core program. This file will pull in all of the other header files and is the main organizer of the Timothy McWilliams project.

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Monster.h"
#include "Player.h"
#include "Item.h"
#include "Inventory.h"
#include "Menu.h"

#include "function.h"

using namespace std;

//The program still needs a lot of work and is quite basic for the time being.
int main()
{
    Player Tim;
    Monster Slime(1, 25, 7, 5, 10);//1 Player and 1 Monster are created.
    Monster Smaug(100, 100000, 25000, 5000000, 100000000);//Smaug, the Dragon from the Hobbit.
    Monster Mushroom(5, 50, 12, 10, 20);
    Monster Hobo(10, 100, 20, 20, 30);
    vector<Monster> monsters;
    monsters.push_back(Slime);
    monsters.push_back(Mushroom);
    monsters.push_back(Hobo);
    char choice;

    cout << "These are the Adventures of Timothy McWilliams. The greatest story ever told." << endl;
    cout << "The fate of Timothy McWilliams depends on you." << endl << endl;
    do
    {
        //choice = menu();//After asking the user what they would like to do,
        Menu *menu = make_menu(Tim, monsters);
        menu->print_menu();
        cin >> choice;
        menu->perform_selection(choice);
    } while(true);
}
