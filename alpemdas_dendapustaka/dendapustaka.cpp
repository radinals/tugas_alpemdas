#include <iostream>
#include <iomanip>
#include <ios>
#include <sstream>
#include <string>

using namespace std;

const int besar_denda = 5000; // rupiah
const int tempo_denda = 7; // hari

// menggunakan long long int
// karena ini merubah string ke angka,
// besar angka tidak diketauhi.
long long int
str2num(string str)
{
	long long int tmp;
	stringstream s;

	s << str;
	s >> tmp;

	return tmp;
}

long long int
hitung_denda(string hari_dipinjam)
{
	// denda dihitung dari per tempo yg di tentukan
	// misalkan tempo nya 7 hari, maka jika buku dipinjam
	// 13 hari, denda yg akan dikenakan adalah 13 hari dibagi 7,
	// maka didapatkan 1 yg kemudian di kalikan dengan besar denda.
	return besar_denda * (str2num(hari_dipinjam) / tempo_denda);
}

int
main()
{
	// jumlah data anggota yg akan disimpan
	int jumlah_peminjam = 0;

	cout << "Masukan Jumlah Data Peminjam: ";
	cin >> jumlah_peminjam;

	// jangan melanjutkan jika 'cin' gagal
	// atau jumlah yg di input kurang atau sama dengan 0
	if (cin.fail() || jumlah_peminjam <= 0 )
		return -1;

	// 'kolom' hanya 2 karena jumlah data,
	// dan denda akan di dapatkan secara dinamis
	string data_peminjam[jumlah_peminjam][2];

	// inputkan data
	for(size_t i=0; i < jumlah_peminjam; i++ ) {
		cout << endl;
		cout << "NO: " << i+1 << endl;
		cout << "Masukan Nama          : ";
		cin  >> data_peminjam[i][0];
		cout << "Masukan Hari Dipinjam : ";
		cin  >> data_peminjam[i][1];
	}

	// outputkan header
	cout << "-------------------- DATA PEMINJAMAN BUKU --------------------------" << endl;
	cout << "|" <<
		right << setw(3)  << "NO"                    << setw(2) << "|" <<
		left  << setw(20) << "NAMA ANGGOTA"          << setw(2) << "|" <<
		right << setw(15) << "LAMA HARI PEMINJAMAN"  << setw(2) << "|" <<
		right << setw(15) << "DENDA (RP.)"           << setw(2) << "|";
	cout << endl;

	// outputkan data
	for(size_t i=0; i < jumlah_peminjam; i++ ) {
		cout << "-------------------------------------------------------------------" << endl;
		cout << "|" <<
			right << setw(3) << i+1                                << setw(2) << "|" <<
			left  << setw(20) << data_peminjam[i][0]               << setw(2) << "|" <<
			right << setw(20) << data_peminjam[i][1]               << setw(2) << "|" <<
			right << setw(15) << hitung_denda(data_peminjam[i][1]) << setw(2) << "|";
		cout << endl;
	}

	cout << "-------------------------------------------------------------------" << endl;

	return 0;
}
