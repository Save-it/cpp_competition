#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
string pwd, org, in;
char tab[MAXN];
int f;

int main () {
    cin >> pwd >> org >> in;
    fill(tab, tab + MAXN, 0);
    for (int i = 0; i < int(pwd.size()); i++) {
        char x = pwd[i];
        char y = org[i];
        if (tab[int(x)] == 0) {
            tab[int(x)] = y; 
            f++;
        }
        else if (tab[int(x)] != y) {
            cout << "Failed";
            return 0;
        }
    }
    if (f != 26) {
        cout << "Failed";
        return 0;
    }

    for (int i = 0; i < int(in.size()); i++) {
        cout << tab[int(in[i])];
    }

    return 0;
}