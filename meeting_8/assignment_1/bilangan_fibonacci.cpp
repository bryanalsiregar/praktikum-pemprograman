/*
    0 1 1 2 3 5
    0 1 

    f(x) = { 0, x = 1
           { 1, x = 2 
           { 
           { f(x-1)+f(x-2), x > 2 

    x = 1, 0
    x = 2, 1
    x = 3, 1+0=1
    x = 4, 1+1=2
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int fibonacci(int n) {
    if (n < 1) return -1;
    if (n == 1) return 0;
    if (n == 2) return 1;

    return fibonacci(n-1)+fibonacci(n-2);
}

int run_func() {
    int n;
    cin >>  n;
    if (n < 0) {
        cout << "Tidak Valid!" << endl;
        return 0;
    }
    cout << fibonacci(n) << endl;
    return 0;
}

int test_func() {
    ifstream testFile("test.txt");
    string line;
    string input;
    string expected_output;
    int count = 0;

    if (!testFile) {
        cerr << "Error: Could not open test.txt" << endl;
        return 1;
    }

    int test_num = 1;
    while (getline(testFile, line)) {
        if (count == 0) { 
            input = line;
            count++;
        }
        else if (count == 1) {
            expected_output = line;
            count++;
            string output;
            int fib = fibonacci(stoi(input));
            if (fib == -1) {
                output = "Tidak Valid!";
            } else {
                output = to_string(fib);
            }

            if (output == expected_output) {
                cout << "Test " << test_num << " passed!" << endl;
            } else {
                cout << "Test " << test_num << " failed. Expected: \"" 
                        << expected_output << "\", Got: \"" << output << "\"" << endl;
            }
            test_num++;
            count = 0;
        } 
    }

    testFile.close();
    
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc > 1 && string(argv[1]) == "test") {
        test_func();
    } else {
        run_func();
    }
    return 0;
}