using namespace std;
#include<iostream>

struct Array {
    int A[20], size, length;
};

int Get(struct Array a, int index) {
// TC = O(1)
    if (index >= 0 && index < a.length) {
        return a.A[index];
    }
    return -1;
}
void Set(struct Array* a, int index, int x) {
// TC = O(1)
    if (index >= 0 && index <a->length) {
        a->A[index] = x;
    }
}
int Max(struct Array a) {
// TC = O(n)
    int max = a.A[0];
    for (int i = 1; i < a.length; i++) {
        if (max < a.A[i])
            max = a.A[i];
    }
    return max;
}

int Min(struct Array a) {
// TC = O(n)
    int min = a.A[0];
    for (int i = 1; i < a.length; i++) {
        if (min > a.A[i])
            min = a.A[i];
    }
    return min;
}

int Sum(struct Array a) {
// TC = O(n)
    int total = 0;
    for (int i = 0; i < a.length; i++) {
        total += a.A[i];
    }
    return total;
}

int RSum(struct Array a, int n) {
// TC = O(n)
// SC = O(n)
    if (n < 0)
        return 0;
    else {
        return RSum(a, n - 1) + a.A[n];
    }
}

float Avg(struct Array a) {
// TC = O(n)
    int total = 0;
    for (int i = 0; i < a.length; i++) {
        total += a.A[i];
    }
    return (float) total/a.length;
}

int main() {
    Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    cout << Get(arr, 2) << endl;
    Set(&arr, 1, 99);
    cout << Max(arr) << endl;
    cout << Avg(arr) << endl;
    return 0;
}