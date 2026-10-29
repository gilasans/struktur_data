#include <iostream>
using namespace std;

#define MAX 10

int S[MAX];
int TOP1 = -1;
int TOP2 = MAX;

void PUSH1(int data) {
    if (TOP1 + 1 == TOP2) {
        cout << "\nStack Penuh! PUSH1 tidak dapat dilakukan.\n";
    } else {
        TOP1++;
        S[TOP1] = data;
        
        cout << "\nData " << data << " berhasil dimasukkan ke Stack 1.\n";
    }
}

void POP1() {
    if (TOP1 == -1) {
        cout << "\nStack 1 Kosong! POP1 tidak dapat dilakukan.\n"; 
    } else {
        cout << "\nData " << S[TOP1]
             << " dihapus dari Stack 1.\n";
        
        TOP1--;
    }
}

void PUSH2(int data) {
    if (TOP1 + 1 == TOP2) {
        cout << "\nStack Penuh! PUSH2 tidak dapat dilakukan.\n";
    } else {
        TOP2--;
        S[TOP2] = data;

        cout << "\nData " << data << " berhasil dimasukkan ke Stack 2.\n";
    }
}

void POP2() {
    if (TOP2 == MAX) {
        cout << "\nStack 2 Kosong! POP2 tidak dapat dilakukan.\n";
    } else {
        cout << "\nData " << S[TOP2]
             << " dihapus dari Stack 2.\n";
        
        TOP2++;
    }
}




void tampilkanStack() {
    cout << "\n==============================================";
    cout << "\n             KONDISI DOUBLE STACK";
    cout << "\n==============================================\n";

    cout << "TOP1 = " << TOP1 << endl;
    cout << "TOP2 = " << TOP2 << endl;

    cout << "\nIsi Array:\n";

    for (int i = 0; i < MAX; i++) {
        cout << "Index [" << i << "] = ";

        if (i <= TOP1) {
            cout << S[i] << " <- Stack 1";
        }
        else if (i >= TOP2) {
            cout << S[i] << " <- Stack 2";
        }
        else {
            cout << "-";
        }

        cout << endl;
    } 

    cout << "\n-----------------------------------------";

    cout << "\nStack 1 : ";
    if (TOP1 == -1) {
        cout << "Kosong";
    } else {
        for (int i = TOP1; i >= 0; i--) {
            cout << S[i] << " ";
        }
    }

    cout << "\nStack 2 : ";
    if (TOP2 == MAX) {
        cout << "Kosong";
    } else {
        for (int i = TOP2; i < MAX; i++) {
            cout << S[i] << " ";
        }
    }

    cout << "\n=========================================\n";
} 



int main() {

    int pilihan;
    int data;

    do {
        cout << "\n\n==========================================";
        cout << "\n         PROGRAM DOUBLE STACK";
        cout << "\n==========================================";
        cout << "\n1. PUSH1";
        cout << "\n2. POP1";
        cout << "\n3. PUSH2";
        cout << "\n4. POP2";
        cout << "\n5. Tampilkan Stack";
        cout << "\n6. Keluar";
        cout << "\n==========================================";
        cout << "\nMasukkan pilihan : ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << "Masukkan data Stack 1 : ";
                cin >> data;
                PUSH1(data);
                break;

            case 2:
                POP1();
                break;

            case 3:
                cout << "Masukkan data Stack 2 : ";
                cin >> data;
                PUSH2(data);
                break;

            case 4:
                POP2();
                break;

            case 5:
                tampilkanStack(); 
                break;

            case 6:
                cout << "\n program selesai.";
                break;

            default:
                cout << "\nPilihan tidak tidak tersedia!";
                break;
        }

    } while (pilihan != 6);

    return 0;
}

