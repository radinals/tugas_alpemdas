#include <cmath>
#include <iostream>

using namespace std;

double
perpangkatan(double n, int pangkat)
{
	double hasil = n;
	bool pangkat_negatif = false;

	if (pangkat == 0) {
		return 1;
	} else if (pangkat == 1) {
		return n;
	} else if (pangkat < 0) {

		// rumus pangkat negatif
		// a^-n = 1 / a^n

		pangkat = abs(pangkat);
		pangkat_negatif = true;
	}

	for (size_t i = 1; i < pangkat; i++) hasil *= n;

	if (pangkat_negatif)
		return (1.0f / hasil);

	return hasil;
}

int
main()
{
	double angka, pangkat;

	cout << "Masukan Angka: ";
	cin >> angka;

	cout << "Masukan Pangkat: ";
	cin >> pangkat;

	cout << "perpangkatan(): " << (perpangkatan(angka, pangkat)) << endl;
	;
	cout << "pow(): " << (pow(angka, pangkat)) << endl;
	;

	return 0;
}
