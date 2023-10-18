using namespace std;
#include<iostream>

struct Array {
    int A[10], size, length;
};

bool check_array(struct Array a) {
    for (int i = 0; i < a.length-1 ; i++) {
        if (a.A[i] > a.A[i+1])
            return false;
    }
    return true;
}

int main() {
    Array arr = {{1, 3, 5, 7, 9}, 10, 5};
    cout << check_array(arr) << endl;
    return 0;
}