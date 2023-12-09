#include <iostream>
using namespace std;

const int MAX = 1000;

void print_matrix(int matrx[3][3], size_t baris, size_t kolom);

int main()
{
	int data[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	};

	print_matrix(data, 3, 3);
}

void
print_matrix(int matrx[3][3], size_t baris, size_t kolom)
{
	cout << "matrix = {\n";
	for(size_t y=0; y < baris ; y++)
	{
		cout << "\t{";
		for(size_t x=0; x < kolom; x++)
			cout << matrx[y][x] << " ";
		cout << "}\n";
	}
	cout << "}" << endl;;
}
