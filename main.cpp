#include "mystring.hpp"
#include <iostream>
#include <fstream>

my_str_t* read_file(const char *path, size_t* data_size) {
    // get all data
    std::ifstream inputFile(path);

    if (!inputFile.is_open()) {
        std::cerr << "Error: File could not be opened." << std::endl;
    }

    my_str_t* data = new my_str_t[1];
    my_str_t word;
    int i = 0;
    int curr_capacity = 1;
    while(!inputFile.eof() and !inputFile.bad()){
        inputFile >> word;
        data[i] = word;

        if ((i + 1) == curr_capacity) {
            curr_capacity *= 2;
            my_str_t* new_data = new my_str_t[curr_capacity];

            for (int j = 0; j < (i + 1); ++j) {
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
    int length = data_size;
    for (int i = 0; i < length; ++i) {
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

    // Visualize output
    for (int i = 0; i < data_size; ++i) {
        std::cout << *(data + i) << std::endl;
    }

    delete[] data;
    return 0;
}