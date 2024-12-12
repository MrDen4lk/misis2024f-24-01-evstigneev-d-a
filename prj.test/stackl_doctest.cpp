#include <stackl/stackl.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[stackl] - ctor") {
    StackL a;

    CHECK(a.IsEmpty());

    a.Push(10);
    CHECK(a.Top() == 10);

    a.Pop();
    CHECK(a.IsEmpty());

    a.Push(1);
    a.Push(2);
    a.Push(3);
    a.Push(4);
    a.Push(5);

    CHECK(a.Top() == 5);
    a.Pop();
    CHECK(a.Top() == 4);
    CHECK(a.Top() == 4);
    a.Pop();
    CHECK(a.Top() == 3);
    a.Pop();
    CHECK(a.Top() == 2);
    a.Pop();
    CHECK(a.Top() == 1);
    a.Pop();

    CHECK(a.IsEmpty());

    a.Push(1);
    a.Push(2);
    a.Push(3);
    a.Push(4);
    a.Push(5);

    CHECK(a.Top() == 5);

    StackL b(a);
    CHECK(b.Top() == 5);
    b.Clear();
    CHECK(b.IsEmpty());
    b.Push(1);
    b.Push(2);
    CHECK(b.Top() == 2);
    CHECK(a.Top() == 5);

    StackL c = b;
    CHECK(c.Top() == 2);
    c.Clear();
    CHECK(c.IsEmpty());
}