#include <vector>
#include <iostream>
using namespace std; 
 
void search(vector<int> arr, int search_Element);
 
int main() 
{ 
    vector<int> arr{ 1, 2, 3, 4, 5 }; 
    int search_element = 5; 
    
    search(arr, search_element); 

    cout << endl << endl;
    cout << "===================================" << endl;
    cout << "Muhammad Saifullah - 251011400748" << endl;
    cout << "03TPLE011" << endl;
    cout << "===================================" << endl;
}

void search(vector<int> arr, int search_Element) 
{ 
    int left = 0; 
    int length = arr.size(); 
    int position = -1; 
    int right = length - 1; 
 
    for(left = 0; left <= right;) 
    { 
        
        if (arr[left] == search_Element) 
        { 
            position = left; 
            cout << "Elemen ditemukan dalam Array di " << position + 1 << " Posisikan dengan " << left + 1 << " Attempt"; 
            
            break; 
        } 
        
        if (arr[right] == search_Element) 
        { 
            position = right; 
            cout << "Elemen ditemukan dalam Array di " << position + 1 << " Posisikan dengan " << length - right << " Attempt"; 
            
            break; 
        } 
        left++; 
        right--; 
    } 
    
    if (position == -1)
    {
        cout << "Tidak ditemukan di Array dengan " << left << " Attempt"; 
    }
    
} 