#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
int n, r, q;

struct cptr {
    int x;
    int s;
    int w;
} cs[MAXN], tmp[MAXN];

bool cmp(cptr a, cptr b) {
    if (a.s == b.s) return a.x < b.x;
    return a.s > b.s;
}

void merge(int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int p = start;
    while (i <= mid && j <= end) {
        if (cmp(cs[i], cs[j])) {
            tmp[p] = cs[i];
            i++; p++;
        } else {
            tmp[p] = cs[j];
            j++; p++;
        }
    }
    for ( ; i <= mid; i++) {
        tmp[p] = cs[i];
        p++;
    }
    for ( ; j <= end; j++) {
        tmp[p] = cs[j];
        p++;
    }
    for (int k = start; k <= end; k++) cs[k] = tmp[k];
}

void mergesort(int start, int end) {
    // cout << start << " : " << end << endl;
    if (start == end) return;

    int mid = start + (end - start) / 2;
    mergesort(start, mid);
    mergesort(mid + 1, end);

    merge(start, mid, end);
}

int main() {
    cin >> n >> r >> q;
    n = n * 2;
    for (int i = 1; i <= n; i++) {
        cs[i].x = i;
        cin >> cs[i].s;
    }
    for (int i = 1; i <= n; i++) cin >> cs[i].w;

    mergesort(1, n);
    for (int i = 0; i < r; i++) {
        // for (int j = 1; j <= n; j++) cout << cs[j].x << ":" << cs[j].s << " ";
        // cout << endl;
        for (int j = 1; j <= n; j += 2) {
            if (cs[j].w > cs[j + 1].w) cs[j].s += 1;
            else cs[j + 1].s += 1;
        }
        mergesort(1, n);
    }

    cout << cs[q].x;

    return 0;
}