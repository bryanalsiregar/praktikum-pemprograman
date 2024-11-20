#include<iostream> // Digunakan untuk mengatur input dan output
#include<string> // Digunakan untuk menggunakan data struktur string
#include<vector> // Digunakan untuk menggunakan data tipe vector

using namespace std; // Untuk menyingkat pemanggilan subprogram standar

// data yang disediakan soal
const vector<long long> nisn = {9960312699, 9963959682, 9950310962, 9970272750, 9970293945, 9952382180, 9965653989};
const vector<long long> nilai = {90, 55, 80, 60, 70, 65, 60};
const vector<string> nama = {
		"Handi Ramadhan", "Rio Alfandra", "Ronaldo Valentino Uneputty", 
		"Achmad Yaumil Fadjri R.", "Alivia Rahma Pramesti", "Ari Lutfianto", "Arief Budiman"};
const int n = 7;

vector<int> index_insertion_sort(vector<long long> data, int n) {
	/*
		Fungsi ini mengembalikan index dengan tipe vector dengan parameter data dan banyaknya data sebagai n.
		Fungsi ini digunakan untuk menyelesaikan permasalahan dengan insertion sort.
	*/
	vector<int> idx = {0, 1, 2, 3, 4, 5, 6}; // inisialisasi index
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

int index_binary_search(vector<long long> data, int n, long long query) {
	/*
		Fungsi ini digunakan untuk mengembalikan data dengan tipe int dengan parameter
		data sebagai data yang ingin dicari dan query mencari nilai dari data. Fungsi
		ini digunakan untuk menyelesaikan permasalahan yang dibutuhkan dengan binary
		search
	*/
	// inisialisasi jika data ditemukan
	bool found = false;
	// inisialisasi untuk proses binary search
	int i = 0, j = n, k, idx=-1;
	// pengulangan saat belum tidak diketahui indexnya
	while (!found&&i<=j) {
		k = (i+j)/2;
		// kondisi jika nilai yang dicari bagian kanan dan kiri atau nilainya sama dengan
		// nilai yang dicari
		if (data[k] < query) {
			i = k+1;
		} else if (data[k] == query) {
			found = true;
			idx = k;
		} else {
			j = k-1;
		}
	}
	// kembalikan index yang ditemukan
	return idx;
}

int run_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program tanpa test.txt
    */
	// inisialiasi untuk data yang disorting sebab 
	// binary sorting membutuhkan data yang udah disort
    vector<int> idx_sorted = index_insertion_sort(nisn, 7);
	vector<long long> new_nisn = {0, 0, 0, 0, 0, 0, 0};
	vector<string> new_nama = {"", "", "", "", "", "", ""};
    vector<long long> new_nilai = {0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < 7; i++) {
        new_nisn[i] = nisn[idx_sorted[i]]; 
        new_nama[i] = nama[idx_sorted[i]];
        new_nilai[i] = nilai[idx_sorted[i]];
    }

	// tampilan untuk data yang ditemukan berdasarkan nisn yang sudah disort
    long long query = 9950310962;
    int idx = index_binary_search(new_nisn, 7, query);

    cout << "Search dengan binary search untuk nisn " << query << " dengan informasinya" << endl;
    cout << "NISN: " << new_nisn[idx] << endl;
    cout << "Nama: " << new_nama[idx] << endl;
    cout << "Nilai: " << new_nilai[idx] << endl;

    return 0;
}

int test_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program dengan test.txt
    */
    return 0;
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