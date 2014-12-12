#include <vector>
#include <string>

using namespace std;

class Entry {
public:
    Entry(char selection, string description, void (action)(void))
        : m_selection(selection), m_description(description),
            m_action(action) {}

    void perform_action() {
        return m_action();
    }

    string description() {
        return m_description;
    }

    bool matches(char selection) {
        return selection == m_selection;
    }
private:
    char m_selection;
    string m_description;
    void (*m_action)(void);
};

class Menu {
public:
    Menu() : m_entries() {}
    void add_entry(Entry);

    void perform_selection(char selection);
private:
    vector<Entry> m_entries;

};
