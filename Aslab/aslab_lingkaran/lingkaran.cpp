#include <iostream>
using namespace std;

int
main()
{
	int diameter = 32;
	for (int y = 0; y <= diameter + 2; y += 2) {
		if (y < diameter - diameter / 2)
			continue;

		int tmp = y;
		if (tmp > diameter)
			tmp = diameter;

		for (int x = 0; x < diameter * 2 - tmp; x++) cout << " ";

		for (int x = 0; x < tmp; x++) {
			cout << "#"
			     << " ";
		}
		cout << endl;
	}

	for (int y = diameter; y >= 0; y -= 2) {
		if (y > diameter)
			y = diameter;

		if (y < diameter - diameter / 2)
			continue;

		for (int x = 0; x < diameter * 2 - y; x++) cout << " ";

		for (int x = 0; x < y; x++) {
			cout << "#"
			     << " ";
		}
		cout << endl;
	}
	return 0;
}
