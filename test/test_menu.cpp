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

class FunctorTest : public ::testing::Test {
protected:
    FunctorTest() : 
        entry('a', "Test Entry", new TestFunctor(intList)) {}

    virtual void setUp() {
        intList.push_back(0);
    }

    vector<int> intList;
    Entry entry;
    Menu m;
};

TEST_F(FunctorTest, TestEntry) {
    ASSERT_EQ(0, intList.size());
    entry.perform_action();
    ASSERT_EQ(1, intList.size()) << "Vector should have length 1 after "
        << "perform_action";
    ASSERT_EQ(0, intList[0]);
    ASSERT_EQ("Test Entry", entry.description());
    ASSERT_EQ('a', entry.selection());
}

TEST_F(FunctorTest, Menu) {
    m.add_entry(entry);
    ASSERT_EQ(0, intList.size());

    m.perform_selection('a');
    ASSERT_EQ(1, intList.size()) << "Vector should have length 1 after "
        << "perform_action";
    ASSERT_EQ(0, intList[0]);
}
