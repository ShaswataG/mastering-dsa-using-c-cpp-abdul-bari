using namespace std;
#include<iostream>

string compare1(char* a, char* b) {
    for (int i = 0; a[i] != '\0' && b[i] != '\0'; i++) {    // doubt- are both i and j required, isn't i alone enough for iterrating over both strings a and b
        if (a[i] < b[i]) return b;
        else if (a[i] > b[i]) return a;
    }
    return "Equal";
}

void compare2(char* a, char* b) {
    int i, j;
    for (i = 0, j = 0; a[i] != '\0' && b[i] != '\0'; i++, j++) {
        if (a[i] != b[j])
            break;
    }
    if (a[i] == b[j]) cout << "Equal" << endl;
    else if (a[i] < b[j]) cout << "Smaller" << endl;
    else cout << "Greater" << endl;
}

void compare3(char* a, char* b) {
    int i, j;
    for (i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            a[i] += 32;
        }
        if (b[i] >= 'A' && b[i] <= 'Z') {
            b[i] += 32;
        }
    }
    for (i = 0, j = 0; a[i] != '\0' && b[i] != '\0'; i++, j++) {
        if (a[i] != b[j])
            break;
    }
    if (a[i] == b[j]) cout << "Equal" << endl;
    else if (a[i] < b[j]) cout << "Smaller" << endl;
    else if (a[i] > b[j]) cout << "Greater" << endl;
}
int main() {
    char x[] = "Painter";
    char y[] = "pa0nter";
    compare3(x, y);
    compare2(x, y);
    return 0;
}