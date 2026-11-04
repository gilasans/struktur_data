#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    float nilai;
    Mahasiswa* next;
    Mahasiswa* prev;
};

Mahasiswa* createNode(string nama, string nim, string gender, float nilai) {
    Mahasiswa* newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->gender = gender;
    newNode->nilai = nilai;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertData(Mahasiswa*& head) {
    string nama, nim, gender;
    float nilai;

    cout << "\n--- INSERT DATA ---\n";
    cout << "Masukkan NIM   : "; cin >> nim;
    cout << "Masukkan Nama  : "; cin >> nama;
    cout << "Masukkan Gender: "; cin >> gender;
    cout << "Masukkan Nilai : "; cin >> nilai;

    Mahasiswa* newNode = createNode(nama, nim, gender, nilai);


    if (head == nullptr) {
        head = newNode;
        cout << "Data pertama berhasil ditambahkan!\n";
        return;
    }


    if (nim < head->nim) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        cout << "Data berhasil ditambahkan di awal!\n";
        return;
    }


    Mahasiswa* curr = head;
    while (curr->next != nullptr && curr->next->nim < nim) {
        curr = curr->next;
    }


    newNode->next = curr->next;
    if (curr->next != nullptr) {
        curr->next->prev = newNode;
    }
    curr->next = newNode;
    newNode->prev = curr;

    cout << "Data berhasil ditambahkan secara terurut!\n";
}

void hapusData(Mahasiswa*& head) {
    if (head == nullptr) {
        cout << "\nLinked List kosong! Tidak ada data yang bisa dihapus.\n";
        return;
    }

    string targetNim;
    cout << "\n--- HAPUS DATA ---\n";
    cout << "Masukkan NIM data yang ingin dihapus: "; cin >> targetNim;

    Mahasiswa* curr = head;


    while (curr != nullptr && curr->nim != targetNim) {
        curr = curr->next;
    }


    if (curr == nullptr) {
        cout << "Data dengan NIM " << targetNim << " tidak ditemukan.\n";
        return;
    }


    if (curr == head) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
    } 

    else {
        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        }
        curr->prev->next = curr->next;
    }

    delete curr;
    cout << "Data dengan NIM " << targetNim << " berhasil dihapus.\n";
}

void cetakData(Mahasiswa* head) {
    if (head == nullptr) {
        cout << "\nLinked List kosong! Belum ada data mahasiswa.\n";
        return;
    }

    cout << "\n-------------------------------------------------------------\n";
    cout << left << setw(15) << "NIM" << setw(20) << "NAMA" << setw(10) << "GENDER" << setw(8) << "NILAI" << "\n";
    cout << "-------------------------------------------------------------\n";

    Mahasiswa* curr = head;
    while (curr != nullptr) {
        cout << left << setw(15) << curr->nim 
             << setw(20) << curr->nama 
             << setw(10) << curr->gender 
             << setw(8) << fixed << setprecision(2) << curr->nilai << "\n";
        curr = curr->next;
    }
    cout << "-------------------------------------------------------------\n";


    curr = head;
    while (curr != nullptr) {
        cout << "[" << curr->nim << "]";
        if (curr->next != nullptr) {
            cout << " <==> ";
        }
        curr = curr->next;
    }
    cout << "\n";
}

int main() {
    Mahasiswa* head = nullptr;
    int pilihan;

    do {
        cout << "\n      PROGRAM DATA MAHASISWA\n";
        cout << "===================================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA   4. EXIT\n";
        cout << "Pilihan (1 - 4) : ";
        
    
        if (!(cin >> pilihan)) {
            cout << "Input harus berupa angka!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (pilihan) {
            case 1:
                insertData(head);
                break;
            case 2:
                hapusData(head);
                break;
            case 3:
                cetakData(head);
                break;
            case 4:
                cout << "\nProgram selesai. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid! Silakan pilih menu 1-4.\n";
        }
    } while (pilihan != 4);

    return 0;
}
