using namespace std;
#include<iostream>

int main() {
    int a[] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    int l = a[0], h = a[10], n = 11;
    int diff = l - 0;
    for (int i = 0; i < 11; i++) {
        if (a[i]-diff) {
            while(diff < (a[i]-i)) {
                cout << i+diff << " ";
                diff++;
            }
        }
    }
    return 0;
}