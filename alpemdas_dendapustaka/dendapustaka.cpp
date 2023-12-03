#include <iostream>
#include <iomanip>
#include <ios>
#include <sstream>
#include <string>

using namespace std;

const int besar_denda = 5000;
const int tempo_denda = 7;

long long int
str2int(string str)
{
	long long int tmp;
	stringstream s;

	s << str;
	s >> tmp;

	return tmp;
}

int
hitung_denda(string hari_dipinjam)
{
	return besar_denda * (str2int(hari_dipinjam) / tempo_denda);
}

int
main()
{
	int jumlah_peminjam = 0;

	cout << "Masukan Jumlah Data Peminjam: ";
	cin >> jumlah_peminjam;

	if (jumlah_peminjam <= 0 ) return -1;

	string data_peminjam[jumlah_peminjam][2];

	for(size_t i=0; i < jumlah_peminjam; i++ ) {
		cout << endl;
		cout << "NO: " << i+1 << endl;
		cout << "Masukan Nama          : ";
		cin  >> data_peminjam[i][0];
		cout << "Masukan Hari Dipinjam : ";
		cin  >> data_peminjam[i][1];
	}

	cout << "-------------------- DATA PEMINJAMAN BUKU --------------------------" << endl;
	cout << "|" <<
		right << setw(3)  << "NO"                    << setw(2) << "|" <<
		left  << setw(20) << "NAMA ANGGOTA"          << setw(2) << "|" <<
		right << setw(15) << "LAMA HARI PEMINJAMAN"  << setw(2) << "|" <<
		right << setw(15) << "DENDA (RP.)"           << setw(2) << "|";
	cout << endl;

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
