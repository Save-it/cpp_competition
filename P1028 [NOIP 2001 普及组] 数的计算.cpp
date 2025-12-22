#include<bits/stdc++.h> 
using namespace std;

int n, ans[10000];
int dfs (int now) {
	int re = 0;
	int f = 0;
	if (now == 1) return 0;
	re += floor(now / 2);
	for (int i = 1; i <= floor(now / 2); i++) {
		if (!ans[i]) re += dfs(i);
		else re += ans[i];
	}
	ans[now] = re;
	return re;
}

int main() {
	cin >> n;
	
	dfs(n);
	
	cout << ans[n] + 1;
//	for (int i = 1; i <= n; i++) cout << ans[i] << endl;
	
	return 0;
}
