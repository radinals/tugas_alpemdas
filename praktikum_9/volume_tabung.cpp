#include <iostream>
#include <limits>
using namespace std;

const float PHI = (22.0f/7.0f);

bool
get_input(int& var)
{
	cin >> var;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "ERROR: INPUT SALAH!\n";
		return false;
	}

	return true;
}

bool
get_input(float& var)
{
	cin >> var;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "ERROR: INPUT SALAH!\n";
		return false;
	}

	return true;
}

float
luas_permukaan_tabung(float jari_jari, float tinggi)
{
	return 2.0f * PHI * jari_jari * (jari_jari + tinggi);
}

float
volume_tabung(float jari_jari, float tinggi)
{
	return PHI * (jari_jari*jari_jari) * tinggi;
}

int
main()
{
	int opsi;
	float jari_jari, tinggi, hasil;

	cout << "==============================================" << endl;

	while(true) {
		cout << "\n";
		cout << "1. Luas Permukaan Tabung\n";
		cout << "2. Volume Tabung\n";

		cout << "pilihan <1-2>:";
		if(get_input(opsi) == false || (opsi != 1 && opsi != 2) ) continue;;

		cout << '\n';

		cout << "- Inputkan Jari-Jari : ";
		if(get_input(jari_jari) == false ) continue;;

		cout << "- Inputkan Tinggi    : ";
		if(get_input(tinggi) == false ) continue;;

		cout << '\n';

		if (opsi == 1)
			hasil = luas_permukaan_tabung(jari_jari, tinggi);
		else if (opsi == 2)
			hasil = volume_tabung(jari_jari, tinggi);
		else {
			continue;
		}

		break;
	}

	cout << "==============================================" << endl;

	if (opsi == 1) {
		cout << "RUMUS: 2 x phi x r x (r x t)" << endl;
		cout << "Luas Permukaan: " << hasil << endl;
	} else if (opsi == 2) {
		cout << "RUMUS: phi x r^2 x t" << endl;
		cout << "Volume: " << hasil << endl;;
	}

	cout << "==============================================" << endl;

	return 0;
}
