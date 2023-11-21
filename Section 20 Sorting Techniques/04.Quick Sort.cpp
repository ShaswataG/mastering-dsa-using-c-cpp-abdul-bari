using namespace std;
#include<iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// int partition(int a[], int l, int h) {
//     int pivot = a[l];
//     int i = l, j = h;

//     while (i <= j) {
//         if (a[i] <= pivot) i++;
//         if (a[j] > pivot) j--;
//         if (a[i] > pivot && a[j] < pivot) {
//             swap(a[i], a[j]);
//         }
//     }
//     swap(pivot, a[j]);
// }

int main() {
    return 0;
}