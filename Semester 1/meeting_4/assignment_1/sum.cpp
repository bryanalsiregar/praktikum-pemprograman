#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define ll long long 

ll sum_func(ll n) {
    ll out = 0;
    for (ll i = 1; i <= n; i++) {
        out+= i;
    }

    return out;
}

int run_func() {
    ll i;
    cin >> i;
    cout << "Sum = " << sum_func(i) << endl;

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
            string output = to_string(sum_func(stoi(input)));
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