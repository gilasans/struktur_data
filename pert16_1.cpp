#include <iostream> 
using namespace std; 
 
int search(int arr[], int n, int x) ;
 
int main() 
{ 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int x = 10; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    int result = search(arr, n, x);
    cout << endl;
    (result == -1) ? cout << "Elemen tidak ada dalam array" : cout << "Elemen ada di indeks " << result; 

    cout << endl << endl;
    cout << "===================================" << endl;
    cout << "Muhammad Saifullah - 251011400748" << endl;
    cout << "03TPLE011" << endl;
    cout << "===================================" << endl;

    return 0; 
}

int search(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
    if (arr[i] == x) 
    return i; 
    return -1; 
} 