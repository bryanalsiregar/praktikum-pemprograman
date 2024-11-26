#include<iostream>
#include<string>

using namespace std;

int temukan_bilangan_terbesar_kedua(int data[], int n) {
    int terb_1 = data[0], terb_2 = data[0];
    
    for (int i = 0; i < n; i++) {
        if (terb_1 < data[i]) {
            terb_2 = terb_1;
            terb_1 = data[i];
        } else if (data[i] > terb_2) {
            terb_2 = data[i];
        }
    }

    return terb_2;
} 

void run_func() {
    int n;
    cout << "Masukkan berapa banyak data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan data: ";
    for (int i = 0; i < n; i++) cin >> data[i];

    cout << "Bilangan terbesar kedua adalah " << temukan_bilangan_terbesar_kedua(data, n) << endl;
}

void test_func() {
    string test_num = "Test #1";
    int n = 6;
    int data_1[] = {24, 234, 324, 54, 243, 23};
    int trbs_2_exp = 243;
    if (temukan_bilangan_terbesar_kedua(data_1, n) == trbs_2_exp) cout << test_num << " Passed!" << endl;
    else cout << test_num << " Failed!" << endl;

    test_num = "Test #2";
    n = 5;
    int data_2[] = {45, 25, 1, 56, 24};
    trbs_2_exp = 45;
    if (temukan_bilangan_terbesar_kedua(data_2, n) == trbs_2_exp) cout << test_num << " Passed!" << endl;
    else cout << test_num << " Failed!" << endl;

    
    test_num = "Test #3";
    n = 3;
    int data_3[] = {1, 2, 3};
    trbs_2_exp = 2;
    if (temukan_bilangan_terbesar_kedua(data_3, n) == trbs_2_exp) cout << test_num << " Passed!" << endl;
    else cout << test_num << " Failed!" << endl;
    
    test_num = "Test #4";
    n = 9;
    int data_4[] = {1, 56, 24, 234, 45, 234, 65, 525, 23};
    trbs_2_exp = 234;
    if (temukan_bilangan_terbesar_kedua(data_4, n) == trbs_2_exp) cout << test_num << " Passed!" << endl;
    else cout << test_num << " Failed!" << endl;
    
    test_num = "Test #5";
    n = 2;
    int data_5[] = {4, 10};
    trbs_2_exp = 4;
    if (temukan_bilangan_terbesar_kedua(data_5, n) == trbs_2_exp) cout << test_num << " Passed!" << endl;
    else cout << test_num << " Failed!" << endl;
}


int main(int argc, char *argv[]) {
    if (argc > 1 && string(argv[1]) == "test") {
        test_func();
    } else {
        run_func();
    }
    return 0;
}