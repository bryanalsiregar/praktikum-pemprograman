/*
	File ini berisi mengenai penyelesaian pada problem 2: Quadratic Equation Solver
	Dijalankan di onlinegdb.com
*/

// Header file yang digunakan
#include<iostream> // Untuk mengatur I/O C++
#include<math.h> // Untuk menggunakan fungsi matematika yang tidak ada pada default C++
#include<fstream>
#include<sstream>
#include<iomanip>

// Pengguanaan scope std
using namespace std;

string removeTrailingZeros(float value) {
	// Deklarasi variabel
    ostringstream oss;

	// Mengatur presisi angka desimal nilai secara tetap
    oss << fixed << setprecision(10) << value;
    // Mengubah nilai itu menjadi tipe string
	string str = oss.str();
    
	// Menghapus nol dibelakang desimal
    str.erase(str.find_last_not_of('0') + 1, string::npos);

	// Menghilangkan titik jika desimal berada akhir
    if (str.back() == '.') {
        str.pop_back();
    }

	// Keluarkan hasil penghilangan digit nol di belakang desimal
    return str;
}

string realRoots(float a, float b, float c) {
	// Deklarasi variabel yang dibutuhkan
	float disc;
	string s_x_1, s_x_2, outRoots;

	// Mencari Diskriminan
	disc = pow(b,2)-4*a*c;
	
	// Jika diskriminan lebih dari 0 maka output ada dua penyelesaian
	if (disc > 0)  
		return removeTrailingZeros((-b+sqrt(disc))/(2*a))+" "+removeTrailingZeros((-b-sqrt(disc))/(2*a));
	// Jika diskriminan sama dengan 0 makan output ada satu penyelesaian
	if (disc == 0) 
		return removeTrailingZeros((-b)/(2*a));

	// Jika diskriminan kurang dari nol maka output Tidak ada
	return "Tidak ada";
}

int run_func() {
	float a, b, c;

	cin >> a >> b >> c;

	cout << realRoots(a, b, c) << endl;
	return 0;
}

int test_func() {
	ifstream testFile("test.txt");
	float a, b, c;
    string expected_output = "";
	string line;
    int count = 0;
    int out_count = 1;

    if (!testFile) {
        cerr << "Error: Could not open test.txt" << endl;
        return 1;
    }

    int test_num = 1;
    while (getline(testFile, line)) {
        if (count == 0) { 
            istringstream iss(line);
            string word;

            int cnt = 0;
            while (iss >> word) {
                cnt++;
                if (cnt == 1) a = stoi(word);
                if (cnt == 2) b = stoi(word);
                if (cnt == 3) c = stoi(word);
            }
            count++;
        } else if (count == 1) {
            expected_output = line;
            count++;
            string output = realRoots(a, b, c);
            if (output == expected_output) {
                cout << "Test " << test_num << " passed!" << endl;
            } else {
                cout << "Test " << test_num << " failed. Expected: \"" 
                        << expected_output << "\", Got: \"" << output << "\"" << endl;
            }
            test_num++;
            count = 0;
            out_count = 1;
            expected_output = "";
        } 
    }

    testFile.close();
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
