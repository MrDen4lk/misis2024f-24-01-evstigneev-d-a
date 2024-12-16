#include <arrayt/arrayt.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <algorithm>
#include <iostream>

TEST_CASE("arrayt_doctest") {
    ArrayT<int> a(4);

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

    for (int i = 0; i < a.Size(); i++) {
        std::cout << a[i] << std::endl;
    }
}