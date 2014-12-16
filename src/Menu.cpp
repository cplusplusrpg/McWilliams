
#include <iostream>

#include "Menu.h"

using namespace std;

void Menu::add_entry(Entry entry) {
    m_entries.push_back(entry);
}

void Menu::perform_selection(char selection) {
    for (vector<Entry>::iterator e = m_entries.begin(); e != m_entries.end(); e++) {
        if (e->matches(selection)) {
            e->perform_action();
            return;
        }
    }
}

void Menu::print_menu() {
    for (vector<Entry>::iterator e = m_entries.begin(); e != m_entries.end(); e++) {
        cout << e->selection() << ") " << e->description() << endl;
    }
}
