#include <iostream>

using namespace std;

int
main()
{
	int baris;

	cout << "Masukan baris segitiga: ";
	cin >> baris;

	for(int i=baris; i > 0; i--)
	{
		for (int j=0; j < i; j++)
			cout << "* ";
		cout << "\n";
	}

	return 0;
}
