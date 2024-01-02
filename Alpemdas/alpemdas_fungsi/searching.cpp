#include <iostream>
using namespace std;

void squential_search(int angka, int arr[], size_t arr_size);
void input_data_array(int arr[], size_t size);
void print_arr(int arr[], size_t arr_size);

int
main()
{
	int angka_dicari;
	size_t jmlh_data;

	cout << "Masukan Jumlah Data: ";
	cin >> jmlh_data;

	int data[jmlh_data];

	input_data_array(data, jmlh_data);
	print_arr(data, jmlh_data);

	cout << "Masukan angka untuk dicari: ";
	cin >> angka_dicari;

	squential_search(angka_dicari, data, jmlh_data);

	return 0;
}

void
squential_search(int angka, int arr[], size_t arr_size)
{
	bool found = false;
	for (size_t i = 0; i < arr_size; i++) {
		if (arr[i] == angka) {
			cout << angka << " ditemukan di index: " << i << "\n";
			;
			found = true;
		}
	}
	if (!found)
		cout << "Angka tidak ditemukan di array!\n";
}

void
input_data_array(int arr[], size_t arr_size)
{
	for (size_t i = 0; i < arr_size; i++) {
		cout << "Input Data ke-" << i << ": ";
		cin >> arr[i];
	}
}

void
print_arr(int arr[], size_t arr_size)
{
	cout << "{ ";
	for (size_t i = 0; i < arr_size; i++) cout << arr[i] << " ";
	cout << "} " << endl;
}
