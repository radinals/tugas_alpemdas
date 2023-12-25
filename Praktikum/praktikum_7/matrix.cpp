#include <iostream>
using namespace std;

int main()
{
	int baris_matrix, kolom_matrix;
	baris_matrix = kolom_matrix = 0;

	while(kolom_matrix <= 0 || baris_matrix <= 0) {
		cout << "Masukan Jumlah Baris Matrix: ";
		cin >> baris_matrix;

		cout << "Masukan Jumlah Kolom Matrix: ";
		cin >> kolom_matrix;

		cin.ignore();
	}

	cout << endl;

	int matrix_1[baris_matrix][kolom_matrix];
	int matrix_2[baris_matrix][kolom_matrix];

	cout << "Matrix ke-1" << endl;;
	for(size_t y=0; y < baris_matrix; y++) {
		for(size_t x=0; x < kolom_matrix; x++) {
			cout << " - Masukan Angka (" << y << ", " << x << ") :";
			cin >> matrix_1[y][x];
			cin.ignore();
		}
	}

	cout << endl;

	cout << "Matrix ke-2" << endl;;
	for(size_t y=0; y < baris_matrix; y++) {
		for(size_t x=0; x < kolom_matrix; x++) {
			cout << " - Masukan Angka (" << y << ", " << x << ") :";
			cin >> matrix_2[y][x];
			cin.ignore();
		}
	}

	cout << endl;

	cout << "Matrix ke-1" << endl;;
	for(size_t y=0; y < baris_matrix; y++) {
		for(size_t x=0; x < kolom_matrix; x++)
			cout << matrix_1[y][x] << " ";
		cout << endl;
	}

	cout << "Matrix ke-2" << endl;;
	for(size_t y=0; y < baris_matrix; y++) {
		for(size_t x=0; x < kolom_matrix; x++)
			cout << matrix_2[y][x] << " ";
		cout << endl;
	}

	return 0;
}
