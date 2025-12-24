#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
const int MAXM = 1000000;
int n, m, in[MAXN], ch[MAXN], d, s, t;

struct segmentTree {
    int l, r;
    int dat;
} T[MAXN * 4];

void build(int p, int l, int r) {
    T[p].l = l;
    T[p].r = r;
    if (l == r) {
        T[p].dat = ch[p];
        return;
    }

    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);

    T[p].dat = T[p * 2].dat + T[p * 2 + 1].dat;
}

void change(int idx, int pos, int val) {
    if (T[idx].l == T[idx].r) {
        T[idx].dat += val;
        return;
    }

    if ()
}

int main() {
    cin >> n >> m;
    cin >> in[1];
    ch[1] = in[1];
    for (int i = 2; i < n; i++) {
        cin >> in[i];
        ch[i] = in[i] - in[i - 1];
    }

    for (int i = 1; i <= m; i++) {
        cin >> d >> s >> t;
        ch[s] -= d;
        ch[t + 1] += d;
    }

    cout << 0;

    return 0;
}