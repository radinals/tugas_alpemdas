#include <iostream>

using namespace std;

void bubble_sort(char arr[], int len, bool acending=true);
void split_to_arr(string str, char arr[], int len);
void swap(int from, int to, char arr[]);
void print_chars(char arr[], int len);

int
main()
{
	// char count
	int len;
	cout << "Masukan Jumlah Huruf: ";
	cin >> len;

	// clear the input stream
	cin.clear(); cin.ignore();

	// get the chars
	string input_str;
	cout << "Masukan " << len << " huruf: ";
	getline(cin, input_str);

	// place at the array
	char huruf[len];
	split_to_arr(input_str, huruf, len);

	// sort the array
	bubble_sort(huruf, len);

	// print the array
	cout << "SORTED: ";
	print_chars(huruf, len);

	return 0;
}

// swap arr[from] with arr[y]
void
swap(int from, int to, char arr[])
{
	char tmp = arr[from];
	arr[from] = arr[to];
	arr[to] = tmp;
}

void
bubble_sort(char arr[], int len, bool acending)
{
	for (int i=0; i < len; i++)
	{
		for (int j=0; j < len-1; j++)
		{
			if (arr[j] > arr[j+1] && acending)
				swap(j, j+1, arr);
			else if (arr[j] > arr[j+1] && ! acending)
				swap(j, j+1, arr);
		}
	}
}

void
split_to_arr(string str, char arr[], int len)
{
	for (int i=0, count=0; i < str.length() && count < len; i++)
	{
		if (str.at(i) != ' ' && str.at(i) != '\t')
			arr[count++] = str.at(i);
	}
}

void
print_chars(char arr[], int len)
{
	for (int i=0; i < len; i++)
		cout << arr[i] << " ";
	cout << "\n";
}
