using namespace std;
#include<iostream>

int main() {
    char s[] = "How are you?";
// Count number of words
    int i;
    for (i = 0; s[i] != '\0'; i++) {
    }
    int len = i;
    int vowels = 0;
    int consonants = 0;
    for (i = 0; i < len; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            vowels++;
        else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' & s[i] <= 'z'))
            consonants++;
    }
    cout << "Number of vowels = " << vowels << endl;
    // cout << s << endl;
    int words = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ' && s[i-1] != ' ') {
            words++;
        } 
    }
    words++;
    cout << "Number of words = " << words << endl;
    return 0;
}