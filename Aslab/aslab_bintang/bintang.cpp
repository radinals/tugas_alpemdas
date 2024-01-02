#include <iostream>

using namespace std;

int
main()
{
	int size = 4;
	for (int y = 0; y < size; y++) {

		for (int x = 0; x < size * 2 - y; x++) cout << " ";

		for (int x = 0; x <= y * 2; x++) cout << "*";

		for (int x = 0; x < size - y; x++) cout << " ";

		cout << "\n";
	}

	for (int y = size * 2; y > (size); y--) {

		for (int x = 0; x < size * 2 - y; x++) cout << " ";

		for (int x = 0; x <= y * 2; x++) cout << "*";
		cout << "\n";
	}

	for (int y = 1; y < size; y++) {

		for (int x = 0; x < size - y; x++) cout << " ";

		for (int x = 0; x <= size - y; x++) cout << "*";

		for (int x = 0; x < y * 4; x++) cout << " ";

		for (int x = 0; x <= size - y; x++) cout << "*";

		cout << "\n";
	}

	return 0;
}
