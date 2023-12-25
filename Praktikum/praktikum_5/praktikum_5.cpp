#include <iostream>

using namespace std;


void
segitiga(char c1, char c2, int baris, bool spaced)
{
	if (spaced) baris++;
	for ( int y=0 ; y < baris ; y++ ) {

		// spasi
		for( int x=0 ; x < baris-y ; x++ ) cout << c2;

		// badan
		for( int x=0 ; x <= y*2    ; x++ ) cout << ((x % 2 == 0 && spaced) ? c2 : c1);

		// spasi
		for( int x=0 ; x < baris-y ; x++ ) cout << c2;

		cout << endl;
	}
}

void
segitiga_terbalik(char c1, char c2, int baris, bool spaced)
{

	for ( int y=baris; y >= 0 ; y-- ) {
		// spasi
		for( int x=y ; x < baris   ; x++ ) cout << c2;

		// badan
	 	for( int x=0 ; x <= y*2    ; x++ ) cout << ((x % 2 == 0 && spaced ) ? c2 : c1);

		// spasi
		for( int x=0 ; x < baris-y ; x++ ) cout << c2;
		cout << endl;
	}
}

void
setengah_segitiga_rata_kiri(char c1, char c2, int baris)
{
	for( int y=baris ; y > 0 ; y--) {

		// spasi
		for( int x=0; x <= baris-y ; x++ ) cout << c2;

		//badan
		for( int x=0; x < y        ; x++ )  cout << c1;

		cout << endl;
	}
}

void
setengah_segitiga_rata_kanan(char c1, char c2, int baris)
{
	for( int y=0 ; y < baris ; y++ ) {

		// spasi
		for(int x=0 ; x < baris-y ; x++) cout << c2;

		//badan
		for(int x=0 ; x <= y      ; x++) cout << c1;

		cout << endl;
	}
}

void
segitiga_rata_kanan(char c1, char c2, int baris)
{
	for(int y=0 ; y < (baris-(baris/2))  ; y++ ) {

		for(int x=0 ; x < (baris/2)-y ; x++) cout << c1;

		for(int x=0 ; x <= y ; x++) cout << c2;

		cout << endl;
	}

	for( int y=(baris/2) ; y > 0 ; y--) {
		for( int x=0; x <= (baris/2)-y ; x++ ) cout << c1;

		for( int x=0; x < y ; x++ )  cout << c2;

		cout << endl;
	}
}

void
segitiga_rata_kiri(char c1, char c2, int baris)
{

	for( int y=(baris-(baris/2)) ; y >= 0 ; y--) {

		// spasi
		for( int x=0; x <= baris/2-y ; x++ ) cout << c2;

		//badan
		for( int x=0; x < y        ; x++ )  cout << c1;

		cout << endl;
	}

	for( int y=0 ; y < baris/2 ; y++ ) {

		// spasi
		for(int x=0 ; x < baris/2-y ; x++) cout << c2;

		//badan
		for(int x=0 ; x <= y      ; x++) cout << c1;

		cout << endl;
	}
}

int
main()
{
	int baris;
	cout << "Masukan Jumlah Baris: ";
	cin >> baris;

	cout << "1. " << endl;
	setengah_segitiga_rata_kiri(' ', '*', baris);

	cout << endl;

	cout << "2. " << endl;
	setengah_segitiga_rata_kanan('*', ' ', baris);

	cout << endl;

	cout << "3. " << endl;
	setengah_segitiga_rata_kanan(' ', '*', baris);

	cout << endl;

	cout << "4. " << endl;
	setengah_segitiga_rata_kiri('*', ' ', baris);

	cout << endl;

	cout << "5. " << endl;
	segitiga('*', ' ', baris, true);

	cout << endl;

	cout << "6. " << endl;
	segitiga_terbalik('*', ' ', baris, true);

	cout << endl;

	cout << "7. " << endl;
	segitiga_rata_kiri(' ', '*', baris);

	cout << endl;

	cout << "8. " << endl;
	segitiga_rata_kanan(' ', '*', baris);

	cout << "9. " << endl;
	setengah_segitiga_rata_kiri('-', '*', baris);

	cout << endl;

	cout << "10. " << endl;
	segitiga_terbalik(' ', '*', baris, false);

	cout << endl;

	cout << "11. " << endl;
	setengah_segitiga_rata_kanan('*', '-', baris);

	cout << endl;

	cout << "12. " << endl;
	segitiga(' ', '*', baris, false);

	cout << endl;

	cout << "13. " << endl;
	segitiga('*', ' ', baris, false);

	cout << endl;

	return 0;
}
