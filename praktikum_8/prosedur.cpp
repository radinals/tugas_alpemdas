#include <iostream>
#include <limits>

using namespace std;

// gunakan "cls" jika di windows
#define clear_console system("clear");

void
clear_buffer()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void
get_input(int& var)
{
	cin >> var;
	clear_buffer();
}

void
get_input(float& var)
{
	cin >> var;
	clear_buffer();
}

void
luas_persegi()
{
	float panjang_sisi;

	cout << "-> Masukan Panjang Sisi: ";
	get_input(panjang_sisi);


	cout << "Luas Persegi adalah, " << panjang_sisi*panjang_sisi << " cm" << endl;
}

void
luas_segitiga()
{
	float ukuran_alas, tinggi;

	cout << "-> Masukan Ukuran Alas: ";
	get_input(ukuran_alas);

	cout << "-> Masukan Tinggi: ";
	get_input(tinggi);

	cout << "Luas Segitiga adalah, " << (0.5f * ukuran_alas * tinggi) << " cm" << endl;
}

void
luas_lingkaran()
{
	float panjang_diameter, jari_jari;

	cout << "-> Masukan Panjang Diameter: ";
	get_input(panjang_diameter);

	jari_jari = 0.5f * panjang_diameter;

	cout << "Luas Lingkaran adalah, " << ((22.0f/7.0f) * jari_jari * jari_jari) << " cm" << endl;
}

int
main()
{
	while (true)
	{
		clear_console

		int opsi;

		cout << endl;
		cout << "1. Luas Persegi" << endl;
		cout << "2. Luas Segitiga" << endl;
		cout << "3. Luas Lingkaran" << endl;
		cout << "4. Exit Program" << endl;

		cout << endl;
		cout << "Pilihan: ";
		get_input(opsi);

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
				cout << "Input Invalid!" << endl;;
				cin.get();
				continue;
		}

		cin.get();
	}

	return 0;
}
