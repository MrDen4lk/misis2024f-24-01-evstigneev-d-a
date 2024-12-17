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

    a.Push(30);
    CHECK(!a.IsEmpty());
    CHECK(a.Top() == 30);

    QueueA b(a);
    CHECK(b.Top() == 30);
    CHECK(!b.IsEmpty());
    b.Clear();
    CHECK(b.IsEmpty());
    CHECK(!a.IsEmpty());

    QueueA c = a;
    CHECK(!c.IsEmpty());
    c.Push(10);
    CHECK(c.Top() == 30);
    c.Pop();
    CHECK(c.Top() == 10);
    c.Pop();
    CHECK(c.IsEmpty());
    CHECK(b.IsEmpty());
}