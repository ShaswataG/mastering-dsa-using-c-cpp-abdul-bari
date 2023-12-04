using namespace std;
#include<iostream>
#define SIZE 10
#define R 7

int hash1(int x) {
    return x%SIZE;
}

int hash2(int x) {
    return R-(x%R);
}

int probe(int H[], int key) {
    int index = hash1(key);
    int i = 0;
    while (H[(index+i*hash2(key))%SIZE] != 0) {
        i++;
    }
    return (index+i*hash2(key))%SIZE;
}

void insert(int H[], int key) {
    int index = hash1(key);
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
    int a[] = {5, 25, 45, 15, 95};
    int HT[SIZE] = {0};
    for (int i = 0; i < 5; i++) {
        insert(HT, a[i]);
    }
    display(HT);
    return 0;
}