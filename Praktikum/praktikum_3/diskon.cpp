#include <iostream>
using namespace std;

int
main()
{
	int harga;
	float persen_diskon = 0.10f;

	cout << "Masukan Nominal Belanja: Rp.";
	cin >> harga;

	if (harga >= 100000) {
		cout << "Anda Berhak untuk Mendapatkan Diskon 10%!\n";
		harga -= (harga * persen_diskon);

	} else if (harga <= 0) {
		cout << "Tidak Ada yang Harus Dibayar!\n";
		return -1;

	} else
		cout << "Anda Belum Berhak untuk Mendapatkan Diskon 10%!\n";

	cout << "Total yang Harus Dibayar: Rp." << harga << "\n";

	return 0;
}
