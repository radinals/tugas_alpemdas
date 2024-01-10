/*   _____ _     _____         _____
 *   |_   _(_) __|_   _|_ _  __|_   _|__   ___
 *     | | | |/ __|| |/ _` |/ __|| |/ _ \ / _ \
 *     | | | | (__ | | (_| | (__ | | (_) |  __/
 *     |_| |_|\___||_|\__,_|\___||_|\___/ \___|
 */

// OPSI Random Number Generator (RNG)
// PERINGATAN:
// 	menggunakan srand() + rand()
// 	akan membuat program stall
//	disaat-saat tertentu.
// comment ini jika ingin menggunakan
// RNG yang C-Style (menggunakan srand() + rand())
#define CPP_STYLE_RANDOM

#include <cstdlib>
#include <ios>
#include <iostream>
#include <limits>
#include <random>

#ifndef CPP_STYLE_RANDOM
#include <cstddef>
#include <time.h>
#endif // !CPP_STYLE_RANDOM

// gunakan "cls" untuk windows
#define ClearScreen system("clear");

enum Mark {
	X_MARK = 0,
	O_MARK = 1,
	EMPTY = 2,
	ERR = 3
};
enum PlayerState {
	WIN,
	DRAW,
	None
};

// TODO: Perlu di tes jika program dinamis
const int tabel_game_lines = 3;
const int tabel_game_cols = 3;
const int win_min = 3;

Mark tabel_game[tabel_game_lines][tabel_game_cols] = {
    {Mark::EMPTY, Mark::EMPTY, Mark::EMPTY},
    {Mark::EMPTY, Mark::EMPTY, Mark::EMPTY},
    {Mark::EMPTY, Mark::EMPTY, Mark::EMPTY},
};

// fungsi-fungsi pengecekan tabel
bool cek_tabel(Mark mark_query); // cek semua arah tabel (searching)
bool tabel_penuh(); // mengecek jika tabel sudah penuh (sudah tidak ada cell
                    // kosong)

void game(); // game loop

void print_tabel(); // print tabel
void redraw();      // print tabel, dan clear console
bool set_cell(
    int x, int y,
    Mark marktype);         // me-set suatu tabel di tabel_game[y][x] = marktype
Mark cell_at(int x, int y); // return tabel_game[y][x]

int rand_int(int min, int max); // angka random antara min dan max

void user_input(Mark marktype);      // minta input user
void rand_com_choice(Mark marktype); // generate pilihan komputer

PlayerState player_turn(Mark player_mark); // abstraksi giliran pemain
PlayerState com_turn(Mark com_mark);       // abstraksi giliran komputer

int
main()
{
	game();
	return 0;
}

void
game()
{
	Mark player_mark = Mark::ERR;
	Mark com_mark = Mark::ERR;

	ClearScreen;

	// tentukan tanda para pemain

	std::string opt;
	std::cout << "Pilih antara X atau O: ";
	getline(std::cin, opt);

	if (opt == "O")
		player_mark = Mark::O_MARK;
	else
		player_mark = Mark::X_MARK;

	if (player_mark == Mark::O_MARK)
		com_mark = Mark::X_MARK;
	else
		com_mark = Mark::O_MARK;

	if (player_mark == Mark::ERR || com_mark == Mark::ERR)
		return;

	redraw();
	while (true) {
		std::cout << "PLAYER TURN:\n";
		switch (player_turn(player_mark)) {
		case PlayerState::WIN: // jika pemain menang
			redraw();
			std::cout << "== PLAYER WINS! ==\n";
			goto EXIT;
		case PlayerState::DRAW: // seri
			redraw();
			std::cout << "== DRAW! ==\n";
			goto EXIT;
		default:
			break;
		};

		std::cout << "COM TURN:\n";
		switch (com_turn(com_mark)) {
		case PlayerState::WIN: // jika com menang
			redraw();
			std::cout << "== COM WINS! ==\n";
			goto EXIT;
		case PlayerState::DRAW: // seri
			redraw();
			std::cout << "== DRAW! ==\n";
			goto EXIT;
		default:
			break;
		};

		redraw();
	}

EXIT:
	return;
}

PlayerState
player_turn(Mark player_mark)
{

	if (tabel_penuh())
		return PlayerState::DRAW; // penuh == seri

	user_input(player_mark); // input user

	if (cek_tabel(player_mark))
		return PlayerState::WIN; // deret == menang

	return PlayerState::None; // jika tidak menang atau seri
}

PlayerState
com_turn(Mark com_mark)
{

	if (tabel_penuh())
		return PlayerState::DRAW; // penuh == seri

	rand_com_choice(com_mark); // RNG

	if (cek_tabel(com_mark))
		return PlayerState::WIN; // deret == menang

	return PlayerState::None; // jika tidak menang atau seri
}

void
redraw()
{
	ClearScreen;
	print_tabel();
}

