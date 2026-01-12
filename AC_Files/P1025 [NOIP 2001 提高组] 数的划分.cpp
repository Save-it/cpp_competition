#include<bits/stdc++.h> 
using namespace std;
int n, ans, k, tmp, vd[500][500][500];
vector<int> tmp2;

int dfs(int now, int c) {
	if (c == k) {
		if (tmp == n) return 1;
		return 0;
	}
	int p = tmp;
	if (vd[now][p][c] == 0) {
		for (int i = now; i <= (n - tmp) / (k - c); i++) {
			tmp += i;
			vd[now][p][c] += dfs(i, c + 1);
			tmp -= i;
		}
	}
	return vd[now][p][c];
}

int main() {
	cin >> n >> k;
	
	for (int i = 1; i <= ceil(n / k); i++) {
		tmp += i;
		ans += dfs(i, 1);
		tmp = 0;
	}
	
	cout << ans;
	
	return 0;
}
