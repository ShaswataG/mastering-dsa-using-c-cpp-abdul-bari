using namespace std;
#include<iostream>

void find_duplicates1(char* s) {
// Compare with other letters
// TC = O(n^2)
    int cnt;
    for (int i = 0; s[i] != '\0'; i++) {
        cnt = 1;
        if (s[i] != '0') {
            for (int j = i+1; s[j] != '\0'; j++) {
               if (s[i] == s[j]) {
                  cnt++;
                  s[j] = '0';
                }
            }
            if (cnt > 1)
                cout << s[i] << " occurs " << cnt << " times." << endl;
        }
    }
}

void find_duplicates2(char* s) {
/*
Using hash table and counting
f(n) = n + n = 2n ~ n
TC = O(n)
*/
    int H[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        H[s[i]-97]++;
    }
    for (int i = 0; i < 26; i++) {
        if (H[i] > 1) {
            char c = i+97;
            cout << c << " occurs " << H[i] << " times." << endl;
        }
    }
}

int main() {
    char a[] = "hsdhshkkl";
    find_duplicates2(a);
    cout << endl;
    find_duplicates1(a);
    return 0;
}