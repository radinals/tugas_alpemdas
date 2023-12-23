#include <iostream>
using namespace std;

int** new_matrix(size_t x, size_t y);
void delete_matrix(size_t y, int** matrix);
int* create_array(size_t size);
void delete_matrix(size_t x, size_t y, int** matrix);

int
main()
{
	int size = 25;
	int **my_matrix = new_matrix(size, size);

	for (int i=0; i < size; i++)
	{
		for (int j=0; j < size; j++)
			my_matrix[i][j] = j;
	}

	for (int i=0; i < size; i++)
	{
		for (int j=0; j < size; j++)
			cout << my_matrix[i][j] << ", ";
		cout << "\n";
	}
}

void
delete_matrix(size_t x, size_t y, int** matrix)
{
	for (int i=0; i < y; i++)
		delete[] matrix[x];
	delete[] matrix;
}

int**
new_matrix(size_t x, size_t y)
{
	try {
		int** matrix = new int* [y];

		for (size_t i=0; i < y; i++)
			matrix[i] = create_array(x);

		return matrix;

	} catch (...) {
		return nullptr;
	}

}

int*
create_array(size_t size)
{
	try {
		return new int [size];

	} catch(...) {
		return nullptr;
	}
}
