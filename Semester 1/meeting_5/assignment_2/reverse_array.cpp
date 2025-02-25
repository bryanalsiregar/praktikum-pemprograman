/*
    File ini digunakan untuk menyelesaikan permasalahan reverse_array
    Algoritma:
    1. Masukkan vector<int> inp_arr
    2. Inisialisasi vector<int> out
    3. Inisialisasi int i dengan (banyaknya anggota pada inp_arr)-1
    4. Masukkan anggota inp_arr ke-i ke dalam vektor out
    5. Kurangi int i dengan 1
    6. Kembali ke langkah 4 hingga i kurang dari 0
    7. Keluarkan vektor out
*/

#include<iostream> // untuk mengatur output dan input program
#include<vector> // untuk menggunakan data struktur vektor
#include<fstream> // untuk membuka file test.txt
#include<string> // untuk menggunakan string
#include<sstream> // untuk mendapatkan anggota dalam string

using namespace std; // untuk menyingkat std::

vector<int> reverse_array(vector<int> arr) {
    /*
        Fungsi ini digunakan untuk menyelesaikan permasalahan reverse_array.
        Fungsi ini memiliki input arr dengan tipe vektor dan tipe int
        Fungsi ini akan mengeluarkan reverse array dari input arr
    */
    vector<int> out; // untuk menampung anggota arr yang berbalik
    // mengulang input arr dari anggota akhir hingga awal dan menambahkan pada vektor out
    for (int i = arr.size()-1; i >= 0; i--) out.push_back(arr[i]);
    // mengeluarkan hasil vektor yang sudah dibalik
    return out;
}

int run_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program tanpa test.txt
    */
    vector<int> inp_vector; // untuk menampung input dengan vektor
    int inp; // untuk menampung input cin
    // menambahkan angka yang diinputkan ke dalam inp_vector dengan perintah
    // menggunakan perintah CTRL+D atau CTRL+Z untuk mengakhiri penginputan
    cout << "Masukkan angka untuk vektor dengan tipe int (CTRL+D atau CTRL+Z untuk mengakhiri): ";
    while (cin >> inp) inp_vector.push_back(inp);

    // melakukan pembalikkan vektor
    vector<int> rvs_arr = reverse_array(inp_vector);

    // untuk mencetak semua anggota pada vektor yang sudah dibalik
    for (long unsigned int i = 0; i < rvs_arr.size(); i++) cout << rvs_arr[i] << " ";
    // untuk memberikan baris baru
    cout << endl;

    // indikasi bahwa program berhasil berjalan
    return 0;
}

int test_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program dengan test.txt
    */
    ifstream testFile("test.txt"); // inisialialisi pembukaan file test.txt
    string line; // untuk menampung baris pada test.txt
    vector<int> expected_output; // untuk menampung angka output pada test.txt
    vector<int> vec_input; // untuk menampung angka input pada test.txt
    int input; // untuk menampung anggota vektor pada baris test.txt 
    int count = 0; // indikasi apakah baris tersebut merupakan input atau output

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
            // inisialisasi baris
            istringstream iss(line);
            // pengulangan kolom anggota untuk dijadikan dalam tipe int dan ditambahkan pada vec_input
            while (iss >> input) vec_input.push_back(input);
            // mengubah indikasi
            count++;
        } else if (count == 1) { // indikasi jika output
            // melakukan reverse pada input
            vector<int> output = reverse_array(vec_input);
            // inisialisasi baris
            istringstream iss(line);
            // pengulangan kolom anggota untuk dijadikan dalam tipe int dan ditambahkan pada expected_output
            while (iss >> input) expected_output.push_back(input);
            // periksa apabila output pada fungsi reverse_array sama dengan output yang diinginkan di test.txt
            if (output == expected_output) {
                // Jika sama dengan, tampilkan ini
                cout << "Test " << test_num << " passed!" << endl;
            } else {
                // Jika tidak sama dengan, tampilkan ini
                cout << "Test " << test_num << " failed. Expected: \"" 
                        << line << "\", Got: \""; 
                for (int otr: output) cout << otr << " "; 
                cout << "\"" << endl;
            }
            test_num++; // lanjut ke tes selanjutnya
            vec_input = {}; // reset vec_input
            expected_output = {}; // reset output untuk menampung output test.txt
            count = 0; // kembali ke mode input
        } 
    }

    testFile.close(); // menutup file test.txt

    return 0; // indikasi fungsi ini berjalan berhasil
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