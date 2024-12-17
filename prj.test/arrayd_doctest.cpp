#include <arrayd/arrayd.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[arrayd] - ctor") {
    ArrayD a(4);

    CHECK(a.Size() == 4);

    a[1] = 10;
    CHECK(a[1] == 10);

    a.Insert(3, 1);
    CHECK(a[3] == 1);
    a.Remove(3);
    CHECK(a[3] != 1);
    CHECK(a.Size() == 4);
    a.Insert(3, 2);
    a.Insert(4, 3);

    a.Resize(10);
}