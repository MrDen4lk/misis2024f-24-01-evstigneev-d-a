#include <arrayd/arrayd.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <algorithm>
#include <iostream>

TEST_CASE("[arrayd] - ctor") {
    ArrayD a(4, 3);

    a[1] = 10;

    CHECK(!a.Empty());
    CHECK(a.Size() == 4);
    CHECK(a[0] == 3);
    CHECK(a[1] == 10);

    a.Resize(10, 5);

    CHECK(a.Size() == 10);
    CHECK(a.Front() == 3);
    CHECK(a.Back() == 5);
    CHECK(a.Capacity() == 10);

    a.Push_back(20);

    CHECK(a.Back() == 20);
    CHECK(a.Size() == 11);

    a.Clear();
    CHECK(a.Empty());

    a.Push_back(10);
    CHECK(a[0] == 10);
    CHECK(a.Size() == 1);

    a.Insert(0, -1);
    CHECK(a[0] == -1);
    a.Remove(0);
    CHECK(a[0] == 10);

    CHECK(*a.begin() == 10);
    CHECK(*a.end() == 10);

    a.Push_back(-10);
    a.Push_back(100);
    CHECK((*(a.end() - 2)) == -10);
    CHECK(*a.rbegin() == 100);

    a.Pop_back();
    CHECK(a[a.Size() - 1] == -10);
    a.Insert(a.Size() - 2, 100);
    std::sort(a.begin(), a.end());
    CHECK(a[0] == -10);
    std::sort(a.rbegin(), a.rend());
    CHECK(a[0] == 100);
}