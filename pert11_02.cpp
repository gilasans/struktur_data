#include <iostream>
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    double nilaiStrukturData;
    Mahasiswa* next;
};

void bersihkanLayar() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void jeda(int milidetik) {
    this_thread::sleep_for(chrono::milliseconds(milidetik));
}

void animasiTeks(const string& teks) {
    cout << "\n" << teks;
    for (int i = 0; i < 3; i++) {
        jeda(250);
        cout << ".";
        cout.flush();
    }
    cout << "\n";
    jeda(200);
}

bool isEmpty(Mahasiswa* top) {
    return top == nullptr;
}

void visualisasiStack(Mahasiswa* top) {
    if (isEmpty(top)) {
        cout << " [ KOSONG / NULL ]\n";
    } else {
        Mahasiswa* current = top;
        int nomor = 1;
        while (current != nullptr) {
            cout << " +------------------------------------------------------------------+\n";
            cout << " | " << left << setw(4) << nomor << " | NAMA   : " << setw(50) << current->nama << " |\n";
            cout << " |      | NIM    : " << setw(50) << current->nim << " |\n";
            cout << " |      | GENDER : " << setw(50) << current->gender << " |\n";
            cout << " |      | NILAI  : " << setw(50) << fixed << setprecision(2) << current->nilaiStrukturData << " |\n";
            cout << " +------------------------------------------------------------------+\n";
            
            current = current->next;
            nomor++;
        }
    }
    cout << "======================================================================\n";
}

void insertData(Mahasiswa*& top) {
    bersihkanLayar();
    cout << "======================================================================\n";
    cout << "            INSERT DATA MAHASISWA                  \n";
    cout << "======================================================================\n";

    Mahasiswa* baru = new Mahasiswa();
    cout << " Masukkan Nama                : ";
    getline(cin >> ws, baru->nama);
    cout << " Masukkan NIM                 : ";
    getline(cin, baru->nim);
    cout << " Masukkan Gender (L/P)        : ";
    getline(cin, baru->gender);
    cout << " Masukkan Nilai Struktur Data : ";
    while (!(cin >> baru->nilaiStrukturData)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << " Nilai tidak valid. Masukkan angka: ";
    }
    cin.ignore(10000, '\n');

    bersihkanLayar();
    cout << "======================================================================\n";
    cout << "                 ANIMASI PROSES INSERT                          \n";
    cout << "======================================================================\n";
    cout << " [1/3] Alokasi simpul dinamis baru secara langsung...\n";
    cout << "       Simpul Baru: [" << baru->nim << " - " << baru->nama << "]\n";
    jeda(600);

    cout << "\n [2/3] Menyambungkan pointer next simpul baru langsung ke TOP lama...\n";
    baru->next = top;
    jeda(600);

    cout << "\n [3/3] Memperbarui penunjuk puncak TOP ke simpul baru (tanpa head)...\n";
    top = baru;
    jeda(600);

    animasiTeks(" Menyimpan data ke dalam Stack LIFO");
    cout << "\n [BERHASIL] Data mahasiswa " << baru->nama << " berhasil ditumpuk di TOP!\n\n";
    visualisasiStack(top);

    cout << "\n Tekan Enter untuk kembali ke menu utama...";
    cin.get();
}

void hapusData(Mahasiswa*& top) {
    bersihkanLayar();
    cout << "======================================================================\n";
    cout << "             HAPUS DATA MAHASISWA                    \n";
    cout << "======================================================================\n";

    if (isEmpty(top)) {
        cout << " [PERINGATAN] Stack dalam keadaan KOSONG (Stack Underflow)!\n";
        cout << " Tidak ada data mahasiswa yang dapat dikeluarkan.\n";
        cout << "======================================================================\n";
        cout << "\n Tekan Enter untuk kembali ke menu utama...";
        cin.get();
        return;
    }

    Mahasiswa* hapusNode = top;
    string namaDihapus = hapusNode->nama;
    string nimDihapus = hapusNode->nim;

    cout << " [1/3] Mengakses simpul di puncak tumpukan (TOP)...\n";
    cout << "       Data yang dikeluarkan: " << nimDihapus << " - " << namaDihapus << "\n";
    jeda(600);

    cout << "\n [2/3] Menggeser penunjuk TOP langsung ke simpul di bawahnya...\n";
    top = top->next;
    jeda(600);

    cout << "\n [3/3] Menghapus dan mendealokasikan memori simpul teratas...\n";
    delete hapusNode;
    jeda(600);

    animasiTeks(" Memproses pengeluaran data dari puncak tumpukan");
    cout << "\n [BERHASIL] Data mahasiswa [" << nimDihapus << " - " << namaDihapus << "] berhasil dikeluarkan!\n\n";
    visualisasiStack(top);

    cout << "\n Tekan Enter untuk kembali ke menu utama...";
    cin.get();
}

void cetakData(Mahasiswa* top) {
    bersihkanLayar();
    cout << "======================================================================\n";
    cout << "              CETAK DATA STACK MAHASISWA                \n";
    cout << "======================================================================\n";

    if (isEmpty(top)) {
        cout << " Stack masih kosong! Tidak ada data mahasiswa tersimpan.\n";
    } else {
        Mahasiswa* current = top;
        int no = 1;
        cout << left << setw(5) << "NO" 
             << setw(16) << "NIM" 
             << setw(26) << "NAMA" 
             << setw(10) << "GENDER" 
             << setw(15) << "NILAI STRUKTUR DATA" << "\n";
        cout << string(70, '-') << "\n";
        while (current != nullptr) {
            cout << left << setw(5) << no 
                 << setw(16) << current->nim 
                 << setw(26) << current->nama 
                 << setw(10) << current->gender 
                 << setw(15) << fixed << setprecision(2) << current->nilaiStrukturData << "\n";
            current = current->next;
            no++;
        }
        cout << string(70, '-') << "\n";
        cout << " Total Data Mahasiswa dalam Stack: " << (no - 1) << "\n\n";
        visualisasiStack(top);
    }

    cout << "\n Tekan Enter untuk kembali ke menu utama...";
    cin.get();
}

int main() {
    Mahasiswa* top = nullptr;
    int pilihan = 0;

    do {
        bersihkanLayar();
        cout << "======================================================================\n";
        cout << "         DATA MAHASISWA             \n";
        cout << "======================================================================\n";
        cout << " 1. INSERT DATA\n";
        cout << " 2. HAPUS DATA\n";
        cout << " 3. CETAK DATA\n";
        cout << " 4. EXIT\n";
        cout << "======================================================================\n";
        cout << " Masukkan pilihan [1-4]: ";
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(10000, '\n');
            pilihan = 0;
        } else {
            cin.ignore(10000, '\n');
        }

        switch (pilihan) {
            case 1:
                insertData(top);
                break;
            case 2:
                hapusData(top);
                break;
            case 3:
                cetakData(top);
                break;
            case 4:
                bersihkanLayar();
                animasiTeks(" Sedang keluar dari program");
                cout << "\n Terima kasih telah menggunakan program animasi Stack tanpa Head!\n\n";
                break;
            default:
                cout << "\n Pilihan tidak valid! Silakan masukkan angka 1 - 4.\n";
                jeda(1000);
                break;
        }
    } while (pilihan != 4);

    while (top != nullptr) {
        Mahasiswa* temp = top;
        top = top->next;
        delete temp;
    }

    return 0;
}

