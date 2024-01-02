#include <iostream>

using namespace std;

int
main()
{
	int angka_pertama, angka_beda, jumlah_suku, sigma = 0;

	cout << "Masukan Angka Pertama: ";
	cin >> angka_pertama;

	cout << "Masukan Angka Beda   : ";
	cin >> angka_beda;

	cout << "Masukan Jumlah Suku  : ";
	cin >> jumlah_suku;

	cout << "Deret                : ";
	while ((jumlah_suku--) > 0) {
		cout << angka_pertama << " ";
		sigma += angka_pertama;
		angka_pertama += angka_beda;
	}

	cout << endl;
	cout << "Sigma N              : " << sigma << endl;

	return 0;
}
