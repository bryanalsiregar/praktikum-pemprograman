/*
	File ini berisi mengenai penyelesaian pada problem 2: Quadratic Equation Solver
	Dijalankan di onlinegdb.com
*/

// Header file yang digunakan
#include<iostream> // Untuk mengatur I/O C++
#include<math.h> // Untuk menggunakan fungsi matematika yang tidak ada pada default C++

// Pengguanaan scope std
using namespace std;

int main() {
	// Deklarasi variabel yang dibutuhkan
	float a, b, c, disc, x_1, x_2;
	// Input untuk mengambil data dari user
	cin >> a >> b >> c;
	
	// Penghitungan diskriminan
	disc = pow(b,2)-4*a*c;
	
	// Kasus jika diskriminan lebih dari 0
	if (disc > 0) {
		// Output pada terminal tentang real roots
		cout << "there are two distinct real root: " << endl;
		cout << "x_1: " << (-b+sqrt(disc))/(2*a) << endl;
		cout << "x_2: " << (-b-sqrt(disc))/(2*a) << endl;
	}
	// Kasus Jika diskriminan sama dengan 0
	if (disc == 0) {
		// Output pada terminal tentang real roots
		cout << "there are exactly one real root: " << endl;
		cout << "x: " << (-b)/(2*a) << endl;
	}
	// Kasus jika diskriminan kurang dari 0
	if (disc < 0) {
		// Ouput pada terminal tentang real roots
		cout << "there are no real roots (the roots are complex)" <<endl;
	}
	
	return 0;
}
