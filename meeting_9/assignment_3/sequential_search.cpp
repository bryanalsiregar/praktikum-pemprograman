#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<long long> nisn = {9960312699, 9963959682, 9950310962, 9970272750, 9970293945, 9952382180, 9965653989};
vector<long long> nilai = {90, 55, 80, 60, 70, 65, 60};
vector<string> nama = {
		"Handi Ramadhan", "Rio Alfandra", "Ronaldo Valentino Uneputty", 
		"Achmad Yaumil Fadjri R.", "Alivia Rahma Pramesti", "Ari Lutfianto", "Arief Budiman"};
int n = 7;


vector<int> index_sequential_search(vector<long long> data, int n, long long query) {
	vector<int> idx;
	for (int i = 0; i < n; i++) {
		if (data[i] == query) {
            idx.push_back(i);
		}
	}
	return idx;
}


int run_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program tanpa test.txt
    */
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