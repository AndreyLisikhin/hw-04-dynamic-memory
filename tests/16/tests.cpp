#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <cstring>
#include <vector>
#include <random>
#include <algorithm>

int* copy(const int* arr, int size);

void gen_vec(std::vector<int>& random_vector){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> size_dist(1000, 5000);
    size_t random_size = size_dist(gen);
    random_vector.resize(random_size);
    std::uniform_int_distribution<int> val_dist(1, 10000);
    std::generate(random_vector.begin(), random_vector.end(), [&]() {
        return val_dist(gen);
    });
}

TEST_CASE("testing createNumber") {
    int cnt = 100;
    std::vector<int> vec;
    for(int i=0;i<cnt;i++){
        gen_vec(vec);
        int* vec_copy = copy(vec.data(), vec.size());
        REQUIRE(vec_copy != nullptr);
        CHECK(std::memcmp(vec_copy, vec.data(), sizeof(int)*vec.size()) == 0);
        delete[] vec_copy;
    }
}
