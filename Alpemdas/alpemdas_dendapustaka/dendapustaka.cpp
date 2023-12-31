#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

// FIXME: most of this is ugly, very ugly...

long long str2num(string str);
long long hitung_denda(string hari_dipinjam);

void print_data(string no, string nama, string hari, string denda);

void print_tabel(string data_peminjam[][2]);
void input_tabel(string data_peminjam[][2]);

string get_nama(string data[][2], size_t i);
string get_hari(string data[][2], size_t i);
void set_nama(string data[][2], size_t i);
void set_hari(string data[][2], size_t i);
void validate_index(size_t index);

const int besar_denda = 5000; // rupiah
const int tempo_denda = 7;    // hari

// maximal panjang kolom
const size_t max_col_length = 20;

// jumlah data anggota yg akan disimpan
int jumlah_peminjam = 0;

int
main()
{
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
	input_tabel(data_peminjam);

	// outputkan header dan outputkan data
	print_tabel(data_peminjam);

	cin.get();

	return 0;
}

void
input_tabel(string data_peminjam[][2])
{
	for (size_t i = 0; i < jumlah_peminjam; i++) {
		try {
			validate_index(i);
		} catch (std::out_of_range) {
			break;
		}

		string nama, hari;

		cout << "\nNO: " << i + 1 << "\n";

		validate_index(i);

		cout << "Masukan Nama          : ";
		set_nama(data_peminjam, i);

		cout << "Masukan Hari Dipinjam : ";
		set_hari(data_peminjam, i);
	}
}

void
print_tabel(string data_peminjam[][2])
{
	// using lambda since it's relevant and used only in here
	// FIXME: the len should be determine by the longest line in the
	//	  table
	// total panjang kolom + jumlah_pemisah + jumlah buffer pemisah
	auto print_line = []() -> void {
		cout << string(((max_col_length * 3) + (3 + (5 * 2))), '-')
		     << "\n";
	};

	print_line();
	print_data("NO", "NAMA ANGGOTA", "LAMA HARI PEMINJAMAN", "DENDA (RP.)");

	for (size_t i = 0; i < jumlah_peminjam; i++) {
		try {
			validate_index(i);
		} catch (std::out_of_range) {
			break;
		}

		print_line();

		string hari, nama;
		hari = get_hari(data_peminjam, i);
		nama = get_nama(data_peminjam, i);

		if (nama.empty() || hari.empty())
			continue;

		long long besar_denda = hitung_denda(hari);

		print_data(to_string(i + 1), nama, hari,
		           to_string(besar_denda));
	}
	print_line();
}

void
print_data(string no, string nama, string hari, string denda)
{
	cout << "|" << right << setw(3) << no << setw(2) << "|" << left
	     << setw(max_col_length) << nama << setw(2) << "|" << right
	     << setw(max_col_length) << hari << setw(2) << "|" << right
	     << setw(max_col_length) << denda << setw(2) << "|";
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

string
get_nama(string data[][2], size_t i)
{
	return data[i][0];
}

string
get_hari(string data[][2], size_t i)
{
	string hari = data[i][1];

	if (hari.length() > max_col_length)
		hari = hari.substr(0, max_col_length);

	return data[i][1];
}

void
set_nama(string data[][2], size_t i)
{

	cin.clear();
	cin.ignore();

	string nama;
	getline(cin, nama);

	// truncate the name if longer than name_max_len
	if (nama.length() > max_col_length) {
		nama = nama.substr(0, max_col_length - 3);
		nama += "...";
	}

	data[i][0] = nama;
}

void
set_hari(string data[][2], size_t i)
{
	cin >> data[i][1];
}

void
validate_index(size_t index)
{
	if (index >= jumlah_peminjam)
		throw std::out_of_range("ERROR: attempted to access/modify an "
		                        "out of bound index!\n");
};
