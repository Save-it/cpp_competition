#include<bits/stdc++.h> 
using namespace std;

struct rock {
	int f;
	int p;
};

int l, n, m;
int main() {
	cin >> l >> n >> m;
	int tmp[n];
	rock rs[n + 2];
	rs[0].p = 0; rs[0].f = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp[i];
		rs[i + 1].p = i + 1;
		if (i == 0) {
			rs[i + 1].f = tmp[i];
			continue;
		}
		rs[i + 1].f = tmp[i] - tmp[i - 1];
	}
	rs[n + 1].p = n + 1; rs[n + 1].f = l - tmp[n - 1];
	
	for (rock r : rs) cout << r.p << " " << r.f << endl;
	
	
	return 0;
}
