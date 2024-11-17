#include <arrayd/arrayd.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <algorithm>
#include <iostream>

TEST_CASE("[arrayd] - ctor") {
    ArrayD<int64_t> a(4, 3);

    a[1] = 10;

    CHECK(!a.empty());
    CHECK(a.size() == 4);
    CHECK(a[0] == 3);
    CHECK(a[1] == 10);

    a.resize(10, 5);

    CHECK(a.size() == 10);
    CHECK(a.front() == 3);
    CHECK(a.back() == 5);
    CHECK(a.capacity() == 10);

    a.push_back(20);

    CHECK(a.back() == 20);
    CHECK(a.size() == 11);

    a.clear();
    CHECK(a.empty());

    a.push_back(10);
    CHECK(a[0] == 10);
    CHECK(a.size() == 1);

    a.insert(0, -1);
    CHECK(a[0] == -1);
    a.erase(0);
    CHECK(a[0] == 10);

    CHECK(*a.begin() == 10);
    CHECK(*a.end() == 10);

    a.push_back(-10);
    a.push_back(100);
    CHECK((*(a.end() - 2)) == -10);
    CHECK(*a.rbegin() == 100);

    a.pop_back();
    CHECK(a[a.size() - 1] == -10);
    a.insert(a.size() - 2, 100);
    std::sort(a.begin(), a.end());
    CHECK(a[0] == -10);
    std::sort(a.rbegin(), a.rend());
    CHECK(a[0] == 100);
}