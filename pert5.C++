#include <iostream>
using namespace std;

#define MAX 5

int queueData[MAX];
int front = -1;
int rear = -1;

bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    return ((rear + 1) % MAX == front);
}

void enqueue(int data) {
    
    if (isFull()) {
        cout << "\nQueue Penuh! Data tidak dapat ditambahkan.\n";
        return;
    }
    
    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        
        rear = (rear + 1) % MAX;
    }

    queueData[rear] = data;

    cout << "\nData " << data << " berhasil dimasukkan.\n";
    cout << "FRONT = " << front << endl;
    cout << "REAR  = " << rear << endl;
}


void dequeue() {
    
    if (isEmpty()) {
        cout << "\nQueue Kosong! Tidak ada data yang dapat dihapus.\n";
        return;
    }

    int data = queueData[front];

    
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        
        front = (front + 1) % MAX;
    }

    cout << "\nData " << data << " berhasil dihapus.\n";

    if (isEmpty()) {
        cout << "Queue sekarang kosong.\n";
    } else {
        cout << "FRONT = " << front << endl;
        cout << "REAR  = " << rear << endl;
    }
}


void display() {
    if (isEmpty()) {
        cout << "\nQueue Kosong.\n";
        return;
    }

    cout << "\n================================\n";
    cout << "       ISI CIRCULAR QUEUE\n";
    cout << "================================\n";

    cout << "Index : ";

    int i = front;

    while (true) {
        cout << i << " ";

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    cout << "\nData  : ";

    i = front;

    while (true) {
        cout << queueData[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    cout << "\n\nFRONT = " << front;
    cout << "\nREAR  = " << rear;
    cout << "\n================================\n";
}


void displayArray() {
    cout << "\n================================\n";
    cout << "          KONDISI ARRAY\n";
    cout << "================================\n";

    cout << "Index : ";

    for (int i = 0; i < MAX; i++) {
        cout << i << "\t";
    }

    cout << "\nData  : ";

    for (int i = 0; i < MAX; i++) {
        if (front == -1) {
            cout << "-\t";
        } else {
            bool digunakan = false;
            int j = front;

            while (true) {
                if (j == i) {
                    digunakan = true;
                    break;
                }

                if (j == rear)
                    break;

                j = (j + 1) % MAX;
            }

            if (digunakan)
                cout << queueData[i] << "\t";
            else
                cout << "-\t";
        }
    }

    cout << "\n\nFRONT = " << front;
    cout << "\nREAR  = " << rear;
    cout << "\n================================\n";
}


int main() {
    int pilihan;
    int data;

    do {
        cout << "\n\n====================================\n";
        cout << "           PROGRAM CIRCULAR QUEUE\n";
        cout << "           SAIFULLAH - 03TPL011\n";
        cout << "====================================\n";
        cout << "1. Insert / Enqueue\n";
        cout << "2. Delete / Dequeue\n";
        cout << "3. Tampilkan Queue\n";
        cout << "4. Tampilkan Array\n";
        cout << "5. Keluar\n";
        cout << "====================================\n";

        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nMasukkan data : ";
                cin >> data;
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                displayArray();
                break;

            case 5:
                cout << "\nProgram selesai.\n";
                break;

            default:
                cout << "\nPilihan tidak tersedia!\n";
        }

    } while (pilihan != 5);

    return 0;
}