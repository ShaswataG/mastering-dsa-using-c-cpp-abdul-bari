using namespace std;
#include<iostream>

int main() {
    char s[10]= "John";
    int i;
    for (i = 0; s[i] != '\0'; i++)
        cout << s[i] << " ";
    cout << endl << "Length of s = " << i << endl;;
    return 0;
}