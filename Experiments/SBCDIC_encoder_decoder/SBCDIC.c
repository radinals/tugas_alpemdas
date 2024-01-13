#include <stdio.h>
#include <stdlib.h>

// Converter encoding ascii -> SBCDIC dan SBCDIC -> ascii

// Aturan:
//  - index:
//     'A' = 0001
//     'R' = 1001
//  - id:
//      00 -> numeric -> 0 .. 9
//      11 -> huruf   -> A .. I
//      10 -> huruf   -> J .. R
//      01 -> huruf   -> S .. Z
//  - FORMAT
//      id  index
//      00   0001

// ================================================================ datatypes

typedef unsigned char SBCDIC_Char;

typedef struct {
	SBCDIC_Char* str; // array unsigned char
	size_t len;       // ukuran dari str
} SBCDIC_Str;

// =============================================================== prototypes
SBCDIC_Str* alloc_sbcdic_str(size_t size);
unsigned char* alloc_str(size_t size);
void free_str(unsigned char* str);
void free_sbcdic_str(SBCDIC_Str* str);
unsigned char* decode(SBCDIC_Str* sbcdic_str);
SBCDIC_Str* encode(unsigned char* str, size_t str_len);
void ascii_2_sbcdic(unsigned char c, SBCDIC_Char* sbcdic_char);
void sbcdic_2_ascii(SBCDIC_Char sbcdic_char, unsigned char* c);

// ================================================================= konstant

// id bit mask
const unsigned char NUM_SET = 0x00; // 00
const unsigned char A_I_SET = 0x30; // 11
const unsigned char J_R_SET = 0x20; // 10
const unsigned char S_Z_SET = 0x10; // 01

// ==================================================================== macro

// mencari index sebuah char dari index
#define char_index(char, start) (char - start);

// kembalikan char + index
#define index2char(start, index) (start + index);

// ================================================================ functions
int
main()
{
	unsigned char* msg = "HELLO12345";
	size_t msg_len = 10;

	SBCDIC_Str* sbcdic_str;
	unsigned char* decoded_msg;

	sbcdic_str = encode(msg, msg_len);
	decoded_msg = decode(sbcdic_str);

	if (sbcdic_str == NULL || decoded_msg == NULL)
		return -1;

	printf("IN: %s\n", msg);
	printf("OUT: %s\n", decoded_msg);

	printf("PROOF:\n");
	for (size_t i = 0; i < sbcdic_str->len; i++) {
		printf("  - sbcdic char at %lu = %c : %u\n", i + 1, *(msg + i),
		       *(sbcdic_str->str + i));
	}

	free_str(decoded_msg);
	free_sbcdic_str(sbcdic_str);

	return 0;
}

// konversi tiap char di string jadi format sbcdic
SBCDIC_Str*
encode(unsigned char* str, size_t str_len)
{
	SBCDIC_Str* sbcdic_str = NULL;

	sbcdic_str = alloc_sbcdic_str(str_len);
	sbcdic_str->len = str_len;

	for (size_t i = 0; i < str_len; i++) {
		unsigned char c = *(str + i);
		SBCDIC_Char tmp = '\0';

		ascii_2_sbcdic(c, &tmp);

		if (tmp != '\0')
			*(sbcdic_str->str + i) = tmp;
	}

	if (sbcdic_str != NULL && *(sbcdic_str->str) != '\0')
		return sbcdic_str;

	free_sbcdic_str(sbcdic_str);

	return NULL;
}

// konversi tiap char sbcdic di string jadi format ascii
unsigned char*
decode(SBCDIC_Str* sbcdic_str)
{
	unsigned char* ascii_str = NULL;
	size_t str_len = sbcdic_str->len;

	ascii_str = alloc_str(str_len);

	for (size_t i = 0; i < str_len; i++) {
		unsigned char c = '\0';
		sbcdic_2_ascii(*(sbcdic_str->str + i), &c);

		if (c != '\0') {
			*(ascii_str + i) = c;
		}
	}

	if (ascii_str != NULL && *(ascii_str) != '\0')
		return ascii_str;

	free_str(ascii_str);

	return NULL;
}

// alokasi memory string sbcdic sepanjang size + 1, +1 karena '\0'
SBCDIC_Str*
alloc_sbcdic_str(size_t size)
{
	SBCDIC_Str* sbcdic_str;
	// alokasi memory struct
	sbcdic_str = (SBCDIC_Str*)malloc(sizeof(SBCDIC_Str));

	// alokasi memory string sbcdic
	sbcdic_str->str =
	    (SBCDIC_Char*)malloc((size + 1) * sizeof(SBCDIC_Char));

	// set endpoint
	*((sbcdic_str->str) + size + 1) = '\0';

	return sbcdic_str;
}

// alokasi memory string biasa sepanjang size + 1, +1 karena '\0'
unsigned char*
alloc_str(size_t size)
{
	unsigned char* ascii_str;

	// alokasi memory unsigned char* str
	ascii_str = (unsigned char*)malloc((size + 1) * sizeof(unsigned char));

	// set endpoint
	*(ascii_str + size + 1) = '\0';

	return ascii_str;
}

// konversi satu char ascii jadi char sbcdic
void
ascii_2_sbcdic(unsigned char c, SBCDIC_Char* sbcdic_char)
{
	unsigned char c_i;

	if (sbcdic_char == NULL) // check jika pointer invalid
		return;

	// clang-format off
	switch (c) {
		case '0': case '1': case '2': case '3': case '4': case '5':
			case '6': case '7': case '8': case '9':
		{
			c_i = char_index(c, '0');
			*sbcdic_char = NUM_SET; // set nilai awal sebagai id
			break;
		}

		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
			case 'G': case 'H': case 'I':
		{
			c_i = char_index(c, 'A');
			*sbcdic_char = A_I_SET;
			break;
		}

		case 'J': case 'K': case 'L': case 'M': case 'N': case 'O':
			case 'P': case 'Q': case 'R':
		{
			c_i = char_index(c, 'J');
			*sbcdic_char = J_R_SET;
			break;
		}

		case 'S': case 'T': case 'U': case 'V': case 'W': case 'X':
			case 'Y': case 'Z':
		{
			c_i = char_index(c, 'S');
			*sbcdic_char = S_Z_SET;
			break;
		}

		default:
			*sbcdic_char = '\0'; // jika bukan karakter valid
			return;
	}
	// clang-format on
	*sbcdic_char |= c_i; // set bit-bit index
}

// konversi satu char sbcdic jadi char ascii
void
sbcdic_2_ascii(SBCDIC_Char sbcdic_char, unsigned char* c)
{

	if ((sbcdic_char & A_I_SET) == A_I_SET) { // cek jka id sesuai
		// hilangkan id, index kemudian ditambahkan ke karakter awal
		*c = index2char('A', (sbcdic_char ^ A_I_SET));
		return;
	} else if ((sbcdic_char & J_R_SET) == J_R_SET) {
		*c = index2char('J', (sbcdic_char ^ J_R_SET));
		return;
	} else if ((sbcdic_char & S_Z_SET) == S_Z_SET) {
		*c = index2char('S', (sbcdic_char ^ S_Z_SET));
		return;
	} else if ((sbcdic_char & NUM_SET) == NUM_SET) {
		*c = index2char('0', (sbcdic_char ^ NUM_SET));
		return;
	}
	*c = '\0'; // jika diatas gagal semua
}

// bebaskan memori-memori yang dialokasikan
void
free_str(unsigned char* str)
{
	free(str);
}

void
free_sbcdic_str(SBCDIC_Str* str)
{
	free(str->str);
	free(str);
}
