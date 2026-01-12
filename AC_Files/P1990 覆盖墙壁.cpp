#include<bits/stdc++.h> 
using namespace std;
const int MAXN = 10000000;
int ans, n, wa[2][MAXN], vd[3][MAXN];

int dfs(int i, int s) {
	if (i >= n) {
		if (wa[0][n - 1] != 0 && wa[1][n - 1] != 0 && wa[0][n] == 0 && wa[1][n] == 0) return 1;
		return 0;
	}
	int tmp = 0;
	if (wa[0][i] != 0) tmp++;
	if (wa[1][i] != 0) tmp++;
	if (vd[tmp][i] == 0) {
		if (wa[0][i] == 0 && wa[1][i] == 0) {
			wa[0][i] = s;
			wa[1][i] = s;
			vd[tmp][i] += dfs(i + 1, s + 1);
			wa[0][i] = 0;
			wa[1][i] = 0;
		}
		if (wa[0][i] == 0 && wa[0][i + 1] == 0 && wa[1][i] == 0 && wa[1][i + 1] == 0 && i <= n - 2){
			wa[0][i] = s;
			wa[0][i + 1] = s;
			wa[1][i] = s + 1;
			wa[1][i + 1] = s + 1;
			vd[tmp][i] += dfs(i + 2, s + 2);
			wa[0][i] = 0;
			wa[0][i + 1] = 0;
			wa[1][i] = 0;
			wa[1][i + 1] = 0;
		} else if (wa[0][i] == 0 && wa[0][i + 1] == 0 && i <= n - 2) {
			wa[0][i] = s;
			wa[0][i + 1] = s;
			if (wa[1][i] != 0 && wa[1][i + 1] != 0) vd[tmp][i] += dfs(i + 2, s + 1);
			else if (wa[1][i] != 0 && wa[1][i + 1] == 0) vd[tmp][i] += dfs(i + 1, s + 1);
			else vd[tmp][i] += dfs(i, s + 1);
			wa[0][i] = 0;
			wa[0][i + 1] = 0;
		} else if (wa[1][i] == 0 && wa[1][i + 1] == 0 && i <= n - 2) {
			wa[1][i] = s;
			wa[1][i + 1] = s;
			if (wa[0][i] != 0 && wa[0][i + 1] != 0) vd[tmp][i] += dfs(i + 2, s + 1);
			else if (wa[0][i] != 0 && wa[0][i + 1] == 0) vd[tmp][i] += dfs(i + 1, s + 1);
			else vd[tmp][i] += dfs(i, s + 1);
			wa[1][i] = 0;
			wa[1][i + 1] = 0;
		}
		if (wa[0][i] == 0 && wa[1][i] == 0 && wa[0][i + 1] == 0 && i <= n - 2) {
			wa[0][i] = s;
			wa[1][i] = s;
			wa[0][i + 1] = s;
			vd[tmp][i] += dfs(i + 1, s + 1);
			wa[0][i] = 0;
			wa[1][i] = 0;
			wa[0][i + 1] = 0;
		}
		if (wa[0][i] == 0 && wa[1][i] == 0 && wa[1][i + 1] == 0 && i <= n - 2) {
			wa[0][i] = s;
			wa[1][i] = s;
			wa[1][i + 1] = s;
			vd[tmp][i] += dfs(i + 1, s + 1);
			wa[0][i] = 0;
			wa[1][i] = 0;
			wa[1][i + 1] = 0;
		}
		if (wa[0][i] == 0 && wa[0][i + 1] == 0 && wa[1][i + 1] == 0 && wa[1][i] != 0 && i <= n - 2) {
			wa[0][i] = s;
			wa[0][i + 1] = s;
			wa[1][i + 1] = s;
			vd[tmp][i] += dfs(i + 2, s + 1);
			wa[0][i] = 0;
			wa[0][i + 1] = 0;
			wa[1][i + 1] = 0;
		}
		if (wa[1][i] == 0 && wa[0][i + 1] == 0 && wa[1][i + 1] == 0 && wa[0][i] != 0 && i <= n - 2) {
			wa[1][i] = s;
			wa[0][i + 1] = s;
			wa[1][i + 1] = s;
			vd[tmp][i] += dfs(i + 2, s + 1);
			wa[1][i] = 0;
			wa[0][i + 1] = 0;
			wa[1][i + 1] = 0;
		}
	}
	if (vd[tmp][i] >= 10000) vd[tmp][i] %= 10000;
	return vd[tmp][i];
}

int main() {
	cin >> n;
	
	ans = dfs(0, 1);
	
	cout << ans % 10000;
	
	return 0;
}
