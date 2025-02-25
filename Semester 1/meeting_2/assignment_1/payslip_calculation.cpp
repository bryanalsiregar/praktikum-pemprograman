/*
	File ini digunaka untuk menyelesaikan problem 1: Payslip Calculation
	Dijalankan di onlinegdb.com
*/
// Header yang digunakan untuk file ini
#include<iostream> // Untuk penggunaan I/O di C++
#include<string> // Untuk penggunaan tipe string dan manipulasinya
#include<algorithm> // Untuk menggunakan algoritma yang sudah dibuat sebelumnya
#include<fstream> // digunakan untuk membuka file txt
#include<sstream> // digunakan untuk mengambil perkata pada input test

// Penggunaam scope std
using namespace std;

// Penamaan kembali tipe untuk penyederhanaan
typedef unsigned long long ull;


// Fungsi ini untuk membnatu dalam pemisahan ribuan dengan penambahan titik dengan output tipe string
string thousandSeparator(int n) 
{ 
	// Inisial output
    string ans = ""; 
	
	// Mengubah variabel n yang int ke dalam string
    string num = to_string(n); 

	// Melakukan penambahan titik koma setelah tiga digit dari belakang angka
	// Dilakukan counting untuk mencari tahu apakah sudah pada digit ke-3 dari belakang
    // Penambahan titik koma dan tiga digit pada variabel ans
    int count = 0; 
    for (int i = num.size() - 1; 
         i >= 0; i--) { 
        count++; 
        ans.push_back(num[i]); 
  
        if (count == 3) { 
            ans.push_back('.'); 
            count = 0; 
        } 
    } 
	
	// Output harus dibalikkan sebab pencarian tiga digit belakang angka
    reverse(ans.begin(), ans.end()); 
  
	// Pengecekkan apakah panjang variabel ans habis dibagi 4 
	// Jika iya maka terjadi penghapusan pada variabel ans
    if (ans.size() % 4 == 0) { 
        ans.erase(ans.begin()); 
    } 
	
	// Keluarkan output
    return ans; 
}

string paySlip(string name, ull salary, ull installment, ull insurance) {
	// Deklarasi variabel
	ull tax;
	string outStr;

	// Menghitung pajak dari variabel salary
	tax = salary*0.2;

	// Membuat output yang diinginkan oleh tester
	outStr = "Payslip for Employee\n---------------------\nName: "
	+name+"\nGross Salary: Rp"+thousandSeparator(salary)+",00\nTax (20%): Rp"+thousandSeparator(tax)+
	",00\nInstallment: Rp"+thousandSeparator(installment)+",00\nInsurance: Rp"+
	thousandSeparator(insurance)+",00\nNet Salary: Rp"+thousandSeparator(salary-tax-installment-insurance)+
	",00\n";
	
	return outStr;
}

int run_func() {
	// Deklarasi variabel
	string name;
	ull salary, installment, insurance;
	
	// Penggunaa prompt dan input
	cout << "Input your name" << endl;
	cin >> name;
	cout << "Input your gross salary cost" << endl;
	cin >> salary;
	cout << "Input your installment cost" << endl;
	cin >> installment;
	cout << "Input your insurance cost" << endl;
	cin >> insurance;
	
	cout << paySlip(name, salary, installment, insurance) << endl;

    return 0;
}

int test_func() {
	ifstream testFile("test.txt");
    string line, name;
	ull salary, installment, insurance;
    string expected_output = "";
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
                if (cnt == 1) name = word;
                if (cnt == 2) salary = stoi(word);
                if (cnt == 3) installment = stoi(word);
                if (cnt == 4) insurance = stoi(word);
            }
            count++;
        } else if (count == 1) {
            if (out_count < 8) {
                expected_output += line + "\n";
                out_count++;
                continue;
            } 
            expected_output += line + "\n";
            count++;
            string output = paySlip(name, salary, installment, insurance);
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

int main(int argc, char *argv[]){
	if (argc > 1 && string(argv[1]) == "test") {
        test_func();
    } else {
        run_func();
    }
	return 0;
}
