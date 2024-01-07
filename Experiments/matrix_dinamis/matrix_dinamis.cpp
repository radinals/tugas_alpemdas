#include <iostream>
using namespace std;

int** new_matrix(size_t cols, size_t lines);
void delete_matrix(size_t lines, int** matrix);
int* create_array(size_t size);
void delete_matrix(size_t cols, size_t lines, int** matrix);

int
main()
{
	int size = 25;
	int** my_matrix = new_matrix(size, size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) my_matrix[i][j] = j;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) cout << my_matrix[i][j] << ", ";
		cout << "\n";
	}
}

void
delete_matrix(size_t cols, size_t lines, int** matrix)
{
	while (lines >= 0) {
		delete[] matrix[cols];
		lines--;
	};
	delete[] matrix;
}

int**
new_matrix(size_t cols, size_t lines)
{
	try {
		int** matrix = new int*[lines];

		for (size_t i = 0; i < lines; i++)
			matrix[i] = create_array(cols);

		return matrix;

	} catch (...) {
		return nullptr;
	}
}

int*
create_array(size_t size)
{
	try {
		return new int[size];

	} catch (...) {
		return nullptr;
	}
}
