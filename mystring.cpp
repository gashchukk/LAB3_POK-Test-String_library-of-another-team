// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstring>
#include "mystring.hpp"

// Implemented by team shumskyi_hashchuk_arnauta
my_str_t::my_str_t() {
    size_m = 0;
    capacity_m = 1;
    data_m = new char[capacity_m];
    data_m[size_m] = '\0';
}

//
my_str_t::my_str_t (size_t size, char initial):
        capacity_m(size + 16 - size % 16), size_m(size), data_m(new char[size + 16 - size % 16])
{
    for(size_t i = 0; i < size; ++i)
    {
        data_m[i] = initial;
    }
    data_m[size] = '\0';
}
//
my_str_t::my_str_t(my_str_t&& other) noexcept:
        data_m(other.data_m), capacity_m(other.capacity_m), size_m(other.size_m) {
    other.data_m = nullptr;
    other.capacity_m = 0;
    other.size_m = 0;
}
//
my_str_t& my_str_t::operator=(my_str_t&& other) noexcept{
    if (this != &other){
        clear();
        data_m = other.data_m;
        capacity_m = other.capacity_m;
        size_m = other.size_m;
        other.data_m = nullptr;
        other.capacity_m = 0;
        other.size_m = 0;
    }
    return *this;
}
//
void my_str_t::print(){
    for(size_t i = 0; i < size_m; ++i){
        std::cout << data_m[i];
    }
    std::cout << std::endl;
}

//
my_str_t::my_str_t (const char* cstr)
{
    size_t cstr_len = strlen(cstr);
    capacity_m = cstr_len + 16 - cstr_len % 16;
    size_m = cstr_len;
    data_m = new char[capacity_m+1];
    for (size_t i = 0; i <= size_m; i++){
        data_m[i] = cstr[i];
    }
}


//
my_str_t::my_str_t (const std::string& str):
        capacity_m(str.length() + 16 - str.length() % 16), size_m(str.length()), data_m(new char[str.length() + 16 - str.length() % 16])
{
    for(size_t i = 0; i < size_m; ++i){
        data_m[i] = str[i];
    }
    data_m[size()] = '\0';
}

//
my_str_t::my_str_t (const my_str_t& mystr):
        capacity_m(mystr.size() + 16 - mystr.size()%16), size_m(mystr.size()), data_m(new char[mystr.size() + 16 - mystr.size()%16])
{
    for (size_t i = 0; i < size_m; i++){
        data_m[i] = mystr[i];
    }
    data_m[size_m] = '\0';
}

//
my_str_t& my_str_t::operator=(const my_str_t& mystr)
{
    if(this == &mystr){
        return *this;
    }
    delete[] data_m;

    capacity_m = mystr.capacity();
    size_m = mystr.size();
    data_m = new char[capacity_m];

    for(size_t i = 0; i<size_m; ++i)
    {
        data_m[i] = mystr[i];
    }
    return *this;
}

//
void my_str_t::swap(my_str_t& other) noexcept {
    char* temp_data = data_m;
    data_m = other.data_m;
    other.data_m = temp_data;
    size_t temp_capacity = capacity_m;
    capacity_m = other.capacity_m;
    other.capacity_m = temp_capacity;
    size_t temp_size = size_m;
    size_m = other.size_m;
    other.size_m = temp_size;
}
//
char& my_str_t::operator[](size_t idx){return data_m[idx];}
const char& my_str_t::operator[](size_t idx) const{return data_m[idx];}
//
char& my_str_t::at(size_t idx)
{
    if (idx >= size_m) {throw std::out_of_range("Index out of bounds");}
    return data_m[idx];
}

//
const char& my_str_t::at(size_t idx) const
{
    if (idx >= size_m) {throw std::out_of_range("Index out of bounds");}
    return data_m[idx];
}

//
void my_str_t::reserve(size_t new_capacity) {
    if (new_capacity > capacity_m) {
        char* new_data_m = new char[new_capacity];
        for (size_t i = 0; i < size_m; ++i) {
            new_data_m[i] = data_m[i];
        }
        capacity_m = new_capacity;
        delete[] data_m;
        data_m = new_data_m;
    }
}

