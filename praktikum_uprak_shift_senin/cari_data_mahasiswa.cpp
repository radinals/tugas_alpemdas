#include <iostream>
using namespace std;

typedef struct DataMahasiswa{
	string name;
	string npm;
} DataMahasiswa;

int
main()
{
	size_t jumlah_mahasiswa;

	cout << "Masukan Jumlah Mahasiswa: ";
	cin >> jumlah_mahasiswa;

	// DataMahasiswa data_mahasiswa[jumlah_mahasiswa];
	string data_mahasiswa[jumlah_mahasiswa][2];

	for(size_t i=0; i < jumlah_mahasiswa; i++)
	{
		cout << "Masukan NPM:";
		cin >> data_mahasiswa[i][0];

		cout << "Masukan Nama:";
		cin >> data_mahasiswa[i][1];

		cout << "\n";
	}

	for(size_t i=0; i < jumlah_mahasiswa; i++)
	{
		cout << "NAMA: ";
		cout << data_mahasiswa[i][1] << "\n";

		cout << "NPM: ";
		cout << data_mahasiswa[i][0] << "\n";

		cout << "\n";
	}

	bool found = false;
	string npm_dicari;

	cout << "Masukan NPM yang dicari: ";
	cin >> npm_dicari;

	for (size_t i=0; i < jumlah_mahasiswa; i++)
	{
		if (npm_dicari != data_mahasiswa[i][0]) continue;

		cout << "Nama: " << data_mahasiswa[i][1] << "\n";
		cout << "NPM: " << data_mahasiswa[i][0] << "\n";
	}
}
