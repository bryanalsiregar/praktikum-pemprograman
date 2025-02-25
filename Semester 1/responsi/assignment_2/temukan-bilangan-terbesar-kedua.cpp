// import package yang dibutuhkan
#include<iostream>
#include<string>

// untuk penyingkatan dalam pemanggilan fungsi standar
using namespace std;

int temukan_bilangan_terbesar_kedua(int data[], int n) {
    /*
        Fungsi ini digunakan untuk menyelesaikan permasalahan
        menemukan bilangan terbesar kedua
    */
    // inisiasi terbesar dan terbesar kedua
    int terb_1 = data[1], terb_2 = data[0];
    
    // pengulangan tiap angka pada data
    for (int i = 0; i < n; i++) {
        // mengecek apakah data merupakan terbesar atau terbesar kedua
        if (terb_1 < data[i]) {
            terb_2 = terb_1;
            terb_1 = data[i];
        } else if (data[i] > terb_2) {
            terb_2 = data[i];
        }
    }

    // keluarkan terbesar kedua
    return terb_2;
} 

void run_func() {
    // meminta pengguna memasukkan berapa banyak data
    int n;
    cout << "Masukkan berapa banyak data: ";
    cin >> n;

    // meminta pengguna memasukkan data sebanyak banyaknya data yang dimasukkan
    int data[n];
    cout << "Masukkan data: ";
    for (int i = 0; i < n; i++) cin >> data[i];

    // mencetak bilangan kedua dengan fungsi penyelesaian
    cout << "Bilangan terbesar kedua adalah " << temukan_bilangan_terbesar_kedua(data, n) << endl;
}

void test_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program dalam mode test
    */

    // Test 1
    // inisiasi test 1
    string test_num = "Test #1";
    int n = 6;
    int data_1[] = {24, 234, 324, 54, 243, 23};
    int trbs_2_exp = 243;
    // mengecek apakah keluaran fungsi penyelesaian sesuai dengan yang diharapkan
    if (temukan_bilangan_terbesar_kedua(data_1, n) == trbs_2_exp) cout << test_num << " Passed!" << endl;
    else cout << test_num << " Failed!" << endl;

    // Test 2
    // inisiasi test 2
    test_num = "Test #2";
    n = 5;
    int data_2[] = {45, 25, 1, 56, 24};
    trbs_2_exp = 45;
    // mengecek apakah keluaran fungsi penyelesaian sesuai dengan yang diharapkan
    if (temukan_bilangan_terbesar_kedua(data_2, n) == trbs_2_exp) cout << test_num << " Passed!" << endl;
    else cout << test_num << " Failed!" << endl;

    // Test 3
    // inisiasi test 3
    test_num = "Test #3";
    n = 3;
    int data_3[] = {1, 2, 3};
    trbs_2_exp = 2;
    // mengecek apakah keluaran fungsi penyelesaian sesuai dengan yang diharapkan
    if (temukan_bilangan_terbesar_kedua(data_3, n) == trbs_2_exp) cout << test_num << " Passed!" << endl;
    else cout << test_num << " Failed!" << endl;
    
    // Test 4
    // inisiasi test 4
    test_num = "Test #4";
    n = 9;
    int data_4[] = {1, 56, 24, 234, 45, 234, 65, 525, 23};
    trbs_2_exp = 234;
    // mengecek apakah keluaran fungsi penyelesaian sesuai dengan yang diharapkan
    if (temukan_bilangan_terbesar_kedua(data_4, n) == trbs_2_exp) cout << test_num << " Passed!" << endl;
    else cout << test_num << " Failed!" << endl;
    
    // Test 5
    // inisiasi test 5
    test_num = "Test #5";
    n = 2;
    int data_5[] = {10, 4};
    trbs_2_exp = 4;
    // mengecek apakah keluaran fungsi penyelesaian sesuai dengan yang diharapkan
    if (temukan_bilangan_terbesar_kedua(data_5, n) == trbs_2_exp) cout << test_num << " Passed!" << endl;
    else cout << test_num << " Failed!" << endl;
}


int main(int argc, char *argv[]) {
    // mengecek apakah pengguna ingin menjalankan program dalam mode biasa atau test
    if (argc > 1 && string(argv[1]) == "test") {
        test_func();
    } else {
        run_func();
    }
    return 0;
}