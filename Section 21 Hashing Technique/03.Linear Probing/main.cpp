using namespace std;
#include<iostream>
#define SIZE 10

int Hash(int x) {
    return x%SIZE;
}

int probe(int H[], int key) {
    int index = Hash(key);
    int i = 0;
    while (H[(index+i)%SIZE] != 0) {
        i++;
    }
    return (index+i)%SIZE;
}

void insert(int H[], int key) {
    int index = Hash(key);
    if (H[Hash(key)] != 0) {
            index = probe(H, key);
    }
    H[index] = key;
}

void display(int H[]) {
    for (int i = 0; i < SIZE; i++) {
        cout << "H[" << i << "] = " << H[i] << endl;
    }
}

int search(int H[], int key) {
    int index = Hash(key);
    if (H[index] == key) 
        return key;
    int i = 0;
    while (H[(index+i)%SIZE] != key && H[(index+i)%SIZE] != 0) {
        i++;
    }
    if (H[(index+i)%SIZE] == 0) return -1;
    else return (index+i)%SIZE;
}

int main() {

    int a[] = {23, 22, 41, 54, 32};
    int HT[SIZE] = {0};
    for (int i = 0; i < 5; i++) {
        insert(HT, a[i]);
    }

    display(HT);
    cout << search(HT, 33);
    return 0;
}