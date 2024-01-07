#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// FIXME: most of this is ugly, very ugly...

long long str2num(string str);
long long hitung_denda(string hari_dipinjam);

// using a template, too generic for overloading
template <typename T_NO, typename T_NAMA, typename T_HARI, typename T_DENDA>
void print_data(T_NO no, T_NAMA nama, T_HARI hari, T_DENDA denda);

void print_tabel(string data_peminjam[][2], int jumlah_peminjam);
void input_tabel(string data_peminjam[][2], int jumlah_peminjam);

string get_nama(string data[][2], size_t i);
string get_hari(string data[][2], size_t i);
void set_nama(string data[][2], size_t i);
void set_hari(string data[][2], size_t i);

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

	// hanya 2 kolom karena hanya akan digunakan
	// untuk nama dan hari
	string data_peminjam[jumlah_peminjam][2];

	// inputkan data
	input_tabel(data_peminjam, jumlah_peminjam);

	// outputkan header dan outputkan data
	print_tabel(data_peminjam, jumlah_peminjam);

	cin.get();

	return 0;
}

void
input_tabel(string data_peminjam[][2], int jumlah_peminjam)
{
	for (size_t i = 0; i < jumlah_peminjam; i++) {
		string nama, hari;

		cout << "\nNO: " << i + 1 << "\n";

		cout << "Masukan Nama          : ";
		set_nama(data_peminjam, i);

		cout << "Masukan Hari Dipinjam : ";
		set_hari(data_peminjam, i);
	}
}

void
print_tabel(string data_peminjam[][2], int jumlah_peminjam)
{
	// using lambda since it's relevant and used only in here
	// FIXME: the len should be determine by the longest line in the
	//	  table
	auto print_line = []() -> void { cout << string(70, '-') << "\n"; };

	print_line();
	print_data<string, string, string, string>(
	    "NO", "NAMA ANGGOTA", "LAMA HARI PEMINJAMAN", "DENDA (RP.)");

	for (size_t i = 0; i < jumlah_peminjam; i++) {
		print_line();

		string hari = get_hari(data_peminjam, i),
		       nama = get_nama(data_peminjam, i);

		long long besar_denda = hitung_denda(hari);

		print_data<size_t, string, string, long long>(i + 1, nama, hari,
		                                              besar_denda);
	}
	print_line();
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
set_nama(string data[][2], size_t i)
{
	cin >> data[i][0];
}

void
set_hari(string data[][2], size_t i)
{
	cin >> data[i][1];
}

template <typename T_NO, typename T_NAMA, typename T_HARI, typename T_DENDA>
void
print_data(T_NO no, T_NAMA nama, T_HARI hari, T_DENDA denda)
{
	cout << "|" << right << setw(3) << no << setw(2) << "|" << left
	     << setw(20) << nama << setw(2) << "|" << right << setw(20) << hari
	     << setw(2) << "|" << right << setw(15) << denda << setw(2) << "|";
	cout << "\n";
}

// TODO:
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
