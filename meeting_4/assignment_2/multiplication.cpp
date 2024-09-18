#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define ll long long

string mul_func(ll n) {
    string out = "";
    for (int i = 1; i <= 10; i++) {
        out += to_string(n) + " x " + to_string(i) + " = " + to_string(n*i) + "\n";
    }
    return out;
}

int test_func() {
    ifstream testFile("test.txt");
    string line;
    string input;
    string expected_output = "";
    int count = 0;
    int out_count = 1;

    if (!testFile) {
        cerr << "Error: Could not open test.txt" << endl;
        return 1;
    }

    int test_num = 1;
    while (getline(testFile, line)) {
        if (count == 0) { 
            input = line;
            count++;
        } else if (count == 1) {
            if (out_count < 10) {
                expected_output += line + "\n";
                out_count++;
                continue;
            } 
            expected_output += line + "\n";
            count++;
            string output = mul_func(stoi(input));
            if (output == expected_output) {
                cout << "Test " << test_num << " passed!" << endl;
            } else {
                cout << "Test " << test_num << " failed. Expected: \"" 
                        << expected_output << "\", Got: \"" << output << "\"" << endl;
            }
            test_num++;
            count = 0;
            out_count = 1;
            expected_output = "";
        } 
    }

    testFile.close();
    
    return 0;
}

int run_func() {
    ll i;
    cin >> i;
    cout << mul_func(i) << endl;
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