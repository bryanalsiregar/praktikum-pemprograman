/*
	Program untuk penyelesaian nomor 1
	Soal:
		Buatlah program yang bisa menghitung nilai determinan dari sebuah persamaan
		kuadrat, kemudian tentukan nilai masing-masing akarnya. Setelah nilai determinan
		diketahui, terdapat 3 kemungkinan yang dapat menentukan akar-akar persamaan
		tersebut, yaitu:
			a. Jika D > 0, maka x1 dan x2 bersifat riil dan berbeda, rumus untuk penentuan
			   nilainya adalah sebagai berikut:
			   x1 = (-b + sqrt(D)) / 2a
			   x2 = (-b - sqrt(D)) / 2a
			b. Jika D = 0, maka x1 dan x2 bersifat riil dan sama
			c. Jika D < 0, maka x1 dan x2 bersifat imaginer
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
	cout << "Penyelesaian persamaan kuadrat ax^2 + bx + c"  << endl;
	cout << "Masukkan nilai a b c: ";
	cin >> a >> b >> c;
	
	// Penghitungan diskriminan
	disc = pow(b,2)-4*a*c;
	
	// Kasus jika diskriminan lebih dari 0
	if (disc > 0) {
		// Output pada terminal tentang real roots
		cout << "ada dua nilai akarnya, yaitu: " << endl;
		cout << "x_1: " << (-b+sqrt(disc))/(2*a) << endl;
		cout << "x_2: " << (-b-sqrt(disc))/(2*a) << endl;
	} else if (disc == 0) {
		// Kasus Jika diskriminan sama dengan 0	
		// Output pada terminal tentang real roots
		cout << "hanya ada satu akarnya, yaitu: " << endl;
		cout << "x: " << (-b)/(2*a) << endl;
	} else if(disc < 0) {
		// Kasus Jika diskriminan kurang dari 0
		// Ouput pada terminal tentang real roots
		cout << "tidak ada penyelesaian pada persamaan kuadrat tersebut" <<endl;
	}
	
	return 0;
}
