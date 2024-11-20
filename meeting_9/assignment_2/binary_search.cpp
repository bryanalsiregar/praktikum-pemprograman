#include<iostream>

using namespace std;

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


int index_binary_search(vector<long long> data, int n, long long query) {
	bool found = false;
	int i = 0, j = n, k, idx=-1;
	while (!found&&i<=j) {
		k = (i+j)/2;
		cout << k << endl;
		if (data[k] < query) {
			i = k+1;
		} else if (data[k] == query) {
			found = true;
			idx = k;
		} else {
			j = k-1;
		}
	}

	return idx;
}

int main() {
	vector<int> idx_sorted = index_insertion_sort(nisn, 7);
	vector<long long> new_nisn = {0, 0, 0, 0, 0, 0, 0};
	vector<string> new_nama = {"", "", "", "", "", "", ""};
	for (int i = 0; i < 7; i++) {new_nisn[i] = nisn[idx_sorted[i]]; new_nama[i] = nama[idx_sorted[i]];}

    int idx = index_binary_search(new_nisn, 7, 9950310962);

	cout << new_nama[idx] << endl;
    return 0;
}

int run_func() {
    /*
        Fungsi ini digunakan untuk menjalankan program tanpa test.txt
    */
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