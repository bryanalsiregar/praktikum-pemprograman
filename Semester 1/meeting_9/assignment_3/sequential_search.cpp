#include<iostream> // Digunakan untuk mengatur input dan output
#include<string> // Digunakan untuk menggunakan data struktur string
#include<vector> // Digunakan untuk menggunakan data tipe vector
#include<fstream> // untuk membuka file test.txt
#include<sstream> // untuk mendapatkan kata dalam string

using namespace std; // Untuk menyingkat pemanggilan subprogram standar

// data yang disediakan soal
vector<long long> nisn = {9960312699, 9963959682, 9950310962, 9970272750, 9970293945, 9952382180, 9965653989};
vector<long long> nilai = {90, 55, 80, 60, 70, 65, 60};
vector<string> nama = {
		"Handi Ramadhan", "Rio Alfandra", "Ronaldo Valentino Uneputty", 
		"Achmad Yaumil Fadjri R.", "Alivia Rahma Pramesti", "Ari Lutfianto", "Arief Budiman"};
int n = 7;


vector<int> index_sequential_search(vector<long long> data, int n, long long query) {
	/*
        Fungsi ini mengembalikan index dengan tipe vector int dengan parameter data, n sebagai banyaknya data,
        dan query untuk mencari nilai yang dicari pada variabel data. Fungsi ini digunakan untuk menyelesaikan
        permasalahan yang membutuhkan sequential search.
    */
    // untuk menampung index yang ditemukan
    vector<int> idx;
    // lakukan pengulangan pada data
    // ketika nilai pada data ditemukan maka
    // index nilai tersebut dimasukkan ke dalam tampungan index
	for (int i = 0; i < n; i++) {
		if (data[i] == query) {
            idx.push_back(i);
		}
	}
    // kembalikan tampungan index
	return idx;
}


int run_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program tanpa test.txt
    */
    // tampilan untuk melakukan sequential search untuk nilai_joko yaitu 60
    // sebelum nama diubah dan setelah diubah dengan menggunakan sequential
    // search
    int nilai_joko = 60;
    vector<int> idx = index_sequential_search(nilai, 7, nilai_joko);
    cout << "Sebelum nama diubah: " << endl;
    for (int id: idx) {
        cout << "NISN: " << nisn[id] << endl;
        cout << "Nama: " << nama[id] << endl;
        cout << "Nilai: " << nilai[id] << endl;
        cout << endl;
    }
    
    cout << "Setelah nama diubah: " << endl;
    for (int id: idx) {
        nama[id] = "Joko";
        
        cout << "NISN: " << nisn[id] << endl;
        cout << "Nama: " << nama[id] << endl;
        cout << "Nilai: " << nilai[id] << endl;
        cout << endl;
    }
    return 0;
}

int test_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program dengan test.txt
    */
    ifstream testFile("test.txt"); // inisialialisi pembukaan file test.txt
    string line; // untuk menampung baris pada test.txt
    int expected_output; // untuk menampung angka output pada test.txt
    vector<long long> vec_input; // untuk menampung angka input pada test.txt
    int input; // untuk menampung anggota vektor pada baris test.txt 
    int count = 0; // indikasi apakah baris tersebut merupakan input atau output
	int n_in; // untuk mengambil banyaknya data pada test.txt
	int q_in; // untuk mengambil query pada test.txt

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
			// indikasi apakah menginput data, banyaknya data, atau query
            int count2 = 0;
			// pengulangan kolom anggota untuk dijadikan dalam tipe int dan ditambahkan pada vec_input
            while (iss >> input) {
                // jika menginput banyaknya data
				if (count2 == 0) {
					n_in = input; 
					count2++;
                // jika menginput query
				} else if (count2 == n_in+1) {
					q_in = input;
                // jika menginput data
				} else {
					vec_input.push_back(input); 
					count2++;
				}
			}
            // mengubah indikasi
            count++;
        } else if (count == 1) { // indikasi jika output
			// mengubah baris pada test.txt menjadi int
			expected_output = stoi(line);

			// melakukan sequential search pada input
			vector<int> v_output = index_sequential_search(vec_input, n_in, q_in);
            // mengubah format yang diinginkan test.txt
            int output;
            if (v_output.size() == 0) output = 0;
            else output = 1;
				
			// periksa apabila output pada output sequential search sama dengan output yang diinginkan di test.txt
			if (output == expected_output) {
				// Jika sama dengan, tampilkan ini
				cout << "Test " << test_num << " passed!" << endl;
			} else {
				// Jika tidak sama dengan, tampilkan ini
				cout << "Test " << test_num << " failed. Expected: \"" 
						<< line << "\", Got: \""; 
				cout << output << " "; 
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
		Fungsi utama ini untuk mengecek apakah pengguna
		ingin untuk menjalankan program dalam test atau bukan
	*/
    if (argc > 1 && string(argv[1]) == "test") {
        test_func();
    } else {
        run_func();
    }
    return 0;
}