#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct mahasiswa {
    string nim;
    string nama;
    string gender;
    string nilaiStrukData;
};

struct Node {
    mahasiswa data;
    Node* next;
};

Node* head = nullptr;

bool isNimExists(string nim) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.nim == nim) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void tambahData() {
    Node* newNode = new Node();
    cout << "\n=== Tambah Data mahasiswa ===" << endl;
    
    cout << "Masukkan NIM: ";
    cin >> newNode->data.nim;
    
    if (isNimExists(newNode->data.nim)) {
        cout << "Error: NIM sudah terdaftar!" << endl;
        delete newNode;
        return;
    }
    
    cout << "Masukkan Nama: ";
    cin  >> newNode->data.nama;
    cout << "Masukkan Gender: ";
    cin  >> newNode->data.gender;
    cout << "Masukkan Nilai Struck Data: ";
    cin  >> newNode->data.nilaiStrukData;
    
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Data mahasiswa berhasil ditambahkan!" << endl;
}

void tampilkanDetailData(mahasiswa k) {
    cout << "NIM               : " << k.nim << endl;
    cout << "Nama              : " << k.nama << endl;
    cout << "Gender            : " << k.gender << endl;
    cout << "Nilai Struck Data : " << k.nilaiStrukData << endl;
    cout << "---------------------------------------" << endl;
}
void tampilkanSemuaData() {
    if (head == nullptr) {
        cout << "\nDatabase mahasiswa kosong." << endl;
        return;
    }
    
    Node* temp = head;
    cout << "\n=== Daftar Semua mahasiswa ===" << endl;
    int no = 1;
    while (temp != nullptr) {
        cout << "Data ke-" << no++ << ":" << endl;
        tampilkanDetailData(temp->data);
        temp = temp->next;
    }
}

void cariData() {
    if (head == nullptr) {
        cout << "\nDatabase Mahasiswa kosong." << endl;
        return;
    }
    
    string cariNim;
    cout << "\nMasukkan NIM yang dicari: ";
    cin >> cariNim;
    
    Node* temp = head;
    bool ditemukan = false;
    
    while (temp != nullptr) {
        if (temp->data.nim == cariNim) {
            cout << "\nData Ditemukan:" << endl;
            tampilkanDetailData(temp->data);
            ditemukan = true;
            break;
        }
        temp = temp->next;
    }
    
    if (!ditemukan) {
        cout << "Data Mahasiswa dengan NIM tersebut tidak ditemukan." << endl;
    }
}

void updateData() {
    if (head == nullptr) {
        cout << "\nDatabase Mahasiswa kosong." << endl;
        return;
    }
    
    string cariNim;
    cout << "\nMasukkan NIM data yang ingin diubah: ";
    cin >> cariNim;
    
    Node* temp = head;
    bool ditemukan = false;
    
    while (temp != nullptr) {
        if (temp->data.nim == cariNim) {
            ditemukan = true;
            cout << "\nData Lama ditemukan. Silahkan masukkan data baru:" << endl;
            
            cin.ignore();
            cout << "Masukkan Nama Baru: ";
            cin  >> temp->data.nama;
            cout << "Masukkan Gender Baru: ";
            cin  >> temp->data.gender;
            cout << "Masukkan Nilai Struck Data Baru: ";
            cin  >> temp->data.nilaiStrukData;
            
            cout << "Data mahasiswa berhasil diperbarui!" << endl;
            break;
        }
        temp = temp->next;
    }
    
    if (!ditemukan) {
        cout << "Data mahasiswa dengan NIM tersebut tidak ditemukan." << endl;
    }
}

void hapusData() {
    if (head == nullptr) {
        cout << "\nDatabase Mahasiswa kosong." << endl;
        return;
    }
    
    string cariNim;
    cout << "\nMasukkan NIM data yang ingin dihapus: ";
    cin >> cariNim;
    
    Node* temp = head;
    Node* prev = nullptr;
    bool ditemukan = false;
    
    if (temp != nullptr && temp->data.nim == cariNim) {
        head = temp->next;
        delete temp;
        cout << "Data Mahasiswa dengan NIM " << cariNim << " berhasil dihapus!" << endl;
        return;
    }
    
    while (temp != nullptr && temp->data.nim != cariNim) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp != nullptr) {
        prev->next = temp->next;
        delete temp;
        cout << "Data Mahasiswa dengan NIM " << cariNim << " berhasil dihapus!" << endl;
    } else {
        cout << "Data Mahasiswa dengan NIM tersebut tidak ditemukan." << endl;
    }
}

int main() {
    int pilihan;
    
    do {
        cout << "\n=======================================" << endl;
        cout << "      SISTEM MANAJEMEN DATA MAHASISWA        " << endl;
        cout << "=======================================" << endl;
        cout << "1. Insert Data" << endl;
        cout << "2. Tampilkan Semua Data" << endl;
        cout << "3. Cari Data Mahasiswa (Berdasarkan NIM)" << endl;
        cout << "4. Update Data" << endl;
        cout << "5. Hapus Data " << endl;
        cout << "6. Keluar" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                tampilkanSemuaData();
                break;
            case 3:
                cariData();
                break;
            case 4:
                updateData();
                break;
            case 5:
                hapusData();
                break;
            case 6:
                cout << "\nTerima kasih! Program selesai." << endl;
                break;
            default:
                cout << "\nPilihan tidak valid! Silahkan pilih menu 1-6." << endl;
        }
    } while (pilihan != 6);
    
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    
    return 0;
}
