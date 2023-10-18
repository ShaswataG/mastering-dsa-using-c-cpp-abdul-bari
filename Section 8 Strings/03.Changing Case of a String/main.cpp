using namespace std;
#include<iostream>

int main() {
    char s[] = "WeLcOME";
    int i;
    // from uppercase to lowercase
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
    }
    cout << "Length of s = " << i << endl;
    cout << "s in lowercase: " << s << endl;

    // toggle case
    char s1[] = "HeLlO";
    for (int i = 0; s1[i]; i++) {
        if (s1[i] >= 65 && s1[i] <= 90)
            s1[i] += 32;
        else if (s[i] >= 'a' && s[i] <= 122) 
            s1[i] -=32;
    }
    cout << "s1 after toggling cases: " << s1 << endl;
    return 0;
}