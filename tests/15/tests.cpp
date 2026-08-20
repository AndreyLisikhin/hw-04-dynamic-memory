#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

int* createArray(int size);

void clear_array(int* p);

TEST_CASE("testing createNumber") {
    int as = 20;
    int bs = 1e8;
    int* a = createArray(as);
    int* b = createArray(bs);
    REQUIRE(a != nullptr);
    REQUIRE(b != nullptr);
    for(int i=0;i<as;i++){
        CHECK(a[i]==0);
    }
    for(int i=0;i<bs;i++){
        CHECK(b[i]==0);
    }

    clear_array(a);
    clear_array(b);
}
