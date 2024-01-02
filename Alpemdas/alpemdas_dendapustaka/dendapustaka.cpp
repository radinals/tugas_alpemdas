#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

long long int str2num(string str);
long long int hitung_denda(string hari_dipinjam, int besar_denda,
                           int tempo_denda);
void print_data(int no, string nama, string hari, long long int denda);
void print_data(string no, string nama, string hari, string denda);

int
main()
{
	const int besar_denda = 5000; // rupiah
	const int tempo_denda = 7;    // hari
	                              //
	// jumlah data anggota yg akan disimpan
	int jumlah_peminjam = 0;

	cout << "Masukan Jumlah Data Peminjam: ";
	cin >> jumlah_peminjam;

	// jangan melanjutkan jika 'cin' gagal
	// atau jumlah yg di input kurang atau sama dengan 0
	if (cin.fail() || jumlah_peminjam <= 0)
		return -1;

	// 'kolom' hanya 2 karena jumlah data,
	// dan denda akan di dapatkan secara dinamis
	string data_peminjam[jumlah_peminjam][2];

	// inputkan data
	for (size_t i = 0; i < jumlah_peminjam; i++) {
		cout << endl;
		cout << "NO: " << i + 1 << endl;
		cout << "Masukan Nama          : ";
		cin >> data_peminjam[i][0];
		cout << "Masukan Hari Dipinjam : ";
		cin >> data_peminjam[i][1];
	}

	// outputkan header
	cout << "-------------------- DATA PEMINJAMAN BUKU "
	        "--------------------------"
	     << endl;
	print_data(string("NO"), string("NAMA ANGGOTA"),
	           string("LAMA HARI PEMINJAMAN"), string("DENDA (RP.)"));

	// outputkan data
	for (size_t i = 0; i < jumlah_peminjam; i++) {
		cout << "------------------------------------------------------"
		        "-------------"
		     << endl;
		print_data((int)i + 1, data_peminjam[i][0], data_peminjam[i][1],
		           (long long int)hitung_denda(
		               data_peminjam[i][1], besar_denda, tempo_denda));
	}
	cout << "--------------------------------------------------------------"
	        "-----"
	     << endl;

	cin.get();
	return 0;
}

void
print_data(size_t no, string nama, string hari, int denda)
{
	cout << "|" << right << setw(3) << no << setw(2) << "|" << left
	     << setw(20) << nama << setw(2) << "|" << right << setw(20) << hari
	     << setw(2) << "|" << right << setw(15) << denda << setw(2) << "|";
	cout << endl;
}

void print_data(string no, string nama, string, string hari, string denda);
{
	cout << "|" << right << setw(3) << no << setw(2) << "|" << left
	     << setw(20) << nama << setw(2) << "|" << right << setw(20) << hari
	     << setw(2) << "|" << right << setw(15) << denda << setw(2) << "|";
	cout << endl;
}

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
hitung_denda(string hari_dipinjam, int besar_denda, int tempo_denda)
{
	// denda dihitung dari per tempo yg di tentukan
	// misalkan tempo nya 7 hari, maka jika buku dipinjam
	// 13 hari, denda yg akan dikenakan adalah 13 hari dibagi 7,
	// maka didapatkan 1 yg kemudian di kalikan dengan besar denda.
	return besar_denda * (str2num(hari_dipinjam) / tempo_denda);
}
