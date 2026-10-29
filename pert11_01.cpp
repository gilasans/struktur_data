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

Mahasiswa* head = nullptr;

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

bool isEmpty() {
    return head == nullptr;
}

void visualisasiStack() {
    if (isEmpty()) {
        cout << "[ KOSONG / NULL ]\n";
    } else {
       
        Mahasiswa* bantu = head;
        int nomor = 1;
        while (bantu != nullptr) {
            cout << " +------------------------------------------------------------------+\n";
            cout << " | " << left << setw(4) << nomor << " | NAMA   : " << setw(50) << bantu->nama << " |\n";
            cout << " |      | NIM    : " << setw(50) << bantu->nim << " |\n";
            cout << " |      | GENDER : " << setw(50) << bantu->gender << " |\n";
            cout << " |      | NILAI  : " << setw(50) << fixed << setprecision(2) << bantu->nilaiStrukturData << " |\n";
            cout << " +------------------------------------------------------------------+\n";
           
            bantu = bantu->next;
            nomor++;
        }
    }
    cout << "======================================================================\n";
}

void insertData() {
    bersihkanLayar();
    cout << "======================================================================\n";
    cout << "                     INSERT DATA MAHASISWA                    \n";
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
    cout << "                     ANIMASI PROSES INSERT                            \n";
    cout << "======================================================================\n";
    cout << " [1/3] Mengalokasikan simpul baru di memori...\n";
    cout << "       Node Baru: [" << baru->nim << " - " << baru->nama << "]\n";
    jeda(600);

    cout << "\n [2/3] Menghubungkan pointer 'next' node baru ke HEAD saat ini...\n";
    baru->next = head;
    jeda(600);

    cout << "\n [3/3] Memindahkan penunjuk HEAD ke node baru...\n";
    head = baru;
    jeda(600);

    animasiTeks(" Menyimpan data ke dalam Stack");
    cout << "\n [BERHASIL] Data mahasiswa " << baru->nama << " berhasil ditambahkan ke Stack!\n\n";
    visualisasiStack();

    cout << "\n Tekan Enter untuk kembali ke menu utama...";
    cin.get();
}

void hapusData() {
    bersihkanLayar();
    cout << "======================================================================\n";
    cout << "                      HAPUS DATA MAHASISWA (POP)                      \n";
    cout << "======================================================================\n";

    if (isEmpty()) {
        cout << " [PERINGATAN] Stack dalam kondisi KOSONG (Stack Underflow)!\n";
        cout << " Tidak ada data mahasiswa yang dapat dihapus.\n";
        cout << "======================================================================\n";
        cout << "\n Tekan Enter untuk kembali ke menu utama...";
        cin.get();
        return;
    }

    Mahasiswa* temp = head;
    string namaDihapus = temp->nama;
    string nimDihapus = temp->nim;

    cout << " [1/3] Mengakses simpul di puncak Stack (HEAD)...\n";
    cout << "       Data yang akan dihapus: " << nimDihapus << " - " << namaDihapus << "\n";
    jeda(600);

    cout << "\n [2/3] Menggeser penunjuk HEAD ke simpul berikutnya...\n";
    head = head->next;
    jeda(600);

    cout << "\n [3/3] Menghapus simpul teratas dari memori...\n";
    delete temp;
    jeda(600);

    animasiTeks(" Memproses pelepasan data (LIFO)");
    cout << "\n [BERHASIL] Data mahasiswa [" << nimDihapus << " - " << namaDihapus << "] berhasil dihapus dari Stack!\n\n";
    visualisasiStack();

    cout << "\n Tekan Enter untuk kembali ke menu utama...";
    cin.get();
}

void cetakData() {
    bersihkanLayar();
    cout << "======================================================================\n";
    cout << "                    CETAK DATA STACK MAHASISWA                        \n";
    cout << "======================================================================\n";

    if (isEmpty()) {
        cout << " Stack masih kosong! Belum ada data mahasiswa yang tersimpan.\n";
    } else {
        Mahasiswa* bantu = head;
        int no = 1;
        cout << left << setw(5) << "NO" 
             << setw(16) << "NIM" 
             << setw(26) << "NAMA" 
             << setw(10) << "GENDER" 
             << setw(15) << "NILAI STRUKTUR DATA" << "\n";
        cout << string(70, '-') << "\n";
        while (bantu != nullptr) {
            cout << left << setw(5) << no 
                 << setw(16) << bantu->nim 
                 << setw(26) << bantu->nama 
                 << setw(10) << bantu->gender 
                 << setw(15) << fixed << setprecision(2) << bantu->nilaiStrukturData << "\n";
            bantu = bantu->next;
            no++;
        }
        cout << string(70, '-') << "\n";
        cout << " Total Data Mahasiswa dalam Stack: " << (no - 1) << "\n\n";
        visualisasiStack();
    }

    cout << "\n Tekan Enter untuk kembali ke menu utama...";
    cin.get();
}

int main() {
    int pilihan = 0;
    do {
        bersihkanLayar();
        cout << "======================================================================\n";
        cout << "                           DATA MAHASISWA                             \n";
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
                insertData();
                break;
            case 2:
                hapusData();
                break;
            case 3:
                cetakData();
                break;
            case 4:
                bersihkanLayar();
                animasiTeks(" Sedang keluar dari program");
                cout << "\n Terima kasih telah menggunakan program animasi Stack!\n\n";
                break;
            default:
                cout << "\n Pilihan tidak valid! Silakan masukkan angka 1 - 4.\n";
                jeda(1000);
                break;
        }
    } while (pilihan != 4);

    while (head != nullptr) {
        Mahasiswa* hapus = head;
        head = head->next;
        delete hapus;
    }

    return 0;
}

