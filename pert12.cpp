#include <iostream>
#include <string>

using namespace std;


struct Node {
    string NIM;
    string NAMA;
    int NILAI;
    Node* LEFT;
    Node* RIGHT;
};

Node* Q = nullptr; 


void insertData(string nim, string nama, int nilai) {
    Node* newNode = new Node();
    newNode->NIM = nim;
    newNode->NAMA = nama;
    newNode->NILAI = nilai;
    newNode->LEFT = nullptr;
    newNode->RIGHT = nullptr;

    
    if (Q == nullptr) {
        Q = newNode;
        return;
    }

    
    if (nilai < Q->NILAI) {
        newNode->RIGHT = Q;
        Q->LEFT = newNode;
        Q = newNode;
        return;
    }

    
    Node* curr = Q;
    while (curr->RIGHT != nullptr && curr->RIGHT->NILAI < nilai) {
        curr = curr->RIGHT;
    }

    
    newNode->RIGHT = curr->RIGHT;
    if (curr->RIGHT != nullptr) {
        curr->RIGHT->LEFT = newNode;
    }
    curr->RIGHT = newNode;
    newNode->LEFT = curr;
}


void tampilkanNilai90() {
    Node* curr = Q;
    bool ditemukan = false;
    cout << "\n=== Data Mahasiswa dengan Nilai = 90 ===" << endl;
    while (curr != nullptr) {
        if (curr->NILAI == 90) {
            cout << "NIM: " << curr->NIM << " | Nama: " << curr->NAMA << " | Nilai: " << curr->NILAI << endl;
            ditemukan = true;
        }
        curr = curr->RIGHT;
    }
    if (!ditemukan) {
        cout << "Tidak ada mahasiswa dengan nilai 90." << endl;
    }
}


void tampilkanSemua() {
    Node* curr = Q;
    cout << "\n=== Seluruh Data Mahasiswa (Urut Naik) ===" << endl;
    if (curr == nullptr) {
        cout << "Linked List Kosong!" << endl;
        return;
    }
    while (curr != nullptr) {
        cout << "NIM: " << curr->NIM << " | Nama: " << curr->NAMA << " | Nilai: " << curr->NILAI << endl;
        curr = curr->RIGHT;
    }
}


void hapusDataByNIM(string targetNIM) {
    if (Q == nullptr) {
        cout << "List kosong, tidak ada yang dihapus." << endl;
        return;
    }

    Node* curr = Q;

    
    while (curr != nullptr && curr->NIM != targetNIM) {
        curr = curr->RIGHT;
    }

    
    if (curr == nullptr) {
        cout << "Data dengan NIM " << targetNIM << " tidak ditemukan." << endl;
        return;
    }

    
    if (curr == Q) {
        Q = Q->RIGHT;
        if (Q != nullptr) {
            Q->LEFT = nullptr;
        }
    } else {
        
        curr->LEFT->RIGHT = curr->RIGHT;
        if (curr->RIGHT != nullptr) {
            curr->RIGHT->LEFT = curr->LEFT;
        }
    }

    delete curr;
    cout << "Data dengan NIM " << targetNIM << " berhasil dihapus." << endl;
}


void hitungRataRata() {
    if (Q == nullptr) {
        cout << "\nNilai rata-rata kelas: 0 (Belum ada data)" << endl;
        return;
    }

    Node* curr = Q;
    double totalNilai = 0;
    int jumlahMahasiswa = 0;

    while (curr != nullptr) {
        totalNilai += curr->NILAI;
        jumlahMahasiswa++;
        curr = curr->RIGHT;
    }

    double rataRata = totalNilai / jumlahMahasiswa;
    cout << "\n=== Statistik Kelas ===" << endl;
    cout << "Total Mahasiswa : " << jumlahMahasiswa << endl;
    cout << "Rata-rata Nilai : " << rataRata << endl;
}


int main() {
    
    insertData("2007140021", "Andi", 85);
    insertData("2007140022", "Budi", 90); 
    insertData("2007140023", "Citra", 75);
    insertData("2007140024", "Dewi", 90); 
    insertData("2007140025", "Eko", 95);

    
    tampilkanSemua();

    
    tampilkanNilai90();

    
    hitungRataRata();

    
    cout << "\n[Proses] Menghapus NIM 2007140022..." << endl;
    hapusDataByNIM("2007140022");

    
    tampilkanSemua();
    
    
    hitungRataRata();

    return 0;
}
