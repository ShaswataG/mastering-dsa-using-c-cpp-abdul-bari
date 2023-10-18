using namespace std;
#include<iostream>

int len(char* name) {
    int i;
    for (i = 0; name[i] != '\0'; i++) {
    }
    return i;
}

void swap(char& c1, char& c2) {
    char temp = c1;
    c1 = c2;
    c2 = temp;
}

string Reverse1(char* name) {
    int l = len(name);
    for (int i = 0; i < l/2; i++) {
        swap(name[i], name[l-1-i]);
    }
    return name;
}

string Reverse2(char* name) {
    int l = len(name);
    string rev_string;
    for (int i = 0, j = l-1; i < l; i++, j--) {
        rev_string[i] = name[j];
    }
    for (int i = 0; i < l; i++) {
        name[i] = rev_string[i];
    }
    return name;
}

int main() {
    char name1[] = "This is Great";
    cout << "Before swapping, name = " << name1 << endl;
    Reverse1(name1);
    cout << "After swapping, name = " << name1 << endl;

    char name2[] = "This is Great";
    cout << "Before swapping, name = " << name2 << endl;
    Reverse2(name2);
    cout << "After swapping, name = " << name2 << endl;
    return 0;
}