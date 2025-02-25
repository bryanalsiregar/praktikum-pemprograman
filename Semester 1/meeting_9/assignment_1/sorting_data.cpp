#include<iostream> // Digunakan untuk mengatur input dan output
#include<string> // Digunakan untuk menggunakan data struktur string
#include<vector> // Digunakan untuk menggunakan data tipe vector
#include<fstream> // untuk membuka file test.txt
#include<sstream> // untuk mendapatkan kata dalam string

using namespace std; // Untuk menyingkat pemanggilan subprogram standar

// data yang disediakan soal
const vector<long long> nisn = {9960312699, 9963959682, 9950310962, 9970272750, 9970293945, 9952382180, 9965653989};
const vector<long long> nilai = {90, 55, 80, 60, 70, 65, 60};
const vector<string> nama = {
		"Handi Ramadhan", "Rio Alfandra", "Ronaldo Valentino Uneputty", 
		"Achmad Yaumil Fadjri R.", "Alivia Rahma Pramesti", "Ari Lutfianto", "Arief Budiman"};
const int n = 7;

vector<int> index_bubble_sort(vector<long long> data, int n) {	
	/*
		Fungsi ini mengembalikan index dengan tipe vector dengan parameter data dan banyaknya data sebagai n.
		Fungsi ini digunakan untuk menyelesaikan permasalahan dengan bubble sort.
	*/
	vector<int> idx; // deklarasi index
	for (int i = 0; i < n; i++) idx.push_back(i); // inisialisasi index dengan banyaknya data
	int temp_idx; // untuk swap index
	long long temp; // untuk swap data

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1; j++) {
			// jika data sekarang lebih besar dari data setelahnya
			// swap terjadi begitu pula indexnya
			if (data[j]>data[j+1]) {
				temp = data[j];
				temp_idx = idx[j];
				data[j] = data[j+1];
				idx[j] = idx[j+1];
				data[j+1] = temp;
				idx[j+1] = temp_idx;
			}
		}
	}
	// keluarkan indexnya
	return idx;
} 

vector<int> index_selection_sort(vector<long long> data, int n) {
	/*
		Fungsi ini mengembalikan index dengan tipe vector dengan parameter data dan banyaknya data sebagai n.
		Fungsi ini digunakan untuk menyelesaikan permasalahan dengan selection sort.
	*/
	vector<int> idx; // deklarasi index
	for (int i = 0; i < n; i++) idx.push_back(i); // inisialisasi index dengan banyaknya data
	int temp_idx, min; // deklarasi variabel sementara index dan min pada data
	long long temp; // deklarasi variabel untuk swapping

	for (int i = 0; i < n-1; i++) {
		// anggap data terkecil adalah index awal
		min=i;
		for (int j = i+1; j < n; j++) {
			// pengulangan untuk mencari data yang lebih kecil
			// dari data awal
			if (data[j]<data[min]) {
				min = j;
			}
		}
		// swapping data dan indexnya
		temp = data[i];
		temp_idx = idx[i];
		data[i] = data[min];
		idx[i] = idx[min];
		data[min] = temp;
		idx[min] = temp_idx;
	}
	// kembalikan indexnya
	return idx;
}

vector<int> index_insertion_sort(vector<long long> data, int n) {
	/*
		Fungsi ini mengembalikan index dengan tipe vector dengan parameter data dan banyaknya data sebagai n.
		Fungsi ini digunakan untuk menyelesaikan permasalahan dengan insertion sort.
	*/
	vector<int> idx; // deklarasi index
	for (int i = 0; i < n; i++) idx.push_back(i); // inisialisasi index dengan banyaknya data
	int i, temp_idx; // deklarasi untuk pengulangan dan swapping index
	long long temp; // deklarasi untuk swapping data

	for (int j=1; j < n; j++) {
		// anggap data pada i adalah sebelumnya
		i = j-1;
		// inisialisasi untuk swapping
		temp = data[j];
		temp_idx = idx[j];
		// pengulangan untuk melakukan geser
		while (data[i]>temp&&i>=0) {
			data[i+1] = data[i];
			idx[i+1] = idx[i];
			i--;
		}
		// untuk swapping 
		data[i+1] = temp;
		idx[i+1] = temp_idx;
	}
	// keluarkan index 
	return idx;
}

