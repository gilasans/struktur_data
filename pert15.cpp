#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student {
    string name;
    string nim;
    string gender;
    float grade;
    Student* prev;
    Student* next;
};

Student* head = nullptr;
Student* tail = nullptr;

void showMenu();
void insertData();
void deleteData();
void printData();
void printList();
void clearData();

int main() {
    int choice;

    do {
        showMenu();

        if (!(cin >> choice)) {
            if (cin.eof()) {
                clearData();
                return 0;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Pilihan tidak valid!" << endl;
            continue;
        }

        switch (choice) {
            case 1:
                insertData();
                break;

            case 2:
                deleteData();
                break;

            case 3:
                printData();
                break;

            case 4:
                clearData();
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (choice != 4);

    return 0;
}

void printList() {
    cout << endl;

    if (head == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Student* current = head;

    cout << "HEAD";

    do {
        cout << " <-> [" << current->nim << "]";
        current = current->next;
    } while (current != head);

    cout << " <-> HEAD" << endl;
}


void insertData() {
    Student* newNode = new Student;

    cout << endl;
    cout << "Nama   : ";
    getline(cin >> ws, newNode->name);

    cout << "NIM    : ";
    cin >> newNode->nim;
    if (newNode->nim.find_first_not_of("0123456789") != string::npos) {
        cout << "NIM harus berupa angka!" << endl;
        delete newNode;
        return;
    }
    Student* current = head;

    if (current != nullptr) {
        do {
            if (current->nim == newNode->nim) {
                cout << "NIM sudah terdaftar!" << endl;
                delete newNode;
                return;
            }

            current = current->next;
        } while (current != head);
    }

    cout << "Gender : ";
    getline(cin >> ws, newNode->gender);

    cout << "Nilai  : ";
    cin >> newNode->grade;
    current = head;

    if (head == nullptr) {
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
        tail = newNode;
    }
    else {
        do {
            if (newNode->nim < current->nim) {
                break;
            }

            current = current->next;
        } while (current != head);

        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;

        if (current == head && newNode->nim < head->nim) {
            head = newNode;
        }
        else if (current == head) {
            tail = newNode;
        }
    }

    cout << "Data berhasil ditambahkan!" << endl;
    printList();
}


void deleteData() {
    if (head == nullptr) {
        cout << "Data masih kosong!" << endl;
        return;
    }

    string nim;

    cout << endl;
    cout << "Masukkan NIM yang dihapus: ";
    cin >> nim;

    Student* current = head;

    do {
        if (current->nim == nim) {
            break;
        }

        current = current->next;
    } while (current != head);

    if (current->nim != nim) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (current == head) {
            head = current->next;
        }

        if (current == tail) {
            tail = current->prev;
        }
    }

    delete current;

    cout << "Data berhasil dihapus!" << endl;
    printList();
}

void printData() {
    if (head == nullptr) {
        cout << "Data masih kosong!" << endl;
        return;
    }

    Student* current = head;
    int number = 1;

    cout << endl;
    cout << "DAFTAR MAHASISWA" << endl;
    cout << "==============================" << endl;

    do {
        cout << "Data ke-" << number << endl;
        cout << "Nama   : " << current->name << endl;
        cout << "NIM    : " << current->nim << endl;
        cout << "Gender : " << current->gender << endl;
        cout << "Nilai  : " << current->grade << endl;
        cout << "==============================" << endl;

        current = current->next;
        number++;
    } while (current != head);

    printList();
}

void clearData() {
    if (head != nullptr) {
        Student* current = head->next;

        while (current != head) {
            Student* temp = current;
            current = current->next;
            delete temp;
        }

        delete head;
    }

    head = nullptr;
    tail = nullptr;
}

void showMenu() {
    cout << endl;
    cout << "  CIRCULAR DOUBLY LINKED LIST" << endl;
    cout << "================================" << endl;
    cout << "1. INSERT DATA" << endl;
    cout << "2. HAPUS DATA" << endl;
    cout << "3. CETAK DATA" << endl;
    cout << "4. EXIT" << endl;
    cout << "Pilihan : ";
}