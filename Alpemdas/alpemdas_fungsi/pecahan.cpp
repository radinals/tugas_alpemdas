#include <iomanip>
#include <ios>
#include <iostream>

using namespace std;

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
	int kelipatan[] = {100000, 50000, 20000, 5000, 2000, 1000,
	                   500,    200,   100,   10,   1};

	for (size_t i = 0; i < (sizeof(kelipatan) / sizeof(kelipatan[0]));
	     i++) {
		// dapatkan jumlah lembar
		int pecahan = (nominal / kelipatan[i]);

		// output
		cout << left << "Rp." << left << setw(8) << kelipatan[i] << ": "
		     << pecahan << endl;

		// kurangi nominal dengan total (pecahan * kelipatan)
		// agar di nominal di iterasi berikutnya menggunakan
		// nominal yang sudah dikurangi kelipatan sebelumnya
		nominal -= (kelipatan[i] * pecahan);
	}
}
