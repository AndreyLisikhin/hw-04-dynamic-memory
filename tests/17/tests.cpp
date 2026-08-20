#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <cstring>
#include <vector>
#include <random>
#include <algorithm>

int* concat(const int* a, int size_a, const int* b, int size_b);

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

TEST_CASE("testing concat") {
    int cnt = 1000;
    std::vector<int> vec1;
    std::vector<int> vec2;
    for(int i=0;i<cnt;i++){
        gen_vec(vec1);
        gen_vec(vec2);
        int* vec_concat = concat(vec1.data(), vec1.size(), vec2.data(), vec2.size());
        REQUIRE(vec_concat != nullptr);
        CHECK(std::memcmp(vec_concat, vec1.data(), sizeof(int)*vec1.size()) == 0);
        CHECK(std::memcmp(vec_concat+vec1.size(), vec2.data(), sizeof(int)*vec2.size()) == 0);
        delete[] vec_concat;
    }
}
