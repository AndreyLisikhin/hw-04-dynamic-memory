#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <cstring>
#include <vector>
#include <random>

int* erase(const int* arr, int size, int index){
    int* newarr= new int[size-1];
    for(int i=0;i<index;i++){
        newarr[i] = arr[i];
    }
    for(int i=index+1;i<size;i++){
        newarr[i-1] = arr[i];
    }
    return newarr;
}

std::random_device rd;
std::mt19937& get_gen(){
    static std::mt19937 gen(rd());
    return gen;
}
std::uniform_int_distribution<size_t> size_dist(1000, 5000);
std::uniform_int_distribution<int> val_dist(1, 10000);

void gen_vec(std::vector<int>& random_vector){
    size_t random_size = size_dist(get_gen());
    random_vector.resize(random_size);
    std::generate(random_vector.begin(), random_vector.end(), [&]() {
        return val_dist(get_gen());
    });
}

TEST_CASE("testing erase") {
    int cnt = 10000;
    std::vector<int> vec;
    for(int i=0;i<cnt;i++){
        gen_vec(vec);
        int erase_index = val_dist(get_gen())%vec.size();
        int* vec_erased = erase(vec.data(), vec.size(), erase_index);
        REQUIRE(vec_erased != nullptr);
        if(erase_index!=0) CHECK(std::memcmp(vec_erased, vec.data(), sizeof(int)*erase_index) == 0);
        if(erase_index!=vec.size()-1) CHECK(std::memcmp(vec_erased+erase_index, vec.data()+erase_index+1, sizeof(int)*(vec.size() - erase_index-1)) == 0);
        delete[] vec_erased;
    }
}
