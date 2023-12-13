#include <iostream>
#include <iomanip>
#include <ios>

using namespace std;

// dapatkan panjang suatu array
// WARNING: menghitung panjang suatu array, bkn jumlah elemen
#define arr_size(arr) (sizeof(arr) / sizeof(arr[0]))

void pecahan(int nominal);

int
main()
{
	int uang;

	cout << "inputkan jumlah uang: ";
	cin >> uang;

	cout << "UANG: " << uang << endl;
	pecahan(uang);

	return 0;
}

// hitung jumlah pecahan
void
pecahan(int nominal)
{
	int kelipatan[] = {
		100000, 50000, 20000,
		5000, 2000, 1000, 500,
		200, 100, 10, 1
	};

	for (size_t i=0; i < arr_size(kelipatan); i++)
	{
		// dapatkan jumlah lembar
		int pecahan = ( nominal / kelipatan[i] );

		// output
		cout << left << "Rp." << left << setw(8)
			<< kelipatan[i] << ": " << pecahan << endl;

		// kurangi nominal dengan total (pecahan * kelipatan)
		// agar di nominal di iterasi berikutnya menggunakan
		// nominal yang sudah dikurangi kelipatan sebelumnya
		nominal -= ( kelipatan[i] * pecahan );
	}
}
