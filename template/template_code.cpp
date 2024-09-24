#include<iostream>

using namespace std;

int run_func() {
    return 0;
}

int test_func() {
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