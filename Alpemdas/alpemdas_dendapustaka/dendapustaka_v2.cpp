#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

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
	long long int lama_peminjaman;
} Peminjam;

long long int
hitung_denda(long long int hari_dipinjam)
{
	// denda dihitung dari per tempo yg di tentukan
	// misalkan tempo nya 7 hari, maka jika buku dipinjam
	// 13 hari, denda yg akan dikenakan adalah 13 hari dibagi 7,
	// maka didapatkan 1 yg kemudian di kalikan dengan besar denda.
	return (besar_denda * (hari_dipinjam) / tempo_denda);
}

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
	for (size_t i = 0; i < jumlah_peminjam; i++) {
		cout << endl;
		cout << "NO: " << i + 1 << endl;
		cout << "Masukan Nama          : ";
		cin >> data_peminjam[i].nama;
		cout << "Masukan Hari Dipinjam : ";
		cin >> data_peminjam[i].lama_peminjaman;
	}

	// outputkan header
	cout << "-------------------- DATA PEMINJAMAN BUKU "
	        "--------------------------"
	     << endl;

	cout << "|" << right << setw(3) << "NO" << setw(2) << "|" << left
	     << setw(20) << "NAMA ANGGOTA" << setw(2) << "|" << right
	     << setw(15) << "LAMA HARI PEMINJAMAN" << setw(2) << "|" << right
	     << setw(15) << "DENDA (RP.)" << setw(2) << "|";
	cout << endl;

	// outputkan data
	for (size_t i = 0; i < jumlah_peminjam; i++) {
		cout << "------------------------------------------------------"
		        "-------------"
		     << endl;
		cout << "|" << right << setw(3) << i + 1 << setw(2) << "|"
		     << left << setw(20) << data_peminjam[i].nama << setw(2)
		     << "|" << right << setw(20)
		     << data_peminjam[i].lama_peminjaman << setw(2) << "|"
		     << right << setw(15)
		     << hitung_denda(data_peminjam[i].lama_peminjaman)
		     << setw(2) << "|";
		cout << endl;
	}

	cout << "--------------------------------------------------------------"
	        "-----"
	     << endl;

	return 0;
}
