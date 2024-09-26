# Pengerjaan Tugas 2

**Soal**

Write a program that prints the multiplication table for a given integer n. The
program should use a for loop to print the product of n with integers from 1 to
10.

**Example**

```bash
Input: 4
Output:
4 x 1 = 4
4 x 2 = 8
4 x 3 = 12
...
4 x 10 = 40
```

**Hint** Use a for loop to iterate through numbers 1 to 10 and print the product
for each.

**Required Files**

- **multiplication.cpp**: The C++ source code implementing the solution.
- **Makefile**: A makefile with the following functionalities:
    - Compile the program (make).
    - Run the program with user input (make run).
    - Clean the compiled files (make clean).
    - Test the program using test cases from test.txt (make test).
- **test.txt**: A file containing test cases in the format:
```bash
Input: <input_number>
Output:
<n> x 1 = <product_1>
<n> x 2 = <product_2>
... 
<n> x 10 = <product_10>
```