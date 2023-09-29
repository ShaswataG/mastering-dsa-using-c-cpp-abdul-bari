using namespace std;
#include<iostream>

int main() {
    int* p = new int[5];
    int a = 3;
    for (int i = 0; i < 5; i++) {
        *(p+i) = a;
        a += 2;
    }
    int* q = new int[10];
    for (int i = 0; i < 5; i++) {
        q[i] = *(p+i);
    }
    delete [] p;
    p = q;
    q = nullptr;
    return 0;
}