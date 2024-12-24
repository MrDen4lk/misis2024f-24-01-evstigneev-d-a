#include <queuel/queuel.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[queuel] - ctor") {
    QueueL a;
    CHECK(a.IsEmpty());
    a.Push(10);
    CHECK(a.Top() == 10);
    a.Push(20);
    CHECK(a.Top() == 10);
    a.Pop();
    a.Push(30);
    CHECK(a.Top() == 20);
    a.Clear();
    CHECK(a.IsEmpty());
    a.Push(40);
    a.Pop();
    CHECK(a.IsEmpty());
}
