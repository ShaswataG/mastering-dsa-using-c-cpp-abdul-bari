using namespace std;
#include<iostream>
#define SIZE 10

int Hash(int x) {
    return (x%SIZE);
}

int probe(int H[], int key) {
    int index = Hash(key);
    int i = 0;
    while (H[(index+i*i)%SIZE] != 0) 
    {
        i++;
    }
    return (index+i)%SIZE;
}

void insert(int H[], int key) {
    int index = Hash(key);
    if (H[index] != 0) {
        index = probe(H, key);
    }
    H[index] = key;
}

void display(int H[]) {
    for (int i = 0; i < SIZE; i++) {
        cout << "H[" << i << "] = " << H[i] << endl;
    }
}

int main() {
    int a[] = {23, 42, 53, 13, 11};
    int HT[SIZE] = {0};
    for (int i = 0; i < 5; i++) {
        insert(HT, a[i]);
    }
    return 0;
}