#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct KTP {
    string nik;
    string nama;
    string tempatLahir;
    string tanggalLahir;
    string jenisKelamin;
    string alamat;
    string agama;
    string statusPerkawinan;
    string pekerjaan;
    string kewarganegaraan;
};

struct Node {
    KTP data;
    Node* next;
};

Node* head = nullptr;

bool isNikExists(string nik) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.nik == nik) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void tambahKTP() {
    Node* newNode = new Node();
    cout << "\n=== Tambah Data KTP ===" << endl;
    
    cout << "Masukkan NIK: ";
    cin >> newNode->data.nik;
    
    if (isNikExists(newNode->data.nik)) {
        cout << "Error: NIK sudah terdaftar!" << endl;
        delete newNode;
        return;
    }
    
    cout << "Masukkan Nama: ";
    getline(cin, newNode->data.nama);
    cout << "Masukkan Tempat Lahir: ";
    getline(cin, newNode->data.tempatLahir);
    cout << "Masukkan Tanggal Lahir (DD-MM-YYYY): ";
    getline(cin, newNode->data.tanggalLahir);
    cout << "Masukkan Jenis Kelamin: ";
    getline(cin, newNode->data.jenisKelamin);
    cout << "Masukkan Alamat: ";
    getline(cin, newNode->data.alamat);
    cout << "Masukkan Agama: ";
    getline(cin, newNode->data.agama);
    cout << "Masukkan Status Perkawinan: ";
    getline(cin, newNode->data.statusPerkawinan);
    cout << "Masukkan Pekerjaan: ";
    getline(cin, newNode->data.pekerjaan);
    cout << "Masukkan Kewarganegaraan: ";
    getline(cin, newNode->data.kewarganegaraan);
    
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
    cout << "Data KTP berhasil ditambahkan!" << endl;
}

void tampilkanDetailKTP(KTP k) {
    cout << "NIK               : " << k.nik << endl;
    cout << "Nama              : " << k.nama << endl;
    cout << "Tempat/Tgl Lahir  : " << k.tempatLahir << ", " << k.tanggalLahir << endl;
    cout << "Jenis Kelamin     : " << k.jenisKelamin << endl;
    cout << "Alamat            : " << k.alamat << endl;
    cout << "Agama             : " << k.agama << endl;
    cout << "Status Perkawinan : " << k.statusPerkawinan << endl;
    cout << "Pekerjaan         : " << k.pekerjaan << endl;
    cout << "Kewarganegaraan   : " << k.kewarganegaraan << endl;
    cout << "---------------------------------------" << endl;
}

void tampilkanSemuaKTP() {
    if (head == nullptr) {
        cout << "\nDatabase KTP kosong." << endl;
        return;
    }
    
    Node* temp = head;
    cout << "\n=== Daftar Semua KTP ===" << endl;
    int no = 1;
    while (temp != nullptr) {
        cout << "Data ke-" << no++ << ":" << endl;
        tampilkanDetailKTP(temp->data);
        temp = temp->next;
    }
}

void cariKTP() {
    if (head == nullptr) {
        cout << "\nDatabase KTP kosong." << endl;
        return;
    }
    
    string cariNik;
    cout << "\nMasukkan NIK yang dicari: ";
    cin >> cariNik;
    
    Node* temp = head;
    bool ditemukan = false;
    
    while (temp != nullptr) {
        if (temp->data.nik == cariNik) {
            cout << "\nData Ditemukan:" << endl;
            tampilkanDetailKTP(temp->data);
            ditemukan = true;
            break;
        }
        temp = temp->next;
    }
    
    if (!ditemukan) {
        cout << "Data KTP dengan NIK tersebut tidak ditemukan." << endl;
    }
}

void updateKTP() {
    if (head == nullptr) {
        cout << "\nDatabase KTP kosong." << endl;
        return;
    }
    
    string cariNik;
    cout << "\nMasukkan NIK data yang ingin diubah: ";
    cin >> cariNik;
    
    Node* temp = head;
    bool ditemukan = false;
    
    while (temp != nullptr) {
        if (temp->data.nik == cariNik) {
            ditemukan = true;
            cout << "\nData Lama ditemukan. Silahkan masukkan data baru:" << endl;
            
            cin.ignore();
            cout << "Masukkan Nama Baru: ";
            getline(cin, temp->data.nama);
            cout << "Masukkan Tempat Lahir Baru: ";
            getline(cin, temp->data.tempatLahir);
            cout << "Masukkan Tanggal Lahir Baru (DD-MM-YYYY): ";
            getline(cin, temp->data.tanggalLahir);
            cout << "Masukkan Jenis Kelamin Baru: ";
            getline(cin, temp->data.jenisKelamin);
            cout << "Masukkan Alamat Baru: ";
            getline(cin, temp->data.alamat);
            cout << "Masukkan Agama Baru: ";
            getline(cin, temp->data.agama);
            cout << "Masukkan Status Perkawinan Baru: ";
            getline(cin, temp->data.statusPerkawinan);
            cout << "Masukkan Pekerjaan Baru: ";
            getline(cin, temp->data.pekerjaan);
            cout << "Masukkan Kewarganegaraan Baru: ";
            getline(cin, temp->data.kewarganegaraan);
            
            cout << "Data KTP berhasil diperbarui!" << endl;
            break;
        }
        temp = temp->next;
    }
    
    if (!ditemukan) {
        cout << "Data KTP dengan NIK tersebut tidak ditemukan." << endl;
    }
}

void hapusKTP() {
    if (head == nullptr) {
        cout << "\nDatabase KTP kosong." << endl;
        return;
    }
    
    string cariNik;
    cout << "\nMasukkan NIK data yang ingin dihapus: ";
    cin >> cariNik;
    
    Node* temp = head;
    Node* prev = nullptr;
    bool ditemukan = false;
    
    if (temp != nullptr && temp->data.nik == cariNik) {
        head = temp->next;
        delete temp;
        cout << "Data KTP dengan NIK " << cariNik << " berhasil dihapus!" << endl;
        return;
    }
    
    while (temp != nullptr && temp->data.nik != cariNik) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp != nullptr) {
        prev->next = temp->next;
        delete temp;
        cout << "Data KTP dengan NIK " << cariNik << " berhasil dihapus!" << endl;
    } else {
        cout << "Data KTP dengan NIK tersebut tidak ditemukan." << endl;
    }
}

int main() {
    int pilihan;
    
    do {
        cout << "\n=======================================" << endl;
        cout << "      SISTEM MANAJEMEN DATA KTP        " << endl;
        cout << "=======================================" << endl;
        cout << "1. Tambah Data KTP" << endl;
        cout << "2. Tampilkan Semua Data KTP" << endl;
        cout << "3. Cari Data KTP (Berdasarkan NIK)" << endl;
        cout << "4. Update Data KTP" << endl;
        cout << "5. Hapus Data KTP" << endl;
        cout << "6. Keluar" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tambahKTP();
                break;
            case 2:
                tampilkanSemuaKTP();
                break;
            case 3:
                cariKTP();
                break;
            case 4:
                updateKTP();
                break;
            case 5:
                hapusKTP();
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
