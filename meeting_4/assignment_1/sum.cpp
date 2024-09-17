#include<iostream>

using namespace std;

#define ull unsigned long long 

ull sum_func(ull n) {
    ull out = 0;
    for (ull i = 1; i <= n; i++) {
        out+= i;
    }

    return out;
}

int main() {
    ull i;
    cin >> i;
    cout << "Sum = " << sum_func(i) << endl;
    return 0;
}