bool
cek_tabel(Mark mark_query)
{
	// cek semua arah
	int count_diag_kebawah = 0, count_diag_keatas = 0, count_horiz = 0,
	    count_vert = 0;

	int line_diag_kebawah = 0, line_diag_keatas = tabel_game_lines - 1,
	    line_horiz = 0, line_vert = 0;

	int col_diag_kebawah = 0, col_diag_keatas = 0, col_horiz = 0,
	    col_vert = 0;

	for (int ny = 0; ny < tabel_game_lines; ny++) // loop sebanyak baris
	{
		// cek diagonal kebawah
		if (cell_at(col_diag_kebawah, line_diag_kebawah) == mark_query)
			count_diag_kebawah++;
		if (count_diag_kebawah >= win_min) // keluar jika sudah sesuai
			return true;

		line_diag_kebawah++;
		col_diag_kebawah++;

		// cek diagonal keatas
		if (cell_at(col_diag_keatas, line_diag_keatas) == mark_query)
			count_diag_keatas++;
		if (count_diag_keatas >= win_min) // keluar jika sudah sesuai
			return true;

		line_diag_keatas--;
		col_diag_keatas++;

		for (int nx = 0; nx < tabel_game_cols;
		     nx++) // loop sebanyak kolom
		{
			// cek horizontal
			if (cell_at(col_horiz, line_horiz) == mark_query)
				count_horiz++;
			col_horiz++;

			// cek vertical
			if (cell_at(col_vert, line_vert) == mark_query)
				count_vert++;
			line_vert++;
		}
		// cek horizontal
		if (count_horiz >= win_min) // keluar jika sudah sesuai
			return true;
		else
			count_horiz = 0; /// reset hitungan jika belum sesuai

		line_horiz++;

		// cek vertical
		if (count_vert >= win_min) // keluar jika sudah sesuai
			return true;
		else
			count_vert = 0; /// reset hitungan jika belum sesuai

		col_vert++;
	}

	return false;
}

bool
tabel_penuh() // tabel penuh jika sudah tidak ada cell 'kosong'
{
	for (int y = 0; y < tabel_game_lines; y++) {
		for (int x = 0; x < tabel_game_cols; x++) {
			if (cell_at(x, y) == Mark::EMPTY)
				return false;
		}
	}
	return true;
}

bool
set_cell(int x, int y, Mark marktype)
{
	// memastikan index yang di pilih meiliki area lebih kecil
	// dari ukuran matrix dan >= 0
	if (x * y < tabel_game_lines * tabel_game_cols && x * y >= 0) {
		tabel_game[y][x] = marktype; // set nilai
		return true;                 // return success
	}
	return false;
}

Mark
cell_at(int x, int y)
{
	if (x * y < tabel_game_lines * tabel_game_cols && x * y >= 0)
		return tabel_game[y][x];
	return Mark::ERR;
}

void
print_tabel()
{
	std::cout << "-------------\n";
	for (int y = 0; y < tabel_game_lines; y++) {
		for (int x = 0; x < tabel_game_cols; x++) {
			std::cout << "| ";
			switch (cell_at(x, y)) {
			case Mark::X_MARK:
				std::cout << "X";
				break;
			case Mark::O_MARK:
				std::cout << "O";
				break;
			default:
				std::cout << " ";
				break;
			}
			std::cout << " ";
		}
		std::cout << "|\n";
		std::cout << "-------------\n";
	}
}

int
rand_int(int min, int max) // random number generator
{
#ifdef CPP_STYLE_RANDOM
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<int> dist6(min, max);
	return dist6(rng);
#else
	srand(time(NULL));
	return rand() % (min - max + 1) - min;
#endif
}

void
rand_com_choice(
    Mark marktype) // dapatkan nilai-nilai random untuk pemain komputer
{
	int x = -1, y = -1;
	while (true) {
		x = rand_int(0, tabel_game_cols);
		y = rand_int(0, tabel_game_lines);

		if (cell_at(x, y) != Mark::EMPTY)
			continue;

		if (set_cell(x, y, marktype))
			break;
	}
}

void
user_input(Mark marktype)
{
	while (true) {
		int cell_dipilih = -1;
		std::cout << " > Masukan cell yang ingin di tandai [1, 9]: ";
		std::cin >> cell_dipilih;

		if (std::cin.fail() ||
		    cell_dipilih == -1) // clean the buffer if input invalid
		{
			std::cin.clear();
			std::cin.ignore(
			    std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		int x = -1, y = -1; // agar lebih mudah error checking

		// FIXME: seharusnya ada cara lebih baik dari ini
		switch (cell_dipilih) {
		case 1:
			x = 0;
			y = 0;
			break;
		case 2:
			x = 1;
			y = 0;
			break;
		case 3:
			x = 2;
			y = 0;
			break;
		case 4:
			x = 0;
			y = 1;
			break;
		case 5:
			x = 1;
			y = 1;
			break;
		case 6:
			x = 2;
			y = 1;
			break;
		case 7:
			x = 0;
			y = 2;
			break;
		case 8:
			x = 1;
			y = 2;
			break;
		case 9:
			x = 2;
			y = 2;
			break;
		default:
			continue;
		}

		if (cell_at(x, y) == Mark::ERR) { // almost impossible?
			continue;
		} else if (cell_at(x, y) !=
		           Mark::EMPTY) { // if cell is not empty go back
			std::cout << "!!! INVALID !!!\n";
			continue;
		}

		if (set_cell(x, y, marktype))
			break; // jika berhasil meng-set, keluar loop
	}
}
