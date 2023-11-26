#include <iostream>

using namespace std;

int
main()
{
	int n;
	bool bkn_prima = false;

	cout << "Masukan Bilangan: ";
	cin >> n;

	if (n <= 1)
		bkn_prima = true;
	else {
		for(int i=2; i < n; i++)
			if (n % i == 0) {
				bkn_prima = true;
				break;
			}
	}

	if (bkn_prima)
		cout << n << " bukan bilangan prima" << endl;
	else
		cout << n << " adalah bilangan prima" << endl;


	return 0;
}
