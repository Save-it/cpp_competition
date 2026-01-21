#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
const long long MAXNUM = 1000000000;
long long n, m, tmp;
bool vd[MAXNUM];

struct num{
    long long v;
    long long x;
} in[MAXN];

bool cmp(num a, num b) {
    if (a.v == b.v) return a.x < b.x;
    return a.v < b.v;
}

int binary_search(int v, int l, int r) {
	while (l <= r) {
		int mid = (l + r) / 2;
		if (in[mid].v == v){
			return in[mid].x;
		} 
		if (in[mid].v > v){
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return -1;
} 

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (vd[tmp] == false) {
            in[i].v = tmp;
            vd[tmp] = true;
        } else in[i].v = -1;
        in[i].x = i + 1;
    }

    sort(in, in + n, cmp);
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        printf("%d ", binary_search(tmp, 0, n - 1));
    }

    return 0;
}