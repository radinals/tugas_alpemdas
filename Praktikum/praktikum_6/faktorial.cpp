#include <iostream>

using namespace std;;

int
main()
{
	int n, i;
	long long hasil;

	hasil = i = 1;

	cout << "Masukan Faktorial: ";
	cin >> n;

	while(i <= n) hasil*=i++;

	cout << "Angka Faktorial dari " << n <<
		" adalah " << hasil << endl;;

	return 0;
}
