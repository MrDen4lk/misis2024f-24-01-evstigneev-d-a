#include <arrayd/arrayd.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <algorithm>
#include <iostream>

TEST_CASE("[arrayd] - ctor") {
    ArrayD a(4);
    ArrayD b(4, 10);

    CHECK(b[0] == b[3]);
    CHECK(b[1] == 10);

    CHECK(a.Size() == 4);

    a[1] = 10;
    CHECK(a[1] == 10);
    a.Pop_back();
    CHECK(a.Size() == 3);
    a.Push_back(3);
    CHECK(a[a.Size() - 1] == 3);

    a.Insert(3, 1);
    CHECK(a[3] == 1);
    a.Remove(3);
    CHECK(a[3] != 1);
    CHECK(a.Size() == 4);

    a.Clear();
    CHECK(a.Empty());
}