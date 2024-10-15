/*
    File ini digunakan untuk menyelesaikan latihan pencatatan barang

*/

#include<iostream> // untuk menggunakan input dan ouput pada terminal 
#include<string> // untuk menggunakan tipe data string

using namespace std; // untuk menyederhanakan std

// Identitas setiap barang
struct barang {
    string kode_barang;
    string nama_barang;
    int harga_barang;
    int jumlah_barang;
};

string pencatatan_barang(int n, barang barang_milik[]) {
    /*
        Fungsi ini digunakan untuk menyelesaikan masalah pencatatan barang.
        int n: banyaknya barang yang tersedia
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
    // ifstream testFile("test.txt"); // inisialialisi pembukaan file test.txt
    // string line; // untuk menampung baris pada test.txt
    // string expected_output; // untuk menampung output pada test.txt
    // int n_input; // untuk menampung input banyaknya barang pada test.txt
    // string input; // untuk menampung anggota vektor pada baris test.txt 
    // int count = 0; // indikasi apakah baris tersebut merupakan input atau output

    // barang barang_input;
    // int count_barang = 0;

    // // periksa apakah file test.txt dapat dibuka
    // if (!testFile) {
    //     // jika tidak bisa dibuka, akan menampilkan error
    //     cerr << "Error: Could not open test.txt" << endl;
    //     // indikasi fungsi ini tidak berjalan normal
    //     return 1;
    // }

    // // indikasi test ke berapa
    // int test_num = 1

    // // pengulangan untuk mengambil baris pada test.txt
    // while (getline(testFile, line)) {
    //     // indikasi jika baris adalah input atau output
    //     if (count == 0) { // indikasi jika input
    //         // inisialisasi baris
    //         n_input = int(line);
    //         if (n < 0 || n > 50) {
    //             count = 2;
    //         } else {
    //             barang barang_stay[n_input];
    //             barang_input = barang_stay;
    //             // mengubah indikasi
    //             count++;
    //         } 
    //     } else if (count == 1) {
    //         count_iden_barang = 0;
    //         while (iss >> input) {
    //             switch (count_iden_barang) {
    //                 case 0: barang_input[count_barang].kode_barang = input; break;
    //                 case 1: barang_input[count_barang].nama_barang = input; break;
    //                 case 2: barang_input[count_barang].harga_barang = int(input); break;
    //                 case 3: barang_input[count_barang].jumlah_barang = int(input); break;
    //                 default: break;
    //             }
    //         } 
    //         count_barang++;
    //         if (count_barang == n_input-1) {
    //             count_barang = 0;
    //             count++;
    //         }
    //     } else if (count == 2) { // indikasi jika output
    //         // melakukan reverse pada input
    //         string output = pencatatan_barang(n_input, barang_input);
    //         // periksa apabila output pada fungsi reverse_array sama dengan output yang diinginkan di test.txt
    //         if (output == line) {
    //             // Jika sama dengan, tampilkan ini
    //             cout << "Test " << test_num << " passed!" << endl;
    //         } else {
    //             // Jika tidak sama dengan, tampilkan ini
    //             cout << "Test " << test_num << " failed. Expected: \"" 
    //                     << line << "\", Got: \""; 
    //             for (int otr: output) cout << otr << " "; 
    //             cout << "\"" << endl;
    //         }
    //         test_num++; // lanjut ke tes selanjutnya
    //         count = 0; // kembali ke mode input
    //         count_barang = 0;

    //     } 
    // }

    // testFile.close(); // menutup file test.txt

    // return 0; // indikasi fungsi ini berjalan berhasil
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