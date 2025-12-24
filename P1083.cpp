#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
const int MAXM = 1000000;
int n, m, in[MAXN], ch[MAXN], d, s, t;
vector<int> poss;

struct segmentTree {
    int l, r;
    int dat;
} T[MAXN * 4];

void build(int pos, int l, int r) {
    T[pos].l = l;
    T[pos].r = r;
    if (l == r) {
        T[pos].dat = ch[l];
        poss.push_back(pos);
        return;
    }

    int mid = (l + r) / 2;
    build(pos * 2, l, mid);
    build(pos * 2 + 1, mid + 1, r);

    T[pos].dat = T[pos * 2].dat + T[pos * 2 + 1].dat;
}

void change(int idx, int pos, int val) {
    if (T[idx].l == T[idx].r) {
        T[idx].dat += val;
        return;
    }

    int mid = T[idx].l + (T[idx].r - T[idx].l) / 2;
    if (pos <= mid) change(idx * 2, pos, val);
    else change(idx * 2 + 1, pos, val);
    
    T[idx].dat = T[idx * 2].dat + T[idx * 2 + 1].dat;
}

int search(int idx, int start, int end) {
    if (T[idx].l == start && T[idx].r == end) return T[idx].dat;
    if (T[idx].l > end || T[idx].r < start) return 0;

    int mid = T[idx].l + (T[idx].r - T[idx].l) /2;
    if (end <= mid) return search(idx * 2, start, end);
    if (start > mid) return search(idx * 2 + 1, start, end);

    int res = 0;
    res += search(idx*2, start, mid);
    res += search(idx*2+1, mid + 1, end);
    return res;
}

int main() {
    cin >> n >> m;
    cin >> in[1];
    ch[1] = in[1];
    for (int i = 2; i <= n; i++) {
        cin >> in[i];
        ch[i] = in[i] - in[i - 1];
    }
    build(1, 1, n);
    // cout << search(1, 1, 2);
    // for (int i = 1; i <= n * 4; i++) cout << T[i].dat << endl;

    // change(1, 1, 0 - 1);
    // change(1, 4, 1);
    // cout << search(1, 1, 1) << endl;
    // cout << search(1, 1, 2) << endl;
    // cout << search(1, 1, 3) << endl;
    for (int i = 1; i <= m; i++) {
        cin >> d >> s >> t;
        change(1, s, 0 - d);
        change(1, t + 1, d);
        int tmp = search(1, 1, s - 1);
        for (int j = s; j <= t; j++) {
            tmp += T[poss[s - 1]].dat;
            // cout << tmp << endl;
            if (tmp < 0) {
                cout << -1 << endl << i;
                return 0;
            }
        }
    }

    cout << 0;

    return 0;
}