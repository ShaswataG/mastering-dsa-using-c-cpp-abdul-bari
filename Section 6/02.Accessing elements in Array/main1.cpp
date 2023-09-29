using namespace std;
#include<iostream>

int main() {
    int a[5] = {1, 2, 3, 4 ,5};
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << i[a] << " ";
    }
    cout << endl; 

    // using pointer arithmetic
    for (int i = 0; i < 5; i++) {
        cout << *(a+i) << " ";
    }
    cout << endl;
    return 0;
}