# Lab work 3: use the string library, created by another team
Authors (team): Shumskyi Dmytro, Hashchuk Bohdan, Arnauta Liza
Variant: 3

## Prerequisites
Setup run/debug configurations this way, in order to run  random_text.txt as default program argument <br><br>
<img src="https://drive.google.com/uc?export=view&amp;id=1bh-vpOZ5QG6sy82sYpNB6nXtV1SZVqAv">

### Compilation/Installation/Usage
It can be performed two ways:

1)
```bash
mkdir build 
cd build
cmake .. && make
./lab3_strings_usage_shumskyi_hashchuk_arnauta ../random_text.txt ../new.txt
```

2) It can be also done by clicking arrow on the top right and it will be automatically compile and execute needed files

## package quality
 - The division into *.hpp/.cpp files is okay
 - Comments are missing in both files (mystring.cpp and mystring.hpp)

## interface quality
- In general, the library all the required methods are implemented, and there are no obvious violations, you can read the code easily.

## quality of realization
The implementation of this library has no critical fails, except for some minor ones:

1) global variables are constantly changing in their declaration order in functions, which can be confusing
2) if we take this method as an example, we see that there are places where memory is allocated but not freed, for example:

```
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
```

## code quality

Although there are almost no comments AT ALL, the code is quite easy to read. The code is formatted well. However, it is very clear who did what methods in the team of authors because both has a rather specific style of writing code (by code we suppose there two person in the team)

<br>

### rating on a 10-point scale 

the work is done quite well, almost perfectly, so the grade - **9.5/10**

<br>

### Important!
In order to make dynamic array we were supposed to add additional constructor
<img src="https://drive.google.com/uc?export=view&amp;id=17GFlesYOytSsI_kdBtkiL3gmcsjfImU9">

Google Benchmark allows us to measure execution times 
and memory usage for various string operations, 
providing data-driven insights for optimization. 
This analysis informed our ongoing 
efforts to check the efficiency and functionality 
of 'my_str_t'. In benchmarks_controller.h we have tested these methods: append, find, insert, clear, reserve, swap and size. After running main.cpp the execution time comparison between built in strings and my_str_t will be displayed.
