#include <queuea/queuea.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[queuea] - ctor") {
    QueueA a;
    CHECK(a.IsEmpty());

    a.Push(10);
    CHECK(!a.IsEmpty());
    CHECK(a.Top() == 10);
    a.Push(20);
    CHECK(a.Top() == 10);
    a.Pop();
    CHECK(a.Top() == 20);
    a.Clear();
    CHECK(a.IsEmpty());
}