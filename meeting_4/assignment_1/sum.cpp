#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define ull unsigned long long 

ull sum_func(ull n) {
    ull out = 0;
    for (ull i = 1; i <= n; i++) {
        out+= i;
    }

    return out;
}

int run_func() {
    ull i;
    cin >> i;
    cout << "Sum = " << sum_func(i) << endl;

    return 0;
}

int test_func() {
    ifstream testFile("test.txt");
    int input;
    string expected_output;

    if (!testFile) {
        cerr << "Error: Could not open test.txt" << endl;
        return 1;
    }

    int test_num = 1;
    while (testFile >> input && getline(testFile >> ws, expected_output)) {
        string output = to_string(sum_func(input));
        if (output == expected_output) {
            cout << "Test " << test_num << " passed!" << endl;
        } else {
            cout << "Test " << test_num << " failed. Expected: \"" 
                      << expected_output << "\", Got: \"" << output << "\"" << endl;
        }
        test_num++;
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