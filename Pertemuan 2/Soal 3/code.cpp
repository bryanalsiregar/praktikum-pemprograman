/*
	File ini berisi test case pada problem 1 dan 2 yang sudah disederhanakan dan disesuaikan dengan 
	format test yang ada
	Dijalankan di vscode
*/

// Header yang dipakai untuk menjalankan
#include<iostream> // Untuk mengautr I/O Stream
#include<string> // Untuk menggunakan tipe string dan manipulasinya
#include<algorithm> // Untuk menggunakan algoritma yang sudah dibuat 
#include<math.h> // Untuk menggunakan fungsi matematika yang tidak tersedia di C++
#include<sstream> // Untuk menetapkan presisi angka desimal
#include<iomanip> // Untuk mengatur presisi angka desimal 

// Penggunaan score std
using namespace std;

// Penyederhaana tipe
typedef unsigned long long ull;


// Fungsi ini untuk menghilangkan digit nol di belakang desimal
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

// Fungsi ini untuk menambahkan titik pada format ribuan
string thousandSeparator(int n) 
{ 
	// Membuat inisial output
    string ans = ""; 

	// Mengubah angka pada input menjadi string
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

	// Output hasil dari pemisah ribuan
    return ans; 
}


// Problem 1
// Fungsi untuk penyelesaian permasalahan Payslip Calculation
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
	",00";
	
	return outStr;
}

// Problem 2 Quadratic Equation Solver
// Fungsi untuk penyelesaian permasalahan Quadratic Equation Solver 
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


int main() {
	/* Test Problem 1: Payslip problem
		input format: name, salary, installment, insurance
		
		1. ["Adi", 1000000, 100000, 100000] --> 
		Payslip for Employee
		---------------------
		Name: Adi
		Gross Salary: Rp1.000.000,00
		Tax (20%): Rp200.000,00
		Installment: Rp100.000,00
		Insurance: Rp100.000,00
		Net Salary: Rp600.000,00

		2. ["Bryan", 0, 0, 0] -->
		Payslip for Employee
		---------------------
		Name: Bryan
		Gross Salary: Rp0,00
		Tax (20%): Rp0,00
		Installment: Rp0,00
		Insurance: Rp0,00
		Net Salary: Rp0,00
		
		3. ["Caca", 1000000000, 1, 1] -->
		Payslip for Employee
		---------------------
		Name: Caca
		Gross Salary: Rp1.000.000.000,00
		Tax (20%): Rp200.000.000,00
		Installment: Rp1,00
		Insurance: Rp1,00
		Net Salary: Rp799.999.998,00
	
	*/

	// Bagian ini untuk mengetes problem 1 yaitu Payslip Calculation
	if (
		paySlip("Adi", 1000000, 100000, 100000) ==
		"Payslip for Employee\n---------------------\nName: Adi\nGross Salary: Rp1.000.000,00\nTax (20%): Rp200.000,00\nInstallment: Rp100.000,00\nInsurance: Rp100.000,00\nNet Salary: Rp600.000,00"
	) {cout << "Payslip Calculation Test 1: SUCCESS" << endl;} else {cout << "Payslip Calculation Test 1: FAILED" << endl;}
	if (
		paySlip("Bryan", 0, 0, 0) ==
		"Payslip for Employee\n---------------------\nName: Bryan\nGross Salary: Rp0,00\nTax (20%): Rp0,00\nInstallment: Rp0,00\nInsurance: Rp0,00\nNet Salary: Rp0,00"
	) {cout << "Payslip Calculation Test 2: SUCCESS" << endl;} else {cout << "Payslip Calculation Test 2: FAILED" << endl;}
	if (
		paySlip("Caca", 1000000000, 1, 1) == 
		"Payslip for Employee\n---------------------\nName: Caca\nGross Salary: Rp1.000.000.000,00\nTax (20%): Rp200.000.000,00\nInstallment: Rp1,00\nInsurance: Rp1,00\nNet Salary: Rp799.999.998,00"
	) {cout << "Payslip Calculation Test 3: SUCCESS" << endl;} else {cout << "Payslip Calculation Test 3: FAILED" << endl;}


	/* Test Problem 2: Quadratic Problem
	  input format: a, b ,c 
	  
	  jika dua output:
	  output format: x_1, x_2
	  
	  jika satu output:
	  output format: x
	  
	  jika tidak ada output:
	  output format: Tidak ada
	  
	  [2, -1, -15] --> [3, -2.5]
	  [1, 2, 5] --> [Tidak ada]
	  [1, -4, 4] --> [2]
	*/ 
	cout << "-----------------------------------------------" << endl;
	
	// Bagian ini untuk mengetes problem 2 yaitu Quadratic Equation Solver
	if (
		realRoots(2, -1, -15) == "3 -2.5"
	) {cout << "Quadratic Equation Solver Test 1: SUCCESS" << endl;} else {cout << "Quadratic Equation Solver Test 1: FAILED" << endl;}
	if (
		realRoots(1, 2, 5) == "Tidak ada" 
	) {cout << "Quadratic Equation Solver Test 2: SUCCESS" << endl;} else {cout << "Quadratic Equation Solver Test 2: FAILED" << endl;}
	if (
		realRoots(1, -4, 4) == "2" 
	) {cout << "Quadratic Equation Solver Test 3: SUCCESS" << endl;} else {cout << "Quadratic Equation Solver Test 3: FAILED" << endl;}
	
}
