#include <iostream>
using namespace std;
int
main()
{
	int height = 10;

	for (int y=0; y < height; y++)
	{
		for (int x=0; x < height-y; x++)
			cout << " ";

		for (int x=0; x <= y*1; x++)
			cout << "#";

		cout << endl;
	}

	return 0;
}
