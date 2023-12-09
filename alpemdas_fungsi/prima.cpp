#include <iostream>
using namespace std;

bool is_prima(int n);
void cari_prima(size_t start, size_t end);

int main()
{
	cari_prima(1, 30);

	return 0;
}

bool
is_prima(int n) 
{
	bool prima = true;
	if (n <= 1) {
		prima = false;
	} else {
		for (size_t i=2; i < n; i++)
		{
			if (n % i == 0) {
				prima = false;
				break;
			}

		}
	}
	return prima;
} 

void 
cari_prima(size_t start, size_t end)
{
	cout << "PRIMA (" << start << ".." << end << "): {";

	for(size_t n=start; n <= end ; n++)
	{
		if (is_prima(n))
			cout << n << " ";

	}

	cout << "} " << endl;
}

