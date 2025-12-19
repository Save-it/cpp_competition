#include<bits/stdc++.h>
using namespace std;
const int MAXT = 20;
const int MAXL = 200;
int t, L[MAXT], F[MAXT], E[MAXT];
string O[MAXT], tmp;
char b;
struct bi{
    char name;
    int num;
};

int findele(char a[], char ele) {
    for (char i : a) if (i == ele) return 1;
    return 0;
}

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> L[i] >> O[i];
        for (int j = 0; j < L[i]; j++) {
            getline(cin, tmp);
            if (tmp[0] == 'F') {
                F[i]++;
                tmp = tmp.substr(1, tmp.size() - 2);
                b = tmp[2];
                if(findele())
            }
            if (tmp[0] == 'E') E[i]++;

        }
    }

    return 0;
}