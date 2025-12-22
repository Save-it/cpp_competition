#include<bits/stdc++.h> 
using namespace std;

const int MAXN = 1000001;
const int MAXM = 1000001;
int ans, in[MAXN], n, m[MAXN], re[MAXN];

int main() {
	cin >> n;
	cin >> in[1];
	m[1] = min(0, in[1]);
    re[1] = in[1];
    ans = -200000000;
	for (int i = 2; i <= n; i++) {
		cin >> in[i];
		re[i] = in[i] + re[i - 1];
		m[i] = min(m[i - 1], re[i]);
		ans = max(ans, re[i] - m[i]);
	}
	
	cout << ans;
	
	return 0;
}
