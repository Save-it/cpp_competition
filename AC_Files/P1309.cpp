#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
int n, r, q, k;

struct cptr {
    int x;
    int s;
    int w;
} cs[MAXN], tmp[MAXN], tmp2[MAXN];

bool cmp(cptr a, cptr b) {
    if (a.s == b.s) return a.x < b.x;
    return a.s > b.s;
}

void merge(int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int p = start;
    while (i <= mid && j <= end) {
        if (cmp(tmp2[i], tmp2[j])) {
            tmp[p] = tmp2[i];
            i++; p++;
        } else {
            tmp[p] = tmp2[j];
            j++; p++;
        }
    }
    for ( ; i <= mid; i++) {
        tmp[p] = tmp2[i];
        p++;
    }
    for ( ; j <= end; j++) {
        tmp[p] = tmp2[j];
        p++;
    }
    for (int t = start; t <= end; t++) cs[t] = tmp[t];
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

    sort(cs + 1, cs + n + 1, cmp);
    k = 1;
    for (int i = 0; i < r; i++) {
        // for (int j = 1; j <= n; j++) cout << cs[j].x << ":" << cs[j].s << " ";
        // cout << endl;
        for (int j = 1; j <= n; j += 2) {
            if (cs[j].w > cs[j + 1].w) {
                cs[j].s += 1;
                tmp2[k] = cs[j];
                tmp2[k + n / 2] = cs[j + 1];
                k++;
            }
            else {
                cs[j + 1].s += 1;
                tmp2[k] = cs[j + 1];
                tmp2[k + n / 2] = cs[j];
                k++;
            }
        }
        merge(1, n / 2, n);
        k = 1;
    }

    cout << cs[q].x;

    return 0;
}