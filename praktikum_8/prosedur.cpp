#include <iostream>
#include <limits>
using namespace std;

void
clear_buffer()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void
luas_persegi()
{
	float panjang_sisi;

	cout << "Masukan Panjang Sisi: ";
	cin >> panjang_sisi;
	clear_buffer();

	cout << "Luas Persegi: " << panjang_sisi*panjang_sisi << endl;
}

void
luas_segitiga()
{
	float ukuran_alas, tinggi;

	cout << "Masukan Ukuran Alas: ";
	cin >> ukuran_alas;

	clear_buffer();

	cout << "Masukan Tinggi: ";
	cin >> tinggi;

	clear_buffer();

	cout << "Luas Segitiga: " << (0.5f * ukuran_alas * tinggi) << endl;
}

void
luas_lingkaran()
{
	float panjang_diameter, jari_jari;

	cout << "Masukan Panjang Diameter: ";
	cin >> panjang_diameter;

	clear_buffer();

	jari_jari = 0.5f * panjang_diameter;

	cout << "Luas Lingkaran: " << ((22.0f/7.0f) * jari_jari * jari_jari) << endl;
}

int
main()
{
	while (true)
	{
		int opsi;

		cout << endl;
		cout << "1. Luas Persegi" << endl;
		cout << "2. Luas Segitiga" << endl;
		cout << "3. Luas Lingkaran" << endl;
		cout << "4. Exit Program" << endl;

		cout << endl;
		cout << "Pilihan: ";
		cin >> opsi;

		switch (opsi)
		{
			case 1:
				cout << "Pilihan: Luas Persegi" << endl;;
				luas_persegi();
				break;
			case 2:
				cout << "Pilihan: Luas Segitiga" << endl;;
				luas_segitiga();
				break;
			case 3:
				cout << "Pilihan: Luas Lingkaran" << endl;;
				luas_lingkaran();
				break;
			case 4:
				return 0;

			default:
				clear_buffer();
				cout << "Input Invalid!" << endl;;
				continue;
		}
	}

	return 0;
}
