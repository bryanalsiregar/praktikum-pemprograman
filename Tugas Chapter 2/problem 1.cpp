/*
	File ini digunaka untuk menyelesaikan problem 1: Payslip Calculation
	Dijalankan di onlinegdb.com
*/
// Header yang digunakan untuk file ini
#include<iostream> // Untuk penggunaan I/O di C++
#include<string> // Untuk penggunaan tipe string dan manipulasinya
#include<algorithm> // Untuk menggunakan algoritma yang sudah dibuat sebelumnya

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

int main(){
	// Deklarasi variabel
	string name;
	ull salary, installment, insurance, tax;
	
	// Penggunaa prompt dan input
	cout << "Input your name" << endl;
	cin >> name;
	cout << "Input your gross salary cost" << endl;
	cin >> salary;
	cout << "Input your installment cost" << endl;
	cin >> installment;
	cout << "Input your insurance cost" << endl;
	cin >> insurance;
	
	// Penghitungan tax yang harus dibayar
	tax = salary*0.2;

	// Output dalam terminal
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "Payslip for Employee" << endl;
	cout << "---------------------" << endl;
	cout << "Name: " << name << endl;
	cout << "Gross Salary: Rp" << thousandSeparator(salary) << ",00" << endl;
	cout << "Tax (20%): Rp" << thousandSeparator(tax) << ",00" << endl;
	cout << "Installment: Rp" << thousandSeparator(installment) << ",00" << endl;
	cout << "Insurance: Rp" << thousandSeparator(insurance) << ",00" << endl;
	cout << "Net Salary: Rp" << thousandSeparator(salary-tax-installment-insurance) << ",00" << endl;
	return 0;
}
