#include<bits/stdc++.h> 
using namespace std;

const int MAXN = 100001;
const int MAXM = 100001;
int ans[MAXM], in[MAXN], n, m, re[MAXN], a, b;

int main() {
	cin >> n;
	cin >> in[1];
	re[1] = in[1];
	for (int i = 2; i <= n; i++) {
		cin >> in[i];
		re[i] += in[i] + re[i - 1];
//		cout << re[i] << endl;
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		ans[i] = re[b] - re[a - 1];
	}
	
	for (int i = 1; i <= m; i++) cout << ans[i] << endl;
	
	
	return 0;
}
