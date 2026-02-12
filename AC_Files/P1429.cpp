#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
const long long M = 2100000000;
const int t = 5;
long long n;
double ans;

struct p {
    double x;
    double y;
} r[MAXN];

bool cmpx(p a, p b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool cmpy(p a, p b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

double calcDst(p a, p b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r[i].x >> r[i].y;
    }

    ans = M;
    sort(r, r + n, cmpx);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < i + t && j < n; j++) ans = min(calcDst(r[i], r[j]), ans);
    }

    sort(r, r + n, cmpy);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < i + t && j < n; j++) ans = min(calcDst(r[i], r[j]), ans);
    }

    // cout << ans << endl;
    printf("%.4f", ans);
    return 0;
}