int run_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program tanpa test.txt
    */
	// inisialiasi nisn, nama, dan nilai setelah sort
	// dan deklarasi index setelah sorting
	vector<long long> new_nisn = {0, 0, 0, 0, 0, 0, 0};
	vector<string> new_nama = {"", "", "", "", "", "", ""};
	vector<long long> new_nilai = {0, 0, 0, 0, 0, 0, 0};
	vector<int> idx_sorted;

	// menampilkan data setelah menggunakan bubble sort
	// berdasarkan nisn dan nilai
	cout << "Pengurutan data dengan bubble sort" << endl;
	cout << "Urutan berdasarkan NISN" << endl;
	idx_sorted = index_bubble_sort(nisn, 7);
	
	for (int i = 0; i < 7; i++) {
		new_nisn[i] = nisn[idx_sorted[i]]; 
		new_nama[i] = nama[idx_sorted[i]];
		new_nilai[i] = nilai[idx_sorted[i]];
	}
	
	cout << "NISN: ";
	for (int i = 0; i < 7; i++) cout << new_nisn[i] << " ";
	cout << endl;
	
	cout << "Nama: ";
	for (int i = 0; i < 7; i++) cout << new_nama[i] << " ";
	cout << endl;	
	
	cout << "Nilai: ";
	for (int i = 0; i < 7; i++) cout << new_nilai[i] << " ";
	
	cout << endl;
	cout << endl;

	cout << "Urutan berdasarkan Nilai" << endl;
	idx_sorted = index_bubble_sort(nilai, 7);
	
	for (int i = 0; i < 7; i++) {
		new_nisn[i] = nisn[idx_sorted[i]]; 
		new_nama[i] = nama[idx_sorted[i]];
		new_nilai[i] = nilai[idx_sorted[i]];
	}
	
	cout << "NISN: ";
	for (int i = 0; i < 7; i++) cout << new_nisn[i] << " ";
	cout << endl;
	
	cout << "Nama: ";
	for (int i = 0; i < 7; i++) cout << new_nama[i] << " ";
	cout << endl;	
	
	cout << "Nilai: ";
	for (int i = 0; i < 7; i++) cout << new_nilai[i] << " ";

	cout << endl;
	cout << endl;

	
	// menampilkan data setelah menggunakan selection sort
	// berdasarkan nisn dan nilai
	cout << "Pengurutan data dengan selection sort" << endl;
	cout << "Urutan berdasarkan NISN" << endl;
	idx_sorted = index_selection_sort(nisn, 7);
	
	for (int i = 0; i < 7; i++) {
		new_nisn[i] = nisn[idx_sorted[i]]; 
		new_nama[i] = nama[idx_sorted[i]];
		new_nilai[i] = nilai[idx_sorted[i]];
	}
	
	cout << "NISN: ";
	for (int i = 0; i < 7; i++) cout << new_nisn[i] << " ";
	cout << endl;
	
	cout << "Nama: ";
	for (int i = 0; i < 7; i++) cout << new_nama[i] << " ";
	cout << endl;	
	
	cout << "Nilai: ";
	for (int i = 0; i < 7; i++) cout << new_nilai[i] << " ";
	
	cout << endl;
	cout << endl;

	cout << "Urutan berdasarkan Nilai" << endl;
	idx_sorted = index_selection_sort(nilai, 7);
	
	for (int i = 0; i < 7; i++) {
		new_nisn[i] = nisn[idx_sorted[i]]; 
		new_nama[i] = nama[idx_sorted[i]];
		new_nilai[i] = nilai[idx_sorted[i]];
	}
	
	cout << "NISN: ";
	for (int i = 0; i < 7; i++) cout << new_nisn[i] << " ";
	cout << endl;
	
	cout << "Nama: ";
	for (int i = 0; i < 7; i++) cout << new_nama[i] << " ";
	cout << endl;	
	
	cout << "Nilai: ";
	for (int i = 0; i < 7; i++) cout << new_nilai[i] << " ";

	cout << endl;
	cout << endl;

	// menampilkan data setelah menggunakan insertion sort
	// berdasarkan nisn dan nilai
	cout << "Pengurutan data dengan insertion sort" << endl;
	cout << "Urutan berdasarkan NISN" << endl;
	idx_sorted = index_insertion_sort(nisn, 7);
	
	for (int i = 0; i < 7; i++) {
		new_nisn[i] = nisn[idx_sorted[i]]; 
		new_nama[i] = nama[idx_sorted[i]];
		new_nilai[i] = nilai[idx_sorted[i]];
	}
	
	cout << "NISN: ";
	for (int i = 0; i < 7; i++) cout << new_nisn[i] << " ";
	cout << endl;
	
	cout << "Nama: ";
	for (int i = 0; i < 7; i++) cout << new_nama[i] << " ";
	cout << endl;	
	
	cout << "Nilai: ";
	for (int i = 0; i < 7; i++) cout << new_nilai[i] << " ";
	
	cout << endl;
	cout << endl;

	cout << "Urutan berdasarkan Nilai" << endl;
	idx_sorted = index_insertion_sort(nilai, 7);
	
	for (int i = 0; i < 7; i++) {
		new_nisn[i] = nisn[idx_sorted[i]]; 
		new_nama[i] = nama[idx_sorted[i]];
		new_nilai[i] = nilai[idx_sorted[i]];
	}
	
	cout << "NISN: ";
	for (int i = 0; i < 7; i++) cout << new_nisn[i] << " ";
	cout << endl;
	
	cout << "Nama: ";
	for (int i = 0; i < 7; i++) cout << new_nama[i] << " ";
	cout << endl;	
	
	cout << "Nilai: ";
	for (int i = 0; i < 7; i++) cout << new_nilai[i] << " ";

	cout << endl;
	cout << endl;


    return 0;
}

