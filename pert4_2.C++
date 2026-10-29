#include <iostream>
using namespace std;

int main() {
    int stack[5];
    int top = -1;

    top++;
    stack[top] = 10;

    top++;
    stack[top] = 20;

    top++;
    stack[top] = 30;

    cout << "Data TOP = " << stack[top];

    return 0;
}
