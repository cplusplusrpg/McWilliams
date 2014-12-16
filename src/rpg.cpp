//The core program. This file will pull in all of the other header files and is the main organizer of the Timothy McWilliams project.

#include <iostream>
#include <vector>
#include "Monster.h"
#include "Player.h"
#include "function.h"
#include "Item.h"
#include "Inventory.h"

using namespace std;

//The program still needs a lot of work and is quite basic for the time being.
int main()
{
    Player Tim;
    Monster Slime;//1 Player and 1 Monster are created.
    int choice;

    cout << endl << "*********************************************************************************" << endl;
    cout << "*                                                                               *" << endl;
    cout << "* These are the Adventures of Timothy McWilliams. The greatest story ever told. *" << endl;
    cout << "*                The fate of Timothy McWilliams DEPENDS ON YOU.                 *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*********************************************************************************" << endl << endl;
    do
    {
        choice = menu();//After asking the user what they would like to do,
        
        if(choice == 1)
        {
            turn(Tim, Slime);//Performs an appropriate action.
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
            cout << "Timothy takes a blanket and pillow and takes a quick 5-minute nap." << endl;
            cout << "Tim now has " << Tim.get_health() << " health." << endl;
        }
    } while(choice < 5 and choice > 0);
	return 0;
}
