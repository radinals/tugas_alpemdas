#include <iostream>
#include <limits>

using namespace std;

void
clear_buffer()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void
get_input(int& var)
{
	cin >> var;
	clear_buffer();
}

void
get_input(float& var)
{
	cin >> var;
	clear_buffer();
}

void
cari_angka_lebih_besar(int arr[], size_t ukuran_arr, int n)
{

	for (size_t i = 0; i < ukuran_arr; i++) {
		if (arr[i] > n) {
			cout << arr[i] << " lebih besar dari " << n << endl;
		}
	}
}

int
hitung_total(int arr[], size_t ukuran_arr)
{
	int total = 0;

	for (size_t i = 0; i < ukuran_arr; i++) total += arr[i];

	return total;
}

float
cari_rata_rata(int arr[], size_t ukuran_arr)
{
	return ((float)hitung_total(arr, ukuran_arr) / (float)ukuran_arr);
}

void
print_arr(int arr[], size_t ukuran_arr)
{
	for (size_t i = 0; i < ukuran_arr; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

int
main()
{
	size_t ukuran_array_data = 5;
	int data[5] = {60, 75, 80, 55, 90};

	while (true) {
		int opsi;

		cout << endl;
		print_arr(data, ukuran_array_data);
		cout << "1. Jumlah Data" << endl;
		cout << "2. Hitung Rata Rata" << endl;
		cout << "3. Cari Angka Yang Lebih Dari N" << endl;
		cout << "4. Exit Program" << endl;

		cout << endl;
		cout << "Pilihan: ";
		get_input(opsi);

		switch (opsi) {
		case 1:
			cout << "Hasil Penjumlahan Data: "
			     << hitung_total(data, ukuran_array_data) << endl;
			break;
		case 2:
			cout << "Rata-Rata Data: "
			     << cari_rata_rata(data, ukuran_array_data) << endl;
			break;
		case 3: {
			int n;
			cout << "Inputkan angka yg dijadikan pembanding: ";
			cin >> n;
			cari_angka_lebih_besar(data, ukuran_array_data, n);
		} break;
		case 4:
			return 0;
		default:
			cout << "Input Invalid!" << endl;
			;
			cin.get();
			continue;
		}

		cin.get();
	}

	return 0;
}
