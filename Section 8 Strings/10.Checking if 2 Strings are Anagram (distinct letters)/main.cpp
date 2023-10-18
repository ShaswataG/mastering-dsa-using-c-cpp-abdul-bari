using namespace std;
#include<iostream>

// doubt- not working in all scenarios for a = "decimal", b = "medial"
// check "D:\Coding\GFG Practice\Problems\Strings\Anagram\main.cpp", works for all cases

bool checkAnagram(string a, string b) {
// TC = O(n)
   int H[26] = {0};
   int i;
    for (i = 0; a[i] != '\0'; i++) {
        H[a[i]-97]++;
    }
    for (i = 0; b[i] != '\0'; i++) {
        H[b[i]-97]--;
        if (H[i] < 0) {
            return false;
        }
    }
    if (b[i] == '\0') return true;
}

int main() {
    string a = "decimal", b = "medial";
    cout << checkAnagram(a, b) << endl;
    return 0;
}