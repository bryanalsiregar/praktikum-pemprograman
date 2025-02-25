/*
    File ini digunakan untuk menyelesaikan tugas bilangan fibonacci
*/

// import package/library yang dibutuhkan
#include<iostream>
#include<fstream>
#include<string>


// untuk memanggil fungsi standar tanpa std::
using namespace std;


int fibonacci(int n) {
    /*
        Fungsi untuk menyelesaikan permasalahan Fibonacci
        dengan penjelasan 
        
        Ilustrasi 
        0 1 1 2 3 5
        0 1 

        Dengan begitu, kita bisa menyimpulkan fungsi rekursif sebagai berikut:
        f(x) = { 0, x = 1
               { 1, x = 2 
               { 
               { f(x-1)+f(x-2), x > 2 

        Kita bisa mencoba segala macam X
        x = 1, 0
        x = 2, 1
        x = 3, 1+0=1
        x = 4, 1+1=2
    */
    if (n < 1) return -1;
    if (n == 1) return 0;
    if (n == 2) return 1;

    return fibonacci(n-1)+fibonacci(n-2);
}

int run_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program manual
        dengan pengguna memasukkan nilai n untuk bilangan 
        fibonacci ke-n
    */
    // memasukkan nilai n
    int n;
    cin >>  n;
    // kelarkan Tidak Valid! jika n tidak sesuai
    if (n < 0) {
        cout << "Tidak Valid!" << endl;
        return 0;
    }
    // memanggil fungsi fibonacci untuk mendapatkan bilangan fibonacci ke-n
    cout << fibonacci(n) << endl;
    return 0;
}

int test_func() {
    /*
        Fungsi ini digunakan untuk mengetes file ini dengan file
        test.txt
    */
    // inisiasi file
    ifstream testFile("test.txt");
    // inisiasi barisan
    string line;
    // inisiasi input yang didapatkan
    string input;
    // inisiasi output pada test.txt
    string expected_output;
    // indikasi input atau output
    int count = 0;

    // jika file tidak dapat dibuka
    if (!testFile) {
        cerr << "Error: Could not open test.txt" << endl;
        return 1;
    }

    // memberikan indikasi test ke berapa
    int test_num = 1;
    while (getline(testFile, line)) {
        // indikasi jika input
        if (count == 0) { 
            // barisan akan menjadi input
            input = line;
            // berubah indikasi
            count++;
        }
        // indikasi jika output
        else if (count == 1) {
            // mengambil barisan sebagai output yang diharapkan
            expected_output = line;
            // inisiasi output untuk fungsi fibonacci
            string output;
            // menyelesaikan problem fibonacci
            int fib = fibonacci(stoi(input));
            // cek jika fibonacci tidak sesuai
            // jika iya ubah output menjadi Tidak Valid!
            if (fib == -1) {
                output = "Tidak Valid!";
            } else {
                output = to_string(fib);
            }
            
            // cek jika ouput pada fungsi fibonacci sama dengan yang di test.txt
            if (output == expected_output) {
                cout << "Test " << test_num << " passed!" << endl;
            } else {
                cout << "Test " << test_num << " failed. Expected: \"" 
                        << expected_output << "\", Got: \"" << output << "\"" << endl;
            }
            // ubah urutan tes
            test_num++;
            // ubah indikasi
            count = 0;
        } 
    }
    // menutup file test.txt
    testFile.close();
    
    return 0;
}

int main(int argc, char *argv[]) {
    /*
        Fungsi main ini digunakan untuk mengecek
        apakah pengguna ingin menjalankan pada mode tes atau tidak
    */
    if (argc > 1 && string(argv[1]) == "test") {
        test_func();
    } else {
        run_func();
    }
    return 0;
}