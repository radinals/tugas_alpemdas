//  _____ _     _____         _____
// |_   _(_) __|_   _|_ _  __|_   _|__   ___
//   | | | |/ __|| |/ _` |/ __|| |/ _ \ / _ \
//   | | | | (__ | | (_| | (__ | | (_) |  __/
//   |_| |_|\___||_|\__,_|\___||_|\___/ \___|
//           (with bit manipulations)
//

#include <cstddef>
#include <iostream>
#include <random>

// ================================================================ Constants

using std::uint16_t;

// these value are used for the bit shifts
// clang-format off
enum Coord {
	C_A1 = 2, C_A2 = 1, C_A3 = 0,
	C_B1 = 5, C_B2 = 4, C_B3 = 3,
	C_C1 = 8, C_C2 = 7, C_C3 = 6,
};

enum Mark { M_X, M_O };

// which player is what
// TODO: should be assigned dinamicly
const Mark Com_Mark = M_O;
const Mark Player_Mark = M_X;

// the board size
const size_t Grid_mx = 3;
const size_t Grid_my = 3;
// clang-format on

// =============================================================== Prototypes

// bit manipulation functions
void toggle_bit_at(uint16_t& bitmask, Coord coord);
bool bit_on_at(uint16_t bitmask, Coord coord);
bool winstate_found(uint16_t bitmask);

// rng
size_t rand_num(size_t min, size_t max);

// game
void game_loop();
void print_board();
void redraw();
bool place_mark(Mark mark, size_t x, size_t y);
void com_turn();
void player_turn();
bool game_is_draw();
Coord index2Coord(size_t x, size_t y);

// ==================================================================== Macro

#define ArrSize(array) (sizeof(array) / sizeof(array[0]))

// ================================================================== Globals

// bitmaps of the X's and O's
uint16_t X_bitmask = 0b000000000;
uint16_t O_bitmask = 0b000000000;

// win state masks
const uint16_t WinStates[] = {
    0b111000000, 0b000111000, 0b000000111, // horizontal
    0b100100100, 0b010010010, 0b001001001, // vertical
    0b100010001, 0b001010100               // diagonal
};

// ==========================================================================

int
main()
{
	game_loop();
	return 0;
}

void
game_loop()
{
	while (true) {
		redraw();

		std::cout << "TURN: PLAYER\n";
		player_turn();
		if (winstate_found(X_bitmask)) {
			redraw();
			std::cout << "PLAYER WON!\n";
			break;
		}

		redraw();

		std::cout << "TURN: COM\n";
		com_turn();
		if (winstate_found(O_bitmask)) {
			redraw();
			std::cout << "COM WON!\n";
			break;
		}

		if (game_is_draw()) {
			redraw();
			std::cout << "GAME OVER: DRAW\n";
			break;
		}
	}
}

void
com_turn()
{
	size_t x, y;
	do {
		x = rand_num(0, Grid_mx - 1);
		y = rand_num(0, Grid_my - 1);
	} while (!place_mark(Com_Mark, x, y));
}

void
player_turn()
{
	size_t x, y;
	char x_c, y_c;

	while (true) {
		std::string coord_str;
		std::cout << "Enter the Coordinates [A-B][1-3]: ";
		std::cin >> coord_str;

		if (coord_str.empty() || coord_str.length() < 2)
			continue;

		y_c = coord_str.at(0);
		x_c = coord_str.at(1);

		if ((y_c >= 'A' && y_c <= 'C') && (x_c >= '1' && x_c <= '3')) {
			y = (y_c - 'A');
			x = (x_c - '0') - 1;

			if (place_mark(Player_Mark, x, y))
				break;
		}

		std::cout << "ERROR: invalid!\n";
	}
}

// toggles the bit on/off at based of the shift amount
void
toggle_bit_at(uint16_t& bitmask, Coord coord)
{
	bitmask ^= (1u << coord);
}

// returns the on/off state of a bit at a shift amount
bool
bit_on_at(uint16_t bitmask, Coord coord)
{
	return (bitmask & (1u << coord));
}

// check the bits of the WinStates are found to be on at the bitmask
bool
winstate_found(uint16_t bitmask)
{
	for (size_t i = 0; i < ArrSize(WinStates); i++)
		if ((bitmask & WinStates[i]) == WinStates[i])
			return true;
	return false;
}

// if all bits is on on both X's and O's bitmask is on
bool
game_is_draw()
{
	return (X_bitmask | O_bitmask) == 0b111111111;
}

bool
place_mark(Mark mark, size_t x, size_t y)
{
	Coord coord = index2Coord(x, y);

	if (bit_on_at(O_bitmask, coord) || bit_on_at(X_bitmask, coord))
		return false;
	if (mark == M_O) {
		toggle_bit_at(O_bitmask, coord);
		return true;
	} else if (mark == M_X) {
		toggle_bit_at(X_bitmask, coord);
		return true;
	}
	return false;
}

size_t
rand_num(size_t min, size_t max)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<size_t> dist6(min, max);
	return dist6(rng);
}

void
print_board()
{
	std::cout << "\n- - - - - - -\n";
	for (size_t y = 0; y < Grid_my; y++) {
		std::cout << "| ";
		for (size_t x = 0; x < Grid_mx; x++) {

			Coord coord = index2Coord(x, y);

			if (bit_on_at(X_bitmask, coord) == 1)
				std::cout << 'X';
			else if (bit_on_at(O_bitmask, coord) == 1)
				std::cout << 'O';
			else
				std::cout << ' ';
			std::cout << " | ";
		}
		std::cout << "\n- - - - - - -\n";
	}
}

Coord
index2Coord(size_t x, size_t y)
{
	if (x == 0 && y == 0)
		return C_A1;
	else if (x == 1 && y == 0)
		return C_A2;
	else if (x == 2 && y == 0)
		return C_A3;

	else if (x == 0 && y == 1)
		return C_B1;
	else if (x == 1 && y == 1)
		return C_B2;
	else if (x == 2 && y == 1)
		return C_B3;

	else if (x == 0 && y == 2)
		return C_C1;
	else if (x == 1 && y == 2)
		return C_C2;
	else if (x == 2 && y == 2)
		return C_C3;
	else {
		std::cout << "Error!failed to convert index to coord.";
		exit(-1);
	}
}

void
redraw()
{
	system("clear");
	print_board();
}
