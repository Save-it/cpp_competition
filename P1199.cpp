#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n, w[MAXN][MAXN], p, c, vd[MAXN], ans, tmpp;
vector<int> ps, cs;

void game(int now, int k) {
    int tmp = 0;
    tmpp = 0;
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
        for (int i = 0; i < n / 2; i++) for (int j = i + 1; j < n / 2; j++) p = max(p, w[ps[i]][ps[j]]);
        for (int i = 0; i < n / 2; i++) for (int j = i + 1; j < n / 2; j++) c = max(c, w[cs[i]][cs[j]]);
        cout << p << "  " << c << endl;
        if (p > c) ans = max(ans, p);
        p = 0;
        c = 0;
        return;
    }
    for (int i = 1; i <= n; i++) if (vd[i] == 0) {
        ps.push_back(i);
        vd[i]++;
        game(i, k + 1);
        vd[i]--;
        vd[tmpp]--;
        ps.pop_back();
        cs.pop_back();
    }
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
        ps.push_back(i);
        vd[i]++;
        game(i, 1);
        p = 0;
        c = 0;
        fill(vd, vd + MAXN, 0);
        ps.clear();
        cs.clear();
    }

    if (ans) cout << 1 << endl << ans;
    else cout << 0;

    return 0;
}