#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int n, ans[MAXN][MAXN], x, y;

int main() {
    cin >> n;
    x = (n + 1) / 2;
    y = 1;
    for (int i = 1; i <= n * n; i++) {
        ans[y][x] = i;
        if (y == 1 && x != n) {y = n; x++;}
        else if (y != 1 && x == n) {y--; x = 1;}
        else if (y == 1 && x == n) y++;
        else if (y != 1 && x != n) {
            if (ans[y - 1][x + 1] == 0) {y--; x++;}
            else {y++;}
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=n; j++) cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}