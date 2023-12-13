#include "mystring.hpp"
#include <iostream>
#include <fstream>
#include <benchmark/benchmark.h>
#include "benchmark_controller.h"


my_str_t* read_file(const char *path, size_t* data_size) {
    // get all data
    std::ifstream inputFile(path);

    if (!inputFile.is_open()) {
        std::cerr << "Error: File could not be opened." << std::endl;
        exit(EXIT_FAILURE);
    }

    my_str_t* data = new my_str_t[1];
    my_str_t word;
    size_t i = 0;
    size_t curr_capacity = 1;
    while(!inputFile.eof() and !inputFile.bad()){
        inputFile >> word;
        data[i] = word;

        if ((i + 1) == curr_capacity) {
            curr_capacity *= 2;
            my_str_t* new_data = new my_str_t[curr_capacity];

            for (size_t j = 0; j < (i + 1); ++j) {
                new_data[j] = data[j];
                *data_size = j;
            }

            delete[] data;
            data = new_data;
        }
        ++i;
    }

    inputFile.close();

    return data;
}

//main task
void word_concat(my_str_t* concat_data, size_t data_size) {
    size_t length = data_size;
    for (size_t i = 0; i < length; ++i) {
        if (concat_data[i].size() != 0 && (i+1) != length) {
            concat_data[i] = concat_data[i] + my_str_t{":"} + concat_data[i+1];
            concat_data[i+1] = my_str_t{};
        }
    }

    // delete whitespaces
    size_t dest = 0;
    for (size_t src = 0; src < data_size; ++src) {
        if (concat_data[src].size() != 0) {
            if (dest != src) {
                concat_data[dest] = concat_data[src];
                concat_data[src] = my_str_t{}; // Clear the source element
            }
            dest++;
        }
    }

}

int main(int argc, char* argv[]) {
    size_t data_size;
     my_str_t* data = read_file(argv[1], &data_size);

    // Word concantenation goes here
    word_concat(data, data_size);

    // write to another file
    std::ofstream MyFile(argv[2]);
    for (size_t i = 0; i < data_size; ++i) {
        if (*(data + i) != "") {
            MyFile << *(data + i);
            MyFile << "\n";
        }
    }
    MyFile.close();

    delete[] data;

    // to run benchmarks uncoment it
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    return 0;
}

