#include<iostream>
#include<string>
#include<vector>

using namespace std;

const vector<long long> nisn = {9960312699, 9963959682, 9950310962, 9970272750, 9970293945, 9952382180, 9965653989};
const vector<long long> nilai = {90, 55, 80, 60, 70, 65, 60};
const vector<string> nama = {
		"Handi Ramadhan", "Rio Alfandra", "Ronaldo Valentino Uneputty", 
		"Achmad Yaumil Fadjri R.", "Alivia Rahma Pramesti", "Ari Lutfianto", "Arief Budiman"};
const int n = 7;

vector<int> index_bubble_sort(vector<long long> data, int n) {	
	vector<int> idx = {0, 1, 2, 3, 4, 5, 6};
	int temp_idx;
	long long temp;

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1; j++) {
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
	return idx;
} 

vector<int> index_selection_sort(vector<long long> data, int n) {
	vector<int> idx = {0, 1, 2, 3, 4, 5, 6};
	int temp_idx, min;
	long long temp;
	for (int i = 0; i < n; i++) idx[i] = i;

	for (int i = 0; i < n-1; i++) {
		min=i;
		for (int j = i+1; j < n; j++) {
			if (data[j]<data[min]) {
				min = j;
			}
		}
		temp = data[i];
		temp_idx = idx[i];
		data[i] = data[min];
		idx[i] = idx[min];
		data[min] = temp;
		idx[min] = temp_idx;
	}
	return idx;
}

vector<int> index_insertion_sort(vector<long long> data, int n) {
	vector<int> idx = {0, 1, 2, 3, 4, 5, 6};
	int i, temp_idx;
	long long temp;
	for (int i = 0; i < n; i++) idx[i] = i;

	for (int j=1; j < n; j++) {
		i = j-1;
		temp = data[j];
		temp_idx = idx[j];
		while (data[i]>temp&&i>=0) {
			data[i+1] = data[i];
			idx[i+1] = idx[i];
			i--;
		}
		data[i+1] = temp;
		idx[i+1] = temp_idx;
	}
	return idx;
}

int run_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program tanpa test.txt
    */
	vector<long long> new_nisn = {0, 0, 0, 0, 0, 0, 0};
	vector<string> new_nama = {"", "", "", "", "", "", ""};
	vector<long long> new_nilai = {0, 0, 0, 0, 0, 0, 0};
	vector<int> idx_sorted;

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
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc > 1 && string(argv[1]) == "test") {
        test_func();
    } else {
        run_func();
    }
    return 0;
}