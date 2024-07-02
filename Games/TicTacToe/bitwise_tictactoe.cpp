//  _____ _     _____         _____
// |_   _(_) __|_   _|_ _  __|_   _|__   ___
//   | | | |/ __|| |/ _` |/ __|| |/ _ \ / _ \
//   | | | | (__ | | (_| | (__ | | (_) |  __/
//   |_| |_|\___||_|\__,_|\___||_|\___/ \___|
//           (with bit manipulations)
//

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

// ================================================================ Constants

// these value are used for the bit shifts
// clang-format off
enum Coord {
	C_A1 = 0, C_A2 = 1, C_A3 = 2,
	C_B1 = 3, C_B2 = 4, C_B3 = 5,
	C_C1 = 6, C_C2 = 7, C_C3 = 8,
};

enum Mark { M_X, M_O };

// which player is what
// TODO: should be assigned dinamicly
const Mark Com_Mark = M_O;
const Mark Player_Mark = M_X;

// the board size
const size_t GRID_SIZE = 3;
// clang-format on

// =============================================================== Prototypes

// bit manipulation functions
void toggle_bit_at(unsigned int& bitmask, unsigned int coord);
bool bit_on_at(unsigned int bitmask, unsigned int coord);
bool winstate_found(unsigned int bitmask);

// rng
int rand_num(int min, int max);

// game
void game_loop();
void print_board();
void redraw();
bool place_mark(Mark mark, size_t x, size_t y);
void com_turn();
void player_turn();
bool game_is_draw();

// ==================================================================== Macro

#define ArrSize(array) (sizeof((array)) / sizeof((array[0])))
#define COORD(x, y)    ((y) + ((y) * 2) + (x))

// ================================================================== Globals

// bitmaps of the X's and O's
unsigned int X_bitmask = 0b0000000000u;
unsigned int O_bitmask = 0b0000000000u;

// win state masks
const unsigned int WinStates[] = {
    0b111000000u, 0b000111000u, 0b000000111u, // horizontal
    0b100100100u, 0b010010010u, 0b001001001u, // vertical
    0b100010001u, 0b001010100u                // diagonal
};

// ================================================================ Functions

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
		if (game_is_draw()) {
			redraw();
			std::cout << "GAME OVER: DRAW\n";
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
	srand((unsigned int)(time(NULL)));
	do {
		x = rand_num(0, GRID_SIZE - 1);
		y = rand_num(0, GRID_SIZE - 1);
		std::cout << "x: " << x << " "
		          << "y: " << y << '\n';
		printf("X: %x\n", X_bitmask);
		printf("O: %x\n", O_bitmask);
		printf("B: %x\n", X_bitmask & O_bitmask);
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
toggle_bit_at(unsigned int& bitmask, unsigned int coord)
{
	bitmask ^= (1u << coord);
}

// returns the on/off state of a bit at a shift amount
bool
bit_on_at(unsigned int bitmask, unsigned int coord)
{
	return (bitmask & (1u << coord));
}

// check the bits of the WinStates are found to be on at the bitmask
bool
winstate_found(unsigned int bitmask)
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
	return ((X_bitmask | O_bitmask) ^ 0b111111111u) == 0;
}

bool
place_mark(Mark mark, size_t x, size_t y)
{
	unsigned int coord = COORD(x, y);

	if (bit_on_at(O_bitmask, coord) || bit_on_at(X_bitmask, coord))
		return false;
	switch (mark) {
	case M_O:
		toggle_bit_at(O_bitmask, coord);
		return true;
	case M_X:
		toggle_bit_at(X_bitmask, coord);
		return true;
	}
	return false;
}

int
rand_num(int min, int max)
{
	return min + rand() % (max - min + 1);
}

void
print_board()
{
	std::cout << "\n- - - - - - -\n";
	for (size_t y = 0; y < GRID_SIZE; y++) {
		std::cout << "| ";
		for (size_t x = 0; x < GRID_SIZE; x++) {

			unsigned int coord = COORD(x, y);

			std::cout << (bit_on_at(X_bitmask, coord)   ? 'X'
			              : bit_on_at(O_bitmask, coord) ? 'O'
			                                            : ' ')
			          << " | ";
		}
		std::cout << "\n- - - - - - -\n";
	}
}

void
redraw()
{
	system("clear");
	print_board();
}
