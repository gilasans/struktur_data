#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
	string nim;
	string nama;
	int umur;
	float ipk;
};

int main() {
	Mahasiswa mhs;
	
	mhs.nim = "251011400748";
	mhs.nama = "Saifullah";
	mhs.umur = 23;
	mhs.ipk = 4;
	
	cout << "NIM : " << mhs.nim << endl;
	cout << "Nama : " << mhs.nama << endl;
	cout << "Umur : " << mhs.umur << endl;
	cout << "IPK : " << mhs.ipk << endl;
	
	return 0;
}