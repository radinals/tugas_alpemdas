#include <iostream>
using namespace std;


int main()
{
	int jawaban = 8;
	int min = -8;
	int max = 8;

	for (int x=min; x < max; x++)
	{
		for (int y=min; y < max; y++)
		{
			if (x + y == jawaban)
				cout << x << " + " << y << \
					" = " << jawaban << "\n";
		}
	}
}
