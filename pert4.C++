#include <iostream>
using namespace std;

int main()
{
    int S[10];
    int TOP = -1;
    int data;

    while (true)
    {
        cout << "Input data : ";
        cin >> data;

        if (data == 999)
        {
            cout << "Program selesai." << endl;
            break;
        }

        if (data >= 60)
        {
            if (TOP < 9)
            {
                TOP++;
                S[TOP] = data;
                cout << "Data " << data << " berhasil di-PUSH." << endl;
            }
            else
            {
                cout << "Stack Penuh" << endl;
                break;
            }
        }
        else
        {
            if (TOP >= 0)
            {
                data = S[TOP];
                TOP--;
                cout << "Data yang di-POP = " << data << endl;
            }
            else
            {
                cout << "Stack Kosong" << endl;
                break;
            }
        }
    }

    return 0;
}
