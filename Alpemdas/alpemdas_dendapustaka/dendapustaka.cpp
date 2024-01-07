#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

long long str2num(string str);
long long hitung_denda(string hari_dipinjam);
void print_data(size_t no, string nama, string hari, long long denda);
void print_data(string no, string nama, string hari, string denda);
string get_nama(string data[][2], size_t i);
string get_hari(string data[][2], size_t i);

const int besar_denda = 5000; // rupiah
const int tempo_denda = 7;    // hari

int
main()
{
	// jumlah data anggota yg akan disimpan
	int jumlah_peminjam = 0;

	cout << "Masukan Jumlah Data Peminjam: ";
	cin >> jumlah_peminjam;

	// jangan melanjutkan jika 'cin' gagal
	// atau jumlah yg di input kurang atau sama dengan 0
	if (cin.fail() || jumlah_peminjam <= 0)
		return -1;

	auto print_line = []() -> void { cout << string(70, '-') << "\n"; };

	// 'kolom' hanya 2 karena jumlah data,
	// dan denda akan di dapatkan secara dinamis
	string data_peminjam[jumlah_peminjam][2];

	// inputkan data
	for (size_t i = 0; i < jumlah_peminjam; i++) {
		cout << "\n";
		cout << "NO: " << i + 1 << "\n";
		cout << "Masukan Nama          : ";
		cin >> data_peminjam[i][0];
		cout << "Masukan Hari Dipinjam : ";
		cin >> data_peminjam[i][1];
	}

	// outputkan header
	print_line();
	print_data("NO", "NAMA ANGGOTA", "LAMA HARI PEMINJAMAN", "DENDA (RP.)");

	// outputkan data
	for (size_t i = 0; i < jumlah_peminjam; i++) {
		print_line();

		string hari = get_hari(data_peminjam, i),
		       nama = get_nama(data_peminjam, i);

		long long besar_denda = hitung_denda(hari);

		print_data(i + 1, nama, hari, besar_denda);
	}
	print_line();

	cin.get();
	return 0;
}

string
get_nama(string data[][2], size_t i)
{
	return data[i][0];
}

string
get_hari(string data[][2], size_t i)
{
	return data[i][1];
}

void
print_data(size_t no, string nama, string hari, long long denda)
{
	cout << "|" << right << setw(3) << no << setw(2) << "|" << left
	     << setw(20) << nama << setw(2) << "|" << right << setw(20) << hari
	     << setw(2) << "|" << right << setw(15) << denda << setw(2) << "|";
	cout << "\n";
}

void
print_data(string no, string nama, string hari, string denda)
{
	cout << "|" << right << setw(3) << no << setw(2) << "|" << left
	     << setw(20) << nama << setw(2) << "|" << right << setw(20) << hari
	     << setw(2) << "|" << right << setw(15) << denda << setw(2) << "|";
	cout << "\n";
}

// menggunakan long long
// karena ini merubah string ke angka,
// besar angka tidak diketauhi.
long long
str2num(string str)
{
	long long tmp;
	stringstream s;

	s << str;
	s >> tmp;

	return tmp;
}

long long
hitung_denda(string hari_dipinjam)
{
	// denda dihitung dari per tempo yg di tentukan
	// misalkan tempo nya 7 hari, maka jika buku dipinjam
	// 13 hari, denda yg akan dikenakan adalah 13 hari dibagi 7,
	// maka didapatkan 1 yg kemudian di kalikan dengan besar denda.
	return besar_denda * (str2num(hari_dipinjam) / tempo_denda);
}
