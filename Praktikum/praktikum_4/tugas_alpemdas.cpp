#include <iostream>
using namespace std;
int
main()
{
	int opsi;
	float x, y;

	cout << "1. Volume Kubus\n2. Luas Lingkaran\n3. Volume Silinder\n";
	cout << "Inputkan Pilihan Anda: ";
	cin >> opsi;

	switch (opsi) {
	case 1:
		cout << "Masukan Panjang Sisi Kubus (cm): ";
		cin >> x;
		cout << "Volume Kubus (cm): " << (x * x * x) << " cm" << endl;
		break;

	case 2:
		cout << "Masukan Panjang Jari-Jari Lingkaran (cm): ";
		cin >> x;
		cout << "Luas Lingkaran: " << ((22.0f / 7.0f) * x * x) << " cm"
		     << endl;
		break;

	case 3:
		cout << "Masukan Panjang Jari-Jari Alas Tabung (cm): ";
		cin >> x;
		cout << "Masukan Tinggi Tabung (cm): ";
		cin >> y;
		cout << "Volume Silinder: " << ((22.0f / 7.0f) * x * x * y)
		     << " cm" << endl;
		break;

	default:
		cout << "ERROR: '" << opsi << "' Bukan Pilihan Valid!" << endl;
		return -1;
	}

	return 0;
}
