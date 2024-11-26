#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> hitung_ganjil_genap(int data[], int n) {
    int ganjil = 0;
    int genap = 0;
    vector<int> ganjil_genap;

    for (int i = 0; i < n; i++) {
        if (data[i]%2==0) genap++;
        else ganjil++;
    }

    ganjil_genap.push_back(ganjil);
    ganjil_genap.push_back(genap);

    return ganjil_genap;
}

void run_func() {
    int n;
    cout << "Masukkan banyaknya data: ";
    cin >> n;
    cout << endl;

    int data[n];
    cout << "Masukkan data: ";
    for (int i = 0; i < n; i++) cin >> data[i];

    vector<int> ganjil_genap = hitung_ganjil_genap(data, n);

    cout << "Terdapat " << ganjil_genap[0] << " angka ganjil" << endl;
    cout << "Terdapat " << ganjil_genap[1] << " angka genap" << endl;
}

void test_func() {
    // Test 1
    string test_num = "Test #1";
    int data_1[] = {2, 4, 3, 5, 5, 3};
    int ganjil_exp = 4, genap_exp = 2, n = ganjil_exp+genap_exp;
    
    if (hitung_ganjil_genap(data_1, n)[0] == ganjil_exp && hitung_ganjil_genap(data_1, n)[1] == genap_exp) cout << test_num << " Passed!" << endl;
    else cout << test_num << " Failed!" << endl;

    test_num = "Test #2";
    int data_2[] = {5, 32, 53, 4, 6, 3};
    ganjil_exp = 3, genap_exp = 3, n = ganjil_exp+genap_exp;
    
    if (hitung_ganjil_genap(data_2, n)[0] == ganjil_exp && hitung_ganjil_genap(data_2, n)[1] == genap_exp) cout << test_num << " Passed!" << endl;
    else cout << test_num << " Failed!" << endl;

    test_num = "Test #3";
    int data_3[] = {65, 34, 65, 666, 24};
    ganjil_exp = 2, genap_exp = 3, n = ganjil_exp+genap_exp;

    if (hitung_ganjil_genap(data_3, n)[0] == ganjil_exp && hitung_ganjil_genap(data_3, n)[1] == genap_exp) cout << test_num << " Passed!" << endl;
    else cout << test_num << " Failed!" << endl;

    test_num = "Test #4";
    int data_4[] = {75, 35, 65, 31, 45};
    ganjil_exp = 5, genap_exp = 0, n = ganjil_exp+genap_exp;

    if (hitung_ganjil_genap(data_4, n)[0] == ganjil_exp && hitung_ganjil_genap(data_4, n)[1] == genap_exp) cout << test_num << " Passed!" << endl;
    else cout << test_num << " Failed!" << endl;

    test_num = "Test #5";
    int data_5[] = {9, 6, 35, 34, 87, 352};
    ganjil_exp = 3, genap_exp = 3, n = ganjil_exp+genap_exp;

    if (hitung_ganjil_genap(data_5, n)[0] == ganjil_exp && hitung_ganjil_genap(data_5, n)[1] == genap_exp) cout << test_num << " Passed!" << endl;
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