#include <iostream>
using namespace std;

bool is_prima(int n);
void cari_prima(size_t start, size_t end);

int
main()
{
	cari_prima(1, 30);

	return 0;
}

// cek suatu angka apakah prima (true or false)
bool
is_prima(int n)
{
	if (n <= 1)
		return false;

	for (size_t i = 2; i < n; i++) {
		if (n % i == 0)
			return true;
	}

	return false;
}

// cari angka-angka prima,dari start hingga end.
void
cari_prima(size_t start, size_t end)
{
	cout << "PRIMA (" << start << ".." << end << "): {";

	for (size_t n = start; n <= end; n++) {
		if (is_prima(n))
			cout << n << " ";
	}

	cout << "} " << endl;
}
