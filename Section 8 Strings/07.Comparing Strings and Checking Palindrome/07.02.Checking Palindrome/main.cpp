using namespace std;
#include<iostream>

bool check_palindrome1(char* a) {
    char b[] = "\0";
    int i, j;
    for (i = 0; a[i] != '\0'; i++) {
    }
    int l = i-1;
    for (i = 0, j = l-1; i < l; i++, j--) {
        b[i] = a[j];
    }

    for (i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
        if (a[i] >= 'A' && a[i] < 'Z') {
            a[i] += 32;
        }
        if (b[i] >= 'A' && b[i] < 'Z') {
            b[i] += 32;
        }
    }
    for (i = 0, j = 0; a[i] != '\0' && b[i] != '\0'; i++, j++) {
        if (a[i] != b[j])
            break;
    }
    if (a[i] == b[j]) cout << "Yes, its a palindrome" << endl;
    else cout << "No, its not a palindrome." << endl;
}

bool check_palindrome2(char* a) {
    int i;
    for (i = 0; a[i] != '\0'; i++) {        
    }
    int l = i;
    for (int i = 0; i < l; i++) {
        if (a[i] != a[l-1-i]) return false; 
    }
    return true;
}

int main() {
    char a[] = "madam";
    // check_palindrome1(a);
    cout << check_palindrome2(a);
    cout << endl;
    char b[] = "thgj";
    // check_palindrome1(b);
    cout << check_palindrome2(b);
    return 0;
}