//
void my_str_t::shrink_to_fit(){
    capacity_m = size_m;
    reserve(size_m+1);
}

//
void my_str_t::resize(size_t new_size, char new_char)
{
    if(new_size < size_m){size_m = new_size;}
    else if(size_m < new_size && new_size <= capacity_m)
    {
        for(size_t i = size_m; i < new_size; ++i){data_m[i] = new_char;}
        data_m[new_size] = '\0';
        size_m = new_size;
    }
    else if(new_size > capacity_m)
    {
        size_t new_capacity = new_size + 16 - new_size % 16;
        reserve(new_capacity);
        resize(new_size, new_char);
    }
}
//
void my_str_t::clear(){size_m = 0;}
//
void my_str_t::insert(size_t idx, const my_str_t& str)
{
    if(idx > size_m){throw std::out_of_range("Index out of bounds");}
    if(size_m + str.size() >= capacity())
    {
        size_t new_capacity = size_m + str.size() + 16 - (size_m + str.size()) % 16;
        reserve(new_capacity*2);
    }
    size_m += str.size();
    size_t insert_end = idx + str.size();
    for(size_t i = size_m-1; i > insert_end-1; --i)
    {
        data_m[i] = data_m[i - str.size()];
    }

    size_t j = 0;
    for (size_t i = idx; i < insert_end; ++i)
    {
        data_m[i] = str[j];
        j++;
    }
    data_m[size_m] = '\0';
}
//
void my_str_t::insert(size_t idx, char c)
{
    if(idx > size_m){throw std::out_of_range("Index out of bounds");}
    size_m++;
    if(size_m >= capacity())
    {
        size_t new_capacity = size_m + 16 - size_m % 16;
        reserve(new_capacity*2);
    }
    for(size_t i = size_m - 1; i > idx; --i){data_m[i] = data_m[i-1];}
    data_m[idx] = c;
    data_m[size_m] = '\0';
}
//
void my_str_t::insert(size_t idx , const char* cstr)
{
    if(idx > size_m){throw std::out_of_range("Index out of bounds");}
    size_t cstr_len = strlen(cstr);
    if((size_m + cstr_len) >= capacity())
    {
        size_t new_capacity = size_m + cstr_len + 16 - (size_m + cstr_len) % 16;
        reserve(new_capacity*2);
    }
    size_t j = 0;
    size_m += cstr_len;
    size_t insert_end = idx + cstr_len;
    for(size_t i = size_m-1; i > insert_end-1; --i)
    {
        data_m[i] = data_m[i - cstr_len];
    }
    for (size_t i = idx; i < insert_end; ++i)
    {
        data_m[i] = cstr[j];
        j++;
    }
    data_m[size_m] = '\0';
}

//
void my_str_t::remove_trailing_newline() {
    if (size_m > 0 && data_m[size_m - 1] == '\n') {
        size_m--;
        data_m[size_m] = '\0';
    }
}
//
void my_str_t::append(const my_str_t& str){ insert(size_m, str);}
//
void my_str_t::append(char c){insert(size_m, c);}
//
void my_str_t::append(const char* cstr){insert(size_m, cstr);}
//
void my_str_t::erase(size_t begin, size_t size) {
    if (begin > size_m) {
        throw std::out_of_range("Index out of bounds");
    }
    size_t toErase = size_m - begin;
    if (size < toErase) {toErase = size;}
    for (size_t i = begin; i + toErase < size_m; i++) {
        data_m[i] = data_m[i + toErase];
    }
    size_m -= toErase;
    data_m[size_m] = '\0';
}

// 
size_t my_str_t::size() const noexcept{return size_m;}
size_t my_str_t::capacity() const noexcept{return capacity_m;}
const char* my_str_t::c_str() const {return data_m;}
//
size_t my_str_t::find(char c, size_t idx){
    if (idx > size_m) {throw std::out_of_range("Index out of bounds");}
    for (size_t i = idx; i < size_m; i++) {
        if (data_m[i] == c){return i;}
    }
    return my_str_t::not_found;
}

