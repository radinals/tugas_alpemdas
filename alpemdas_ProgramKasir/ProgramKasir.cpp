
#include <iostream>
#include <limits>

using namespace std;

void
clear_screen()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void
prompt(string s)
{
	cout << s;
	cout.flush();
}

void
get_num(int &v)
{
	cin >> v;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

int
main()
{
	string nama_kasir, nama_barang;

	int harga_barang, jumlah_barang, no_barang, total_barang, diskon,
		pembayaran, kembalian;

	harga_barang = jumlah_barang = no_barang = total_barang = diskon =
		pembayaran = kembalian = -1;

	while(true) {
		clear_screen();
		prompt("******************* KASIR KELONTONG v0.1 ***********************\n");
		prompt(" NAMA KASIR                    : ");
		if (nama_kasir.empty())
			getline(cin, nama_kasir);
		else
			prompt(nama_kasir + "\n");

		prompt(" NO BARANG                     : ");
		if (no_barang < 0)
			get_num(no_barang);
		else
			prompt(to_string(no_barang)+"\n");

		prompt(" NAMA BARANG                   : ");
		if (nama_barang.empty())
			getline(cin, nama_barang);
		else
			prompt(nama_barang + "\n");

		prompt(" HARGA                         : Rp.");
		if (harga_barang < 0)
			get_num(harga_barang);
		else
			prompt(to_string(harga_barang)+"\n");

		prompt(" JUMLAH BARANG                 : ");
		if (jumlah_barang < 0)
			get_num(jumlah_barang);
		else
			prompt(to_string(jumlah_barang)+"\n");

		prompt("****************************************************************\n");

		total_barang = (diskon < 0 ) ? harga_barang*jumlah_barang : (harga_barang*jumlah_barang)-diskon;
		if (total_barang < 0) total_barang = 0;

		prompt(" JUMLAH YANG HARUS DI BAYAR    : Rp." + to_string(total_barang) + "\n");

		prompt(" POTONGNAN                     : Rp.");
		if (diskon < 0) {
			get_num(diskon);
			clear_screen();
			continue;

		} else 
			prompt(to_string(diskon)+"\n");

		prompt(" PEMBAYARAN                    : Rp.");
		if (pembayaran < 0) 
			get_num(pembayaran);
		else
			prompt(to_string(pembayaran)+"\n");

		if (pembayaran < total_barang ) {
			prompt("Maaf uang anda kurang!...\nTRANSAKSI DIBATALKAN");
			return -1;
		}

		kembalian = abs(total_barang-pembayaran);

		prompt(" KEMBALIAN                     : Rp." + to_string(kembalian)+"\n");
		prompt("****************************************************************\n");
		
		break; // exit the loop
	}

	prompt("                     TERIMA KASIH TELAH BELANJA                 \n");
	prompt("****************************************************************\n");

	return 0;
}