int test_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program dengan test.txt
    */
    ifstream testFile("test.txt"); // inisialialisi pembukaan file test.txt
    string line; // untuk menampung baris pada test.txt
    vector<long long> expected_output; // untuk menampung angka output pada test.txt
    vector<long long> vec_input; // untuk menampung angka input pada test.txt
    int input; // untuk menampung anggota vektor pada baris test.txt 
    int count = 0; // indikasi apakah baris tersebut merupakan input atau output
	int n_in; // untuk mengambil banyaknya data pada test.txt

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
			// indikasi apakah menginput data atau banyaknya data
            int count2 = 0;
			// pengulangan kolom anggota untuk dijadikan dalam tipe int dan ditambahkan pada vec_input
            while (iss >> input) {
				switch (count2) {
					// jika input banyaknya data
					case 0: n_in = input; count2++; break;
					// jika bukan
					default: vec_input.push_back(input);
				}
			}
            // mengubah indikasi
            count++;
        } else if (count == 1) { // indikasi jika output
			// inisialisasi baris
			istringstream iss(line);
			// pengulangan kolom anggota untuk dijadikan dalam tipe int dan ditambahkan pada expected_output
			while (iss >> input) expected_output.push_back(input);
			// melakukan test untuk ketiga algoritma sorting
			for (int i = 0; i < 3; i++) {
				if (i == 0) {
					cout << "Test Bubble Sort" << endl;
					// melakukan bubble sort pada input
					vector<int> output = index_bubble_sort(vec_input, n_in);
					// mengubah index menjadi data input pada test.txt
					vector<long long> new_output;
					for (int id: output) new_output.push_back(vec_input[id]);
				
					// periksa apabila output pada output bubble sort sama dengan output yang diinginkan di test.txt
					if (new_output == expected_output) {
						// Jika sama dengan, tampilkan ini
						cout << "Test " << test_num << " passed!" << endl;
					} else {
						// Jika tidak sama dengan, tampilkan ini
						cout << "Test " << test_num << " failed. Expected: \"" 
								<< line << "\", Got: \""; 
						for (int otr: new_output) cout << otr << " "; 
						cout << "\"" << endl;
					}
				} else if (i == 1) {
					cout << "Test Selection Sort" << endl;
					// melakukan selection sort pada input
					vector<int> output = index_selection_sort(vec_input, n_in);
					// mengubah index menjadi data
					vector<long long> new_output;
					for (int id: output) new_output.push_back(vec_input[id]);
					// periksa apabila output pada fungsi selection sort sama dengan output yang diinginkan di test.txt
					if (new_output == expected_output) {
						// Jika sama dengan, tampilkan ini
						cout << "Test " << test_num << " passed!" << endl;
					} else {
						// Jika tidak sama dengan, tampilkan ini
						cout << "Test " << test_num << " failed. Expected: \"" 
								<< line << "\", Got: \""; 
						for (int otr: new_output) cout << otr << " "; 
						cout << "\"" << endl;
					}
				} else if (i == 2) {
					cout << "Test Insertion Sort" << endl;
					// melakukan insertion sort pada input
					vector<int> output = index_insertion_sort(vec_input, n_in);
					// mengubah index menjadi data dengan data input test.txt
					vector<long long> new_output;
					for (int id: output) new_output.push_back(vec_input[id]);
					// periksa apabila output pada fungsi insertion sort sama dengan output yang diinginkan di test.txt
					if (new_output == expected_output) {
						// Jika sama dengan, tampilkan ini
						cout << "Test " << test_num << " passed!" << endl;
					} else {
						// Jika tidak sama dengan, tampilkan ini
						cout << "Test " << test_num << " failed. Expected: \"" 
								<< line << "\", Got: \""; 
						for (int otr: new_output) cout << otr << " "; 
						cout << "\"" << endl;
					}
				}
				
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