//
size_t my_str_t::find(const std::string& str, size_t idx){
    if (not size_m){return not_found;}
    if (str.empty()){return 0;}
    if (idx > size_m) {
        throw std::out_of_range("Index out of bounds");
    }
    size_t loopSize = size_m - str.length();
    size_t strLen = str.length();
    bool found = true;
    for (size_t i = idx; i <= loopSize; i++) {
        if (data_m[i] == str[0]){
            for (size_t j = 0; j < strLen; j++) {
                if (data_m[i + j] != str[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {return i;}
        }
    }
    return not_found;
}
//
size_t my_str_t::find(const char* cstr, size_t idx){
    if (not size_m){return not_found;}
    if (not cstr){return 0;}
    if (idx > size_m) {throw std::out_of_range("Index out of bounds");}
    size_t loopSize = size_m-strlen(cstr);
    size_t cSize = strlen(cstr);
    for (size_t i = idx; i <= loopSize; i++) {
        if (data_m[i] == cstr[0] && strncmp(data_m+i, cstr, cSize) == 0) {return i;}
    }
    return not_found; // fixed?
}

//
my_str_t my_str_t::substr(size_t begin, size_t size)
{
    if (begin > size_m) {throw std::out_of_range("Index out of bounds");}
    size_t end = (begin + size) > size_m ? size_m : begin + size;
    my_str_t new_str(size, ' ');
    new_str.clear();
    for(size_t i = begin; i < end; ++i)
    {
        new_str.append(data_m[i]);
    }
    return new_str;
}


//Additional task
//
my_str_t my_str_t::operator+(const my_str_t &str)
{
    my_str_t new_str(*this);
    new_str.insert(new_str.size(), str);
    return new_str;
}
//
my_str_t my_str_t::operator+(char c)
{
    my_str_t new_str(*this);
    new_str.insert(new_str.size(), c);
    return new_str;
}
//
my_str_t my_str_t::operator+(const char *cstr)
{
    my_str_t new_str(*this);
    new_str.insert(new_str.size(), cstr);
    return new_str;
}
//
my_str_t& my_str_t::operator+=(const my_str_t& str)
{
    insert(size_m, str);
    return *this;
}
//
my_str_t &my_str_t::operator+=(char c)
{
    insert(size_m, c);
    return *this;
}
//
my_str_t &my_str_t::operator+=(const char *cstr)
{
    insert(size_m, cstr);
    return *this;
}
//
my_str_t my_str_t::operator*(int mul)
{
    if(mul < 0 ){throw std::invalid_argument("Attempting to multiply a string by a negative number.");}
    size_t iter_num = mul;
    size_t size = size_m * mul;
    my_str_t new_str(size, ' ');
    new_str.clear();
    for(size_t i = 0; i < iter_num; ++i)
    {
        new_str.insert(new_str.size(), *this);
    }
    return new_str;
}
//
my_str_t &my_str_t::operator*=(int mul)
{
    if(mul < 0 ){throw std::invalid_argument("Attempting to multiply a string by a negative number.");}
    if(mul == 0){
        clear();
    }else{
        size_t iter_num = mul;
        my_str_t str_copy(*this);
        reserve(size_m);
        for(size_t i = 1; i < iter_num; ++i){
            insert(size_m, str_copy);
        }
    }
    return *this;
}
//
my_str_t::~my_str_t()
{
    delete[] data_m;
}
//
std::ostream& operator<<(std::ostream& stream , const my_str_t& str)
{
    stream << str.c_str();
    return stream;
}
//
std::istream& operator>>(std::istream& stream, my_str_t& str) {
    str.clear();
    char ch;
    while (stream.get(ch) && (isspace(ch))) {}
    while (not isspace(ch)) {
        str.append(ch);
        if (!stream.get(ch)) {
            break;
        }
    }
    return stream;
}
//
std::istream& readline(std::istream& stream, my_str_t& str){
    str.clear();
    char ch;
    while (stream.get(ch)) {
        if (ch == '\n') {
            break;
        }
        str.resize(str.size() + 1);
        str[str.size() - 1] = ch;
    }
    str.remove_trailing_newline();
    return stream;
}
//
size_t getMin(const my_str_t &str1, const my_str_t &str2){
    if (str1.size() > str2.size()) {
        return str2.size();
    }
    else {return str1.size();}
}
//
size_t getMinCstr(const my_str_t &str1, const char* cstr2){
    if (str1.size() > strlen(cstr2)) {
        return strlen(cstr2);
    }
    else {return str1.size();}
}

//куди їх блять запхати\/ в дупу... точно, ще й питаєш вибачте буде круто якщо ми закомітимо з цими коментарями|а давай
//
bool operator==(const my_str_t& str1, const my_str_t& str2){
    if(str1.size() != str2.size()){return false;}
    size_t loopSize = str1.size();
    for (size_t i = 0; i < loopSize; i++){
        if (str1[i] != str2[i]){return false;}
    }
    return true;
}
//
bool operator!=(const my_str_t& str1, const my_str_t& str2){
    if(str1.size() != str2.size()){return true;}
    size_t loopSize = str1.size();
    for (size_t i = 0; i < loopSize; i++){
        if (str1[i] != str2[i]){return true;}
    }
    return false;
}
//
bool operator> (const my_str_t& str1, const my_str_t& str2){
    size_t minSize = getMin(str1, str2);
    for (size_t i = 0; i < minSize; i++){
        if (str1[i] > str2[i]){return true;} else if (str1[i] < str2[i]) {return false;}
    }
    return str1.size() > str2.size();
}
//
bool operator< (const my_str_t& str1, const my_str_t& str2){
    size_t minSize = getMin(str1, str2);
    for (size_t i = 0; i < minSize; i++){
        if (str1[i] < str2[i]){return true;} else if (str1[i] > str2[i]) {return false;}
    }
    return str1.size() < str2.size();
}
//
bool operator>=(const my_str_t& str1, const my_str_t& str2){
    return not (str1 < str2);
}
//
bool operator<=(const my_str_t& str1, const my_str_t& str2){
    return not (str1>str2);
}
//
bool operator==(const my_str_t& str1, const char* cstr2){
    if(str1.size() != strlen(cstr2)){return false;}
    size_t loopSize = strlen(cstr2);
    for (size_t i = 0; i < loopSize; i++){
        if (str1[i] != cstr2[i]){return false;}
    }
    return true;
}
//
bool operator!=(const my_str_t& str1, const char* cstr2){
    if(str1.size() != strlen(cstr2)){return true;}
    size_t loopSize = strlen(cstr2);
    for (size_t i = 0; i < loopSize; i++){
        if (str1[i] != cstr2[i]){return true;}
    }
    return false;
}

//
bool operator> (const my_str_t& str1, const char* cstr2){
    size_t minSize = getMinCstr(str1, cstr2);
    for (size_t i = 0; i < minSize; i++){
        if (str1[i] > cstr2[i]){return true;} else if (str1[i] < cstr2[i]){return false;}
    }
    return str1.size() > strlen(cstr2);
}

//
bool operator>=(const my_str_t& str1, const char* cstr2){
    return not (str1 < cstr2);
}

//
bool operator< (const my_str_t& str1, const char* cstr2){
    size_t minSize = getMinCstr(str1, cstr2);
    for (size_t i = 0; i < minSize; i++){
        if (str1[i] < cstr2[i]){return true;} else if (str1[i] > cstr2[i]){return false;}
    }
    return str1.size() < strlen(cstr2);
}

//
bool operator<=(const my_str_t& str1, const char* cstr2){
    return not (str1 > cstr2);
}

//
bool operator==(const char* cstr1, const my_str_t& str2){
    return (str2 == cstr1);
}
//
bool operator!=(const char* cstr1, const my_str_t& str2){
    return (str2 != cstr1);
}
//
bool operator> (const char* cstr1, const my_str_t& str2){
    return (str2 < cstr1);
}
//
bool operator>=(const char* cstr1, const my_str_t& str2){
    return not (str2 > cstr1);
}
//
bool operator< (const char* cstr1, const my_str_t& str2){
    return (str2 > cstr1);
}
//
bool operator<=(const char* cstr1, const my_str_t& str2) {
    return not (str2 < cstr1);
}
//
my_str_t operator+(const char* cstr, const my_str_t& str){
    my_str_t new_str(cstr);
    new_str.insert(strlen(cstr), str);
    return new_str;
}