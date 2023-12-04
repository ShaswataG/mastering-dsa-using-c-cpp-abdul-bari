using namespace std;
#include<iostream>
#define SIZE 10

/*
deletion in linear Probing is not recommended, as after deleting at an index, that index remains vacant
because of this vacancy, searching for an element in the future might give result as unsuccessful search though an element is present, because once it finds the vacancy, search function will exit
so, there are two solutions for deletion in linear probing:
    rehashing: once an element is deleted, all the other keys are inserted again in the hash table, so that the vacancy is filled by the next element
    flag variable: flag variable for each index representing whether an element was deleted earlier at that index, so that searching doesn't exit unnecessarily   (doubt)
*/

int hashFunction(int x) {
    return x%SIZE;
}

int modifiedHashFunction(int x, int i) {
    return (hashFunction(x)+i)%10;
}

void insert(int HT[], int key) {
    int i = 0;
    while (HT[modifiedHashFunction(key, i)] != 0) {
        i++;
    }
    HT[modifiedHashFunction(key, i)] = key;
}

void display(int HT[]) {
    for (int i = 0; i < 10; i++) {
        cout << "HT[" << i << "] = " << HT[i] << endl;
    }
}

int main() {
    int HT[10];
    int HT[SIZE] = {0};

    int a[] = {23, 22, 41, 54, 32};
    for (int i = 0; i < 5; i++) {
        insert(HT, a[i]);
    }

    display(HT);
    return 0;
}