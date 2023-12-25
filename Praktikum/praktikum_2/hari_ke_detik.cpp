#include <iostream>

using namespace std;

int 
main(void) 
{
	const int detik_sehari = 86400;
	int jumlah_hari;

	cout << "Masukan total hari: ";
	cin >> jumlah_hari;

	printf("%d Hari = %d Detik\n", jumlah_hari, jumlah_hari*detik_sehari);

	return 0;
}
