/*
    File ini digunakan untuk menyelesaikan permasalahan hitung rata rata
*/

#include<iostream> // untuk mengatur input dan output pada terminal
#include<string> // untuk menggunakan tipe data string
#include<fstream> // untuk membuka file test.txt
#include<sstream> // untuk mendapatkan kata dalam string


// untuk menyingkat pemanggilan fungsi standar
using namespace std;

float hitung_rata_rata(float x[], float y, int n, int i) {
    /*
        Fungsi ini digunakan untuk menyelesaikan masalah hitung rata-rata
        dengan penjelasan sebagai berikut

        Ilustrasi permasalan
        1 2 3
        1+2+3/3 = 2

        Dari ilustrasi dapat disimpulkan seperti ini 
        f(x, y=0, n, i) = {-1, n < 0
                           {0, n = 0
                           {(y+x[i])/n, i = 0
                           {f(x, y+x[i], n, i-1), n > 1
    */
    
    if (n < 0) return -1;
    if (n == 0) return 0;

    if (i == 0) return (y+x[i])/n;

    return hitung_rata_rata(x, y+x[i], n, i-1);
}

int run_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program tanpa test.txt
    */
    // mengambil input n dari pengguna
    int n;
    cin >> n;
    
    // mengambil input larikan dari pengguna dari terminal
    float x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    // menghitung larikan dan n untuk fungsi hitung_rata_rata
    float r = hitung_rata_rata(x, 0, n, n-1);

    // cetak hasil dari fungsi hitung_rata_rata
    cout << r << endl;
    return 0;
}

int test_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program dengan test.txt
    */
    ifstream testFile("test.txt"); // inisialialisi pembukaan file test.txt
    string line; // untuk menampung baris pada test.txt
    string expected_output; // untuk menampung output pada test.txt
    int n_input; // untuk mengambil banyaknya elemen pada larikan dari input
    string input; // untuk mengambil input test.txt 
    int count = 0; // indikasi apakah baris tersebut merupakan input atau output
    string output; // inisiasi output untuk fungsi hitung_rata_rata

    

    // periksa apakah file test.txt dapat dibuka
    if (!testFile) {
        // jika tidak bisa dibuka, akan menampilkan error
        cerr << "Error: Could not open test.txt" << endl;
        // indikasi fungsi ini tidak berjalan normal
        return 1;
    }

    // indikasi test ke berapa
    int test_num = 1;

    // pengulangan untuk mengambil baris pada test.txt
    while (getline(testFile, line)) {
        // indikasi jika baris adalah input atau output
        if (count == 0) { // indikasi jika input
            // mengambil banyaknya elemen pada larikan di test.txt
            n_input = stoi(line);
            // ubah indikasi
            count++;
        } else if (count == 1) { // indikasi jika merupakan input larikan
            // jika larikan valid
            if (n_input > 0) {
                // iniasiasi input dan baris pada test.txt
                float x[n_input];
                int i = 0;
                istringstream iss(line);
                while (iss >> input) {
                    x[i] = stoi(input);
                    i++;
                }
                // menghitung rata-rata dengan fungsi hitung_rata_rata
                output = to_string(hitung_rata_rata(x, 0, n_input, n_input-1));
            }
            // ubah indikasi
            count++;
        } else if (count == 2) { // indikasi jika output barang
            // jika banyaknya elemen larikan adalah 0
            if (n_input == 0) {
                // menjalankan fungsi dengan hitung_rata_rata
                float x[n_input];
                float r = hitung_rata_rata(x, 0, n_input, n_input-1);

                output = to_string(r);
            // jika banyaknya elemen larikan kurang dari 0
            } else if (n_input < 0) {
                // menjalankan fungsi dengan hitung_rata_rata
                float x[n_input];
                float r = hitung_rata_rata(x, 0, n_input, n_input-1);

                // cetak jika valid atau tidak
                if (r == -1) {
                    output = "Tidak Valid!";
                } else {
                    output = to_string(r);
                }
            }
            // periksa apabila output pada fungsi pencatatan_barang sama dengan output yang diinginkan di test.txt
            if (output == line) {
                // Jika sama dengan, tampilkan ini
                cout << "Test " << test_num << " passed!" << endl;
            } else {
                // Jika tidak sama dengan, tampilkan ini
                cout << "Test " << test_num << " failed. Expected: \"" 
                        << line << "\", Got: \""; 
                cout << output << endl;
                cout << "\"" << endl;
            }
            test_num++; // lanjut ke tes selanjutnya
            count = 0; // kembali ke mode input
        } 
    }

    testFile.close(); // menutup file test.txt
    return 0;
}

int main(int argc, char *argv[]) {
    /*
        Fungsi utama main digunakan untuk mengecek apakah pengguna
        ingin menjalankan program dalam mode tes atau manual
    */
    if (argc > 1 && string(argv[1]) == "test") {
        test_func();
    } else {
        run_func();
    }
    return 0;
}