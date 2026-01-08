#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n, w[MAXN][MAXN], vd[MAXN], ans;

void game(int now, int k, vector<int> ps, vector<int> cs) {
    int tmp = 0;
    int tmpp = 0;
    for (int j : ps) for (int q = 1; q <= n; q++) {
        if (vd[q] == 0 && w[j][q] > tmp) {
            tmp = w[j][q];
            tmpp = q;
        }
    }
    cs.push_back(tmpp);
    vd[tmpp]++;
    k++;
    if (k == n) {
        int p = 0;
        int c = 0;
        for (int i : ps) for (int j : ps) p = max(p, w[i][j]);
        for (int i : cs) for (int j : cs) c = max(c, w[i][j]);
        // for (int i = 0; i < n / 2; i++) cout << ps[i] << " " << cs[i] << endl;
        // cout << p << "  " << c << endl;
        if (p > c) ans = max(ans, p);
        return;
    }
    for (int i = 1; i <= n; i++) if (vd[i] == 0) {
        ps.push_back(i);
        vd[i]++;
        game(i, k + 1, ps, cs);
        vd[i]--;
    }
    vd[tmpp]--;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> w[i][j];
            w[j][i] = w[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        vector<int> ps;
        vector<int> cs;
        ps.push_back(i);
        vd[i]++;
        game(i, 1, ps, cs);
        vd[i]--;
        fill(vd, vd + MAXN, 0);
    }

    if (ans) cout << 1 << endl << ans;
    else cout << 0;

    return 0;
}