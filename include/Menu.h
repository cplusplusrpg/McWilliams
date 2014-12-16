#include <vector>
#include <string>
#include <functional>

using namespace std;

class Functor {
public:
    virtual void call() = 0;
};

class Entry {
public:
    Entry(char selection, string description, Functor* action)
        : m_selection(selection), m_description(description),
            m_action(action) {}

    void perform_action() { m_action->call(); }

    string description() { return m_description; }

    char selection() { return m_selection; }

    bool matches(char selection) { return selection == m_selection; }
private:
    char m_selection;
    string m_description;
    Functor* m_action;
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

