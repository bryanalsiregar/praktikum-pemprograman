/*
    File ini digunakan untuk menyelesaikan latihan pencatatan barang

*/

#include<iostream> // untuk menggunakan input dan ouput pada terminal 
#include<string> // untuk menggunakan tipe data string
#include<fstream> // untuk membuka file test.txt
#include<sstream> // untuk mendapatkan kata dalam string

using namespace std; // untuk menyederhanakan std

// Identitas setiap barang
struct barang {
    string kode_barang; // kode barang
    string nama_barang; // nama barang
    int harga_barang; // harga barang
    int jumlah_barang; // jumlah barang
};

string pencatatan_barang(int n, barang barang_milik[]) {
    /*
        Fungsi ini digunakan untuk menyelesaikan masalah pencatatan barang.
        int n: banyaknya barang yang tersedia
        barang[] barang_milik: barang-barang yang tersedia dalam array
    */

    // cek jika barang yang dimiliki melampaui kapasitas
    if (n > 50) {
        return "Barang melampaui kapasitas!";
    // cek jika input banyaknya barang tidak valid
    } else if (n < 0) {
        return "Banyaknya barang tidak valid!";
    }

    // untuk menampung jumlah barang dan rata - rata harga barang
    int jumlah_barang_milik = 0;
    float rata_rata_harga_barang = 0;
    
    // untuk memasukkan semua barang yang tersedia
    for (int i = 0; i < n; i++) {
        // menampung jumlah barang dan jumlah harga yang diinputkan
        // anggap harga barang adalah harga satuan
        jumlah_barang_milik += barang_milik[i].jumlah_barang;
        rata_rata_harga_barang += barang_milik[i].harga_barang*barang_milik[i].jumlah_barang;
    }

    // menampung output
    string out = to_string(jumlah_barang_milik) + " " + to_string(rata_rata_harga_barang/jumlah_barang_milik); 

    return out;
}
 
int run_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program tanpa test.txt
    */
    // digunakan untuk menampung banyaknya barang
    int n;
    // digunakan untuk menginput banyaknya barang pada terminal
    cin >> n;

    if (n > 50) {
        cout << "Barang melampaui kapasitas!" << endl;
        return 0;
    // cek jika input banyaknya barang tidak valid
    } else if (n < 0) {
        cout << "Banyaknya barang tidak valid!" << endl;
        return 0;
    }

    // untuk menampung barang yang diinputkan
    barang barang_milik[n];

    // untuk memasukkan semua barang yang tersedia
    for (int i = 0; i < n; i++) {
        cin >> barang_milik[i].kode_barang;
        cin >> barang_milik[i].nama_barang;
        cin >> barang_milik[i].harga_barang;
        cin >> barang_milik[i].jumlah_barang;
    }

    // menggunakan fungsi ini untuk menyelesaikan permasalahan pencatatan barang dan mencetaknya
    cout << pencatatan_barang(n, barang_milik) << endl;
    
    // indikator program berhasil
    return 0;
}

int test_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program dengan test.txt
    */
    ifstream testFile("test.txt"); // inisialialisi pembukaan file test.txt
    string line; // untuk menampung baris pada test.txt
    string expected_output; // untuk menampung output pada test.txt
    int n_input; // untuk menampung input banyaknya barang pada test.txt
    string input; // untuk menampung anggota vektor pada baris test.txt 
    int count = 0; // indikasi apakah baris tersebut merupakan input atau output
    barang barang_input[999]; // untuk menampung barang dalam test.txt
    int count_barang = 0; // untuk menghitung banyaknya barang dalam tiap test

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
            n_input = stoi(line);
            // cek jika n kurang dari 0 atau lebih dari 0
            if (n_input < 0 || n_input > 50) {
                // menuju ke indikasi output
                count = 2;
            } else {
                // mengubah indikasi
                count++;
            } 
        } else if (count == 1) { // indikasi jika input barang
            // indikasi identitas barang
            int count_iden_barang = 0;
            // inisialisasi baris pada test
            istringstream iss(line);
            // pengulangan kata dalam baris
            while (iss >> input) {
                // cek jika kata dalam baris itu suatu identitas
                switch (count_iden_barang) {
                    // identitas kode barang
                    case 0: barang_input[count_barang].kode_barang = input; break;
                    // identitas nama barang
                    case 1: barang_input[count_barang].nama_barang = input; break;
                    // identitas harga barang
                    case 2: barang_input[count_barang].harga_barang = stoi(input); break;
                    // indetitas jumlah barang
                    case 3: barang_input[count_barang].jumlah_barang = stoi(input); break;
                    // jika tidak memenuhi pengecekkan
                    default: break;
                }
                // pengubahan identitas kata dalam baris
                count_iden_barang++;
            }
            // menghitung barang yang sudah masuk
            count_barang++;
            // jika barang sudah terpenuhi semua
            if (count_barang == n_input) {
                // kembali untuk menghitung dari tidak ada barang
                count_barang = 0;
                // ubah indikasi
                count++;
            }
        } else if (count == 2) { // indikasi jika output
            // melakukan pencatatan barang pada input
            string output = pencatatan_barang(n_input, barang_input);
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
            count_barang = 0; // kembali menghitung barang
        } 
    }

    testFile.close(); // menutup file test.txt

    return 0; // indikasi fungsi ini berjalan berhasil
}

int main(int argc, char *argv[]) {
    /*
        Fungsi ini menjadi fungsi utama menjalankan program
    */
    // cek jika user memberikan argumen test 
    if (argc > 1 && string(argv[1]) == "test") {
        test_func();
    } else {
        run_func();
    }
    // indikator program berhasil
    return 0;
}