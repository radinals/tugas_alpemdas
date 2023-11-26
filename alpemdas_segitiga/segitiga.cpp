#include <iostream>
using namespace std;

void
segitiga(char c1, char c2, int baris)
{
	for (int y = 0; y < baris; y++) {

		// spasi
		for (int x = 0; x < baris - y; x++)
			cout << c2;

		// badan
		for (int x = 0; x <= y * 2; x++)
			cout << c1;

		// spasi
		for (int x = 0; x < baris - y; x++)
			cout << c2;

		cout << endl;
	}
}

void
segitiga_terbalik(char c1, char c2, int baris)
{

	for (int y = baris-1; y >= 0; y--) {
		// spasi
		for (int x = y; x < baris; x++)
			cout << c2;

		// badan
		for (int x = 0; x <= y * 2; x++)
			cout << c1;

		// spasi
		for (int x = 0; x < baris - y; x++)
			cout << c2;

		cout << endl;
	}
}

int
main()
{
	int baris = 5;

	segitiga('*', ' ', baris);

	cout << endl;

	segitiga_terbalik('*', ' ', baris);

	cout << endl;

	segitiga('*', ' ', baris);
	segitiga('*', ' ', baris);

	cout << endl;

	segitiga('*', ' ', baris);
	segitiga_terbalik('*', ' ', baris);
}
