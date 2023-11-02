#ifndef LAB1_CSTRINGMYSTRING_HPP
#define LAB1_CSTRINGMYSTRING_HPP
#include <iostream>
#include <cstring>
#include <stdexcept>
using std::size_t;
class my_str_t {
private:
    char *data_m;
    size_t capacity_m;
    size_t size_m;

public:
    my_str_t(); // Implemented by team shumskyi_hashchuk_arnauta
    my_str_t(size_t size, char initial);
    explicit my_str_t(const char* cstr);
    explicit my_str_t(const std::string& str);
    my_str_t(const my_str_t& mystr);
    my_str_t(my_str_t&& other) noexcept;
    my_str_t& operator=(my_str_t&& other) noexcept;
    my_str_t& operator=(const my_str_t& mystr);
    void print();
    void swap(my_str_t& other) noexcept;
    char& operator[](size_t idx);
    const char& operator[](size_t idx) const;
    char& at(size_t idx);
    [[nodiscard]] const char& at(size_t idx) const;
    void reserve(size_t new_capacity);
    void shrink_to_fit();
    void resize(size_t new_size, char new_char = ' ');
    void clear();
    void insert(size_t idx, const my_str_t& str);
    void insert(size_t idx, char c);
    void insert(size_t idx, const char* cstr);
    void remove_trailing_newline();
    void append(const my_str_t& str);
    void append(char c);
    void append(const char* cstr);
    void erase(size_t begin, size_t size);
    [[nodiscard]] size_t size() const noexcept;
    [[nodiscard]] size_t capacity() const noexcept;
    [[nodiscard]] const char* c_str() const;
    static constexpr size_t not_found = -1;
    size_t find(char c, size_t idx = 0);
    size_t find(const std::string& str, size_t idx = 0);
    size_t find(const char* cstr, size_t idx = 0);
    my_str_t substr(size_t begin, size_t size);
    my_str_t operator+(const my_str_t& str);
    my_str_t operator+(char c);
    my_str_t operator+(const char* cstr);
    my_str_t& operator+=(const my_str_t& str);
    my_str_t& operator+=(char c);
    my_str_t& operator+=(const char* cstr);
    my_str_t operator*(int mul);
    my_str_t &operator*=(int mul);
    ~my_str_t();
};

std::ostream& operator<<(std::ostream& stream , const my_str_t& str);
std::istream& operator>>(std::istream& stream , my_str_t& str);
std::istream& readline(std::istream& stream, my_str_t& str);

size_t getMin(const my_str_t &str1, const my_str_t &str2);
size_t getMinCstr(const my_str_t &str1, const char* cstr2);
bool operator==(const my_str_t& str1, const my_str_t& str2);
bool operator!=(const my_str_t& str1, const my_str_t& str2);
bool operator> (const my_str_t& str1, const my_str_t& str2);
bool operator>=(const my_str_t& str1, const my_str_t& str2);
bool operator< (const my_str_t& str1, const my_str_t& str2);
bool operator<=(const my_str_t& str1, const my_str_t& str2);
bool operator==(const my_str_t& str1, const char* cstr2);
bool operator!=(const my_str_t& str1, const char* cstr2);
bool operator> (const my_str_t& str1, const char* cstr2);
bool operator>=(const my_str_t& str1, const char* cstr2);
bool operator< (const my_str_t& str1, const char* cstr2);
bool operator<=(const my_str_t& str1, const char* cstr2);
bool operator==(const char* cstr1, const my_str_t& str2);
bool operator!=(const char* cstr1, const my_str_t& str2);
bool operator> (const char* cstr1, const my_str_t& str2);
bool operator>=(const char* cstr1, const my_str_t& str2);
bool operator< (const char* cstr1, const my_str_t& str2);
bool operator<=(const char* cstr1, const my_str_t& str2);

my_str_t operator+(const char* cstr, const my_str_t& str);


#endif //LAB1_CSTRINGMYSTRING_HPP
