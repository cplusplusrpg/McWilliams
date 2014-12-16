#include <vector>
#include <string>
#include <functional>

using namespace std;

class Entry {
public:
    Entry(char selection, string description, function<void(void)> action)
        : m_selection(selection), m_description(description),
            m_action(action) {}

    void perform_action() { m_action(); }

    string description() { return m_description; }

    char selection() { return m_selection; }

    bool matches(char selection) { return selection == m_selection; }
private:
    char m_selection;
    string m_description;
    function<void(void)> m_action;
};

class Menu {
public:
    Menu() : m_entries() {}
    void add_entry(Entry);

    void print_menu();
    void perform_selection(char selection);
private:
    vector<Entry> m_entries;

};

