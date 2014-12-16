#include <gtest/gtest.h>
#include "Menu.h"


class TestFunctor : public Functor {
public:
    TestFunctor(vector<int>& ints) : m_ints(ints) {}
    void call() {
        m_ints.push_back(0);
    }
private:
    vector<int>& m_ints;
};

TEST(EntryTest, TestPerform) {
    vector<int> intList;
    ASSERT_EQ(intList.size(), 0);
    Entry e('a', "Test Entry", new TestFunctor(intList));
    ASSERT_EQ(0, intList.size());
    e.perform_action();
    ASSERT_EQ(1, intList.size()) << "Vector should have length 1 after "
        << "perform_action";
    ASSERT_EQ("Test Entry", e.description());
    ASSERT_EQ('a', e.selection());
}

TEST(MenuTest, TestPerform) {
    vector<int> intList;
    ASSERT_EQ(intList.size(), 0);
    Entry e('a', "Test Entry", new TestFunctor(intList));
    Menu m;
    m.add_entry(e);
    ASSERT_EQ(0, intList.size());

    m.perform_selection('a');
    ASSERT_EQ(1, intList.size()) << "Vector should have length 1 after "
        << "perform_action";
    ASSERT_EQ("Test Entry", e.description());
    ASSERT_EQ('a', e.selection());
}
