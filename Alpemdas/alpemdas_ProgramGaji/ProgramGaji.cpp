#include <iostream>
#include <limits>
#include <ostream>

using namespace std;

void
clear_screen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void
prompt(string s)
{
	cout << s;
	cout.flush();
}

void
get_num(int &v)
{
	cin >> v;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void
get_num(long &v)
{
	cin >> v;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void
get_num(short &v)
{
	cin >> v;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int
main(void)
{

	const float persen_tunjangan = 10.0f / 100.0f;
	const float persen_lembur = 5.0f / 100.0f;

	string nama;

	short jam_lembur;

	// max 5 digits
	long nik;

	// max 11 digits < 2,147,483,675
	int tunjangan, upah_lembur, gaji_pokok, total_gaji;

	jam_lembur = tunjangan = upah_lembur = gaji_pokok = total_gaji = nik =
	    -1;

	prompt("******************* PROGRAM PEGAJIAN v0.1 "
	       "***********************\n");

	prompt(" NIK                           : ");
	if (nik == -1) {
		get_num(nik);
	} else
		prompt(to_string(nik) + "\n");

	prompt(" NAMA KARYAWAN                 : ");
	if (nama.empty())
		getline(cin, nama);
	else
		prompt(nama + "\n");

	prompt(" GAJI POKOK                    : Rp.");
	if (gaji_pokok < 0)
		get_num(gaji_pokok);
	else
		prompt(to_string(gaji_pokok) + "\n");

	prompt(" JUMLAH JAM LEMBUR             : ");
	if (jam_lembur < 0)
		get_num(jam_lembur);
	else
		prompt(to_string(jam_lembur) + "\n");

	upah_lembur = (persen_lembur * gaji_pokok) * jam_lembur;
	tunjangan = persen_tunjangan * gaji_pokok;
	total_gaji = upah_lembur + tunjangan + gaji_pokok;

	prompt("***************************************************************"
	       "**\n");

	prompt(" NIK                           : " + to_string(nik) + "\n");
	prompt(" NAMA KARYAWAN                 : " + nama + "\n");
	prompt(" GAJI POKOK                    : Rp." + to_string(gaji_pokok) +
	       "\n");
	prompt(" TUNJANGAN KERJA               : Rp." + to_string(tunjangan) +
	       "\n");
	prompt(" UPAH LEMBUR                   : RP." + to_string(upah_lembur) +
	       "\n");
	prompt(" TOTAL GAJI                    : Rp." + to_string(total_gaji) +
	       "\n");

	prompt("***************************************************************"
	       "**\n");

	return 0;
}
