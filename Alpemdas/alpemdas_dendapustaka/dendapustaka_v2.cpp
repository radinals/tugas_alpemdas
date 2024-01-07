#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

struct Peminjam;

long long hitung_denda(long long hari_dipinjam);
void input_tabel(Peminjam data_peminjam[], int jumlah_peminjam);
void print_data(size_t no, string nama, long long hari, long long denda);
void print_data(string no, string nama, string hari, string denda);
void print_tabel(Peminjam data_peminjam[], int jumlah_peminjam);

const int besar_denda = 5000; // rupiah
const int tempo_denda = 7;    // hari

// dengan menggunakan struct
// untuk menyimpan data bertipe data beda
// dalam suatu wadah yang sama.

// menggunakan typedef hanya untuk
// mempersingkat deklarasi nantinya
// jadi melainkan
// struct Peminjam var; menjadi
// Peminjam var;
typedef struct Peminjam {
	string nama;
	long long lama_peminjaman;
} Peminjam;

int
main()
{
	int jumlah_peminjam = 0;

	cout << "Masukan Jumlah Data Peminjam: ";
	cin >> jumlah_peminjam;

	if (cin.fail() || jumlah_peminjam <= 0)
		return -1;

	Peminjam data_peminjam[jumlah_peminjam];

	// inputkan data
	input_tabel(data_peminjam, jumlah_peminjam);

	// outputkan header
	// outputkan data
	print_tabel(data_peminjam, jumlah_peminjam);

	return 0;
}

void
input_tabel(Peminjam data_peminjam[], int jumlah_peminjam)
{
	for (size_t i = 0; i < jumlah_peminjam; i++) {
		string nama, hari;

		cout << "\nNO: " << i + 1 << "\n";

		cout << "Masukan Nama          : ";
		cin >> data_peminjam->nama;

		cout << "Masukan Hari Dipinjam : ";
		cin >> data_peminjam->lama_peminjaman;
	}
}

void
print_tabel(Peminjam data_peminjam[], int jumlah_peminjam)
{
	// using lambda since it's relevant and used only in here
	auto print_line = []() -> void { cout << string(70, '-') << "\n"; };

	print_line();
	print_data("NO", "NAMA ANGGOTA", "LAMA HARI PEMINJAMAN", "DENDA (RP.)");

	for (size_t i = 0; i < jumlah_peminjam; i++) {
		print_line();

		string nama = data_peminjam[i].nama;
		long long hari = data_peminjam[i].lama_peminjaman;
		long long besar_denda = hitung_denda(hari);

		print_data(i + 1, nama, hari, besar_denda);
	}
	print_line();
}

long long
hitung_denda(long long hari_dipinjam)
{
	// denda dihitung dari per tempo yg di tentukan
	// misalkan tempo nya 7 hari, maka jika buku dipinjam
	// 13 hari, denda yg akan dikenakan adalah 13 hari dibagi 7,
	// maka didapatkan 1 yg kemudian di kalikan dengan besar denda.
	return (besar_denda * (hari_dipinjam) / tempo_denda);
}

void
print_data(size_t no, string nama, long long hari, long long denda)
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
