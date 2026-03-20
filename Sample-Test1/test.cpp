#include "gtest/gtest.h"
#include "func.h"

TEST(SortTest, Ascending)
{
    std::vector<int> v = { 5, 3, 2 };
    sortAsc(v);
    EXPECT_EQ(v, (std::vector<int>{2, 3, 5}));
}

TEST(SortTest, Descending)
{
    std::vector<int> v = { 1, 4, 2 };
    sortDesc(v);
    EXPECT_EQ(v, (std::vector<int>{4, 2, 1}));
}

TEST(SumTest, Basic)
{
    std::vector<int> v = { 1, 2, 3 };
    EXPECT_EQ(sumOfElements(v), 6);
}

TEST(UniqueTest, Basic)
{
    std::vector<int> v = { 1, 2, 2, 3 };
    std::vector<int> u;

    removeDuplicates(v, u);

    EXPECT_EQ(u, (std::vector<int>{1, 2, 3}));
}