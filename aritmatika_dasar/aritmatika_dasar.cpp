#include <random>
#include <iostream>

using namespace  std;

void gen_question(string& str, string& answ, int max_n=100, int min_n=-100);
int rand_range(int x, int y);

int
main()
{
	// outputnya ala kadarnya saja:)

	int wrong_count = 0;
	int max_wrong = 3;

	while (wrong_count < max_wrong) {
		string question, correct_answ, user_input;
		gen_question(question, correct_answ, 10, -10);
		cout << question << " = ";
		getline(cin, user_input);

		if (user_input == correct_answ) {
			cout << "JAWABAN BENAR!\n";
		} else if (user_input == "EXIT") {
			break;
		} else {
			cout << "JAWABAN SALAH!, yang benar adalah " << correct_answ << "\n";
			wrong_count++;
		}
	}
	return 0;
}

// kalau pakai srand(time()), kurang random...
// angka yg digenerate bisa sama berkali-kali
// karena untuk nilai seed nya berubah, harus diberi waktu
// antara generasi angka, agar bisa beda (bedasarkan system clock)
int
rand_range(int x, int y)
{
	std::random_device rd; // seed berasal dari /dev/urandom

	// hasilkan angka, ala c++ 11+
	std::mt19937 rng(rd());

	// hasilkan integer antara x dan y
	std::uniform_int_distribution<> uni(x,y);

	// kembalikan angka random
	return uni(rng);
}

// menggembalikan nilai-nilai melalui reffrence, agar satu fungsi bisa
// meng-return 2 nilai (pertanyaan dan jawabannya).

// max_n dan min_n menentukan "range" dari angka angka yg muncul di soal
// yang dihasilkan

// FIXME: pembagian seharusnya menggunakan float

void
gen_question(string& out_str, string& out_answ, int max_n, int min_n)
{
	int n_1, n_2;
	string op;

	// dapatkan angka untuk soal
	n_1 = rand_range(min_n, max_n);
	n_2 = rand_range(min_n, max_n);

	// pilih operator, dan dapatkan hasil yg benar
	switch (rand_range(0, 3)) {
		case 0:
			op = "+";
			out_answ = to_string(n_1 + n_2);
			break;
		case 1:
			op = "-";
			out_answ = to_string(n_1 - n_2);
			break;
		case 2:
			op = ":";
			out_answ = to_string(n_1 / n_2);
			break;
		case 3:
			op = "X";
			out_answ = to_string(n_1 * n_2);
			break;
		default:
			exit(1);
			break;

	}

	// formatkan kedalam bentuk soal
	// <angka1> <operator> <angka2>
	out_str = to_string(n_1) + " " + op + " " + to_string(n_2);
}
