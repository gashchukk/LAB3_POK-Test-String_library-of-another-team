#ifndef LAB3_STRINGS_USAGE_SHUMSKYI_HASHCHUK_ARNAUTA_BENCHMARK_CONTROLLER_H
#define LAB3_STRINGS_USAGE_SHUMSKYI_HASHCHUK_ARNAUTA_BENCHMARK_CONTROLLER_H
#include <benchmark/benchmark.h>
#include "mystring.hpp"

// append
static void BM_Append(benchmark::State& state) {
    std::string s = "Hello, World!";
    for (auto _ : state) {
        s.append(" New Text");
    }
}
BENCHMARK(BM_Append);

static void BM_MyAppend(benchmark::State& state) {
    my_str_t mystr("Hello, World!");
    for (auto _ : state) {
        mystr.append(" New Text");
    }
}
BENCHMARK(BM_MyAppend);

// find
static void BM_find(benchmark::State& state) {
    std::string s = "Hello, World!";
    for (auto _ : state) {
        s.find("World");
    }
}
BENCHMARK(BM_find);

static void BM_Myfind(benchmark::State& state) {
    my_str_t mystr("Hello, World!");
    for (auto _ : state) {
        mystr.find("World");
    }
}
BENCHMARK(BM_Myfind);

// insert
static void BM_StringInsert(benchmark::State& state) {
    std::string s("Hello, World!");
    for (auto _ : state) {
        s.insert(7, " New Text");
    }
}
BENCHMARK(BM_StringInsert);

static void BM_MyStrInsert(benchmark::State& state) {
    my_str_t mystr("Hello, World!");
    for (auto _ : state) {
        mystr.insert(7, " New Text");
    }
}
BENCHMARK(BM_MyStrInsert);

// clear
static void BM_StringClear(benchmark::State& state) {
    std::string s("Hello, World!");
    for (auto _ : state) {
        s.clear();
    }
}
BENCHMARK(BM_StringClear);

static void BM_MyStrClear(benchmark::State& state) {
    my_str_t mystr("Hello, World!");
    for (auto _ : state) {
        mystr.clear();
    }
}
BENCHMARK(BM_MyStrClear);

// shrink_to_fit
static void BM_StringShrinkToFit(benchmark::State& state) {
    std::string s("Hello, World!");
    s.reserve(1000);  // Reserve extra space
    for (auto _ : state) {
        s.shrink_to_fit();
    }
}
BENCHMARK(BM_StringShrinkToFit);

static void BM_MyStrShrinkToFit(benchmark::State& state) {
    my_str_t mystr("Hello, World!");
    mystr.reserve(1000);  // Reserve extra space
    for (auto _ : state) {
        mystr.shrink_to_fit();
    }
}
BENCHMARK(BM_MyStrShrinkToFit);

// swap
static void BM_StringSwap(benchmark::State& state) {
    std::string s1("Hello, World!");
    std::string s2("New Text");
    for (auto _ : state) {
        s1.swap(s2);
    }
}
BENCHMARK(BM_StringSwap);

static void BM_MyStrSwap(benchmark::State& state) {
    my_str_t mystr1("Hello, World!");
    my_str_t mystr2("New Text");
    for (auto _ : state) {
        mystr1.swap(mystr2);
    }
}
BENCHMARK(BM_MyStrSwap);

// size
static void BM_StringSize(benchmark::State& state) {
    std::string s("Hello, World!");
    for (auto _ : state) {
        size_t size = s.size();
    }
}
BENCHMARK(BM_StringSize);

static void BM_MyStrSize(benchmark::State& state) {
    my_str_t mystr("Hello, World!");
    for (auto _ : state) {
        size_t size = mystr.size();
    }
}
BENCHMARK(BM_MyStrSize);


#endif //LAB3_STRINGS_USAGE_SHUMSKYI_HASHCHUK_ARNAUTA_BENCHMARK_CONTROLLER_H
