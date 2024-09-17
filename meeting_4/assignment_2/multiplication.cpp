#include<iostream>
#include<string>

using namespace std;

#define ull unsigned long long

string mul_func(ull n) {
    string out = "";
    for (int i = 1; i <= 10; i++) {
        out += to_string(n) + " x " + to_string(i) + " = " + to_string(n*i) + "\n";
    }
    return out;
}

int main() {
    ull i;
    cin >> i;
    cout << mul_func(i) << endl;
    return 0;
}