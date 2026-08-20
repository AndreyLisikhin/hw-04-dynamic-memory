#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

int* createNumber(int value);
void clear_number(int* p);
TEST_CASE("testing createNumber") {
    int* a = createNumber(0);
    int* b = createNumber(-100);
    int* c = createNumber(123456);

    REQUIRE(a != nullptr);
    REQUIRE(b != nullptr);
    REQUIRE(c != nullptr);

    CHECK(*a == 0);
    CHECK(*b == -100);
    CHECK(*c == 123456);

    clear_number(a);
    clear_number(b);
    clear_number(c);
}
