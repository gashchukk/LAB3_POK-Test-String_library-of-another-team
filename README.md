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
./lab3_strings_usage_shumskyi_hashchuk_arnauta ../random_text.txt
```

2) It can be also done by clicking arrow on the top right and it will be automatically compile and execute needed files 

### Important!
In order to make dynamic array we were supposed to add additional constructor
<img src="https://drive.google.com/uc?export=view&amp;id=17GFlesYOytSsI_kdBtkiL3gmcsjfImU9">


### Results

In our work, we conducted several important 
tasks with our custom string class, 'my_str_t.' 
We read and processed text data from a file using 
'read_file,' dynamically resizing the 'my_str_t' 
array to accommodate the data. Furthermore, 
we implemented the 'word_concat' function, 
which concatenated non-empty strings separated by a 
colon ':' and removed any whitespace elements. 
Our analysis demonstrated the capabilities of 'my_str_t' 
and how it efficiently handles various string operations.

### mystring feedback

Interface Quality:

- The library's interface is well-structured, providing constructors, operators, and functions for common string operations.
- The provided functions meet the basic requirements of a string library, like insert, resize, find, and concatenation, making it usable for common string manipulations.

Cmake:

- CMake Version: Setting CMAKE_MINIMUM_REQUIRED to a specific version (3.15) is a ok. 
However consider using a more recent version of CMake, 
as newer versions include important features and improvements .
- There are some descriptive comments and function documentation, but the library would benefit from more comprehensive comments, especially for complex functions and classes.
- Overall it is written properly

Code Quality:

- The code generally follows acceptable coding standards with meaningful variable and function names.
- There are some commented-out sections and unusual comments in the code that should be removed.
- Some functions could benefit from more concise implementations.
- The code might benefit from additional comments and documentation, especially for more complex functions and classes, to make it more understandable for other developers.

Quality of Implementation:

- The code appears to be correct and doesn't seem to have frequent crashes.
- The functions seem to perform as expected for typical use cases, though some corner cases might not have been thoroughly tested.
- The memory management seems to be appropriately handled, with destructor, constructors(However not all were implemented. Go to important to see more).

# Additional tasks
We compared the performance of 
standard C++ strings and our custom 'my_str_t' 
string class using the Google Benchmark framework. 
Google Benchmark enabled us to measure execution times 
and memory usage for various string operations, 
providing data-driven insights for optimization. 
This analysis informed our ongoing 
efforts to enhance the efficiency and functionality 
of 'my_str_t'.
