/*
	Program untuk penyelesaian soal nomor 2;
	Soal:
		Buatlah sebuah program untuk menentukan bilangan terbesar dari 3 buah bilangan
		yang diinputkan oleh user.
		Contoh: inputkan bilangan 1: 15
				inputkan bilangan 2: 7
				inputkan bilangan 3: 22
				bilangan terbesar adalah: 22
*/

#include<iostream>

using namespace std;

int main() {
	// Deklarasi variabel yang dibutuhkan
	float a, b, c, output;
	
	// Menanyakan user untuk masukkan bilangan 1
	cout << "inputkan bilangan 1: ";
	cin >> a;
	// Menggantikan output dengan nilai bilangan 1
	output = a;
	// Menanyakan user untuk masukkan bilangan 2
	cout << "inputkan bilangan 2: ";
	cin >> b;
	// Mengganti nilai variabel output dengan nilai variabel b jika lebih besar, jika lebih kecil maka dengan nilai variabel a
	if (b > output) {
		output = b;
	} else {
		output = a;
	}
	// Menanyakan user untuk masukkan bilangan 3
	cout << "inputkan bilangan 3: ";
	cin >> c;
	// Mengganti nilai variabel output dengan nilai variabel c jika lebih besar, jika lebih kecil maka dengan nilai variabel b
	if (c > output) {
		output = c;
	} else {
		output = b;
	}
	
	// Keluarkan output dari program
	cout << "bilangan terbesar adalah: "<<output;
	
	return 0;
}

