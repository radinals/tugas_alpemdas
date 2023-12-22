#include <iostream>

using namespace std;

int
main()
{
	int t_detik, t_menit, t_jam, detik;

	cout << "Masukan jarak tempuh Jam : ";
	cin >> t_jam;

	cout << "Masukan jarak tempuh Menit : ";
	cin >> t_menit;

	cout << "Masukan jarak tempuh Detik : ";
	cin >> t_detik;

	detik = (t_jam * 3600) + (t_menit * 60) + t_detik;

	cout << "Jarak tempuh adalah " << detik << " detik" << endl;

	return 0;
}
