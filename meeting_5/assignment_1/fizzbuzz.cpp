/*
    File ini digunakan untuk menyelesaikan permasalahan fizzbuzz.
    Terdapat beberapa fungsi dalam file ini, sebagai berikut:
    - Fungsi run_func digunakan untuk menjalankan file seperti biasa
    - Fungsi test_func digunakan untuk menjalankan file dengan tes
    - Fungsi fizzbuzz digunakan untuk menyelesaikan malasah fizzbuzz
    
    Algoritma penyelesaian
    1. Deklarasi variabel vector string out
    2. Inisialisasi variabel intenger i dengan nilai 1
    3. Jika nilai i mod 3 = 0 dan nilai i mod 5 = 0, jadikan vector dengan index i sebagai "Fizzbuzz"
    4. Jika nilai i mod 3 = 0, jadikan vector dengan index i sebagai "Fizz"
    5. Jika nilai i mod 5 = 0, jadikan vector dengan index i sebagai "Buzz"
    6. Jika tidak masuk langkah 3, 4, dan 5, jadikan vector dengan i sebagai i dengan tipe string
    7. Tambahkan nilai i dengan 1
    9. Jika  nilai i kurang dari 100, ulangi proses dari nomor 3
    9. Keluarkan vector out

*/

#include<iostream> // Digunakan untuk mengatur input dan output
#include<vector> // Untuk menggunakan data struktur vector
#include<string> // Untuk menggunakan data structur vector
#include<fstream> // digunakan untuk membuka file test.txt

using namespace std; // Penyingkatan supaya tidak menggunakan std::

vector<string> fizzbuzz() {
    /*
        Fungsi ini digunakan untuk menyelesaikan permasalahan Fizzbuzz
    */
    vector<string> out(101); // digunakan untuk menyimpan hasil output
    for (int i = 1; i <= 100; i++) { // menjalankan loop dari angka 1 sampai 100
        if ((i%3==0) && (i%5==0)) out[i] = "Fizzbuzz"; // jika nilai i merupakan perkalian 3 dan 5
        else if (i%3==0) out[i] = "Fizz"; // jika nilai i merupakan perkalian 3
        else if (i%5==0) out[i] = "Buzz"; // jika nilai i merupakan perkalian 5
        else out[i] = to_string(i); // jika nilai i tidak termasuk perkalian 3 atu 5
    }
    return out; // mengeluarkan vector out
}

string print_fizzbuzz() {
    /*
        Fungsi ini digunakan untuk memberikan format mencetak fizzbuzz dengan tipe string
    */
    vector<string> fb = fizzbuzz(); // mendapatkan vector fizzbuzz
    string out = ""; // untuk menampung member vector fizzbuzz
    for (int i = 1; i <= 100; i++) { // perulangan dengan size vector fizzbuzz
        out += fb[i] + "\n"; // menambahkan member vector fizzbuzz dengan format string out
    }
    return out; // mengeluarkan format string pada variabel out
}

int run_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program tanpa test.txt
    */
    cout << print_fizzbuzz() << endl; // mencetak format cetakan
    return 0; // indikasi bahwa fungsi ini berjalan dengan baik
}

int test_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program dengan test.txt
    */
    ifstream testFile("test.txt"); // inisialisasi file test.txt
    string line; // deklarasi untuk mengambil baris test.txt
    string expected_output = ""; // menampung semua baris pada test.txt untuk diubah ke dalam format berbeda

    if (!testFile) { // cek jika file test.txt tidak berhasil dibuka
        cerr << "Error: Could not open test.txt" << endl; // memberikan error bahwa file test.txt tidak dapat dibuka
        return 1; // indikasi bahwa program tidak berhasil berjalan
    }

    int test_num = 1; // indikator ke berapa tes yang dijalankan
    while (getline(testFile, line)) expected_output += line + "\n"; // mendapatkan baris pada test.txt dan ditambahkan pada penampungan
    string output = print_fizzbuzz(); // menjalankan fungsi fizzbuzz dengan mendapatkan format yang sesuai
    if (output == expected_output) { // periksa bila output pada fungsi sesuai dengan file test.txt
        cout << "Test " << test_num << " passed!" << endl; // cetak jika tes berhasil
    } else {
           cout << "Test " << test_num << " failed. Expected: \"" 
                << expected_output << "\", Got: \"" << output << "\"" << endl; // cetak bila tes tidak berhasil
    }

    testFile.close(); // menutup file test.txt
    return 0; // indikator bahwa file berjalan berhasil
}

int main(int argc, char *argv[]) {
    /*
        Fungsi utama yang akan dijalankan
    */
    if (argc > 1 && string(argv[1]) == "test") { // Periksa bila argumen meminta dalam bentuk test
        test_func(); // menjalankan fungsi tes
    } else {
        run_func(); // menjalankan fungsi run biasa
    }
    return 0; // indikasi bahwa program berjalan berhasil
}