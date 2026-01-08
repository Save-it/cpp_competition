#include<bits/stdc++.h> 
using namespace std;
long long n, ans, vd[100000];

int dfs(int now) {
	if (now <= 0) {
		if (now == 0) return 1;
		return 0;
	}
	if (vd[now] == 0) {
		for (int i = 1; i <= 3; i++) {
			vd[now] += dfs(now - i);
		}
	}
	return vd[now];
}


int main() {
	cin >> n;
	
	ans = dfs(n);
	
	cout << vd[n];
	
	return 0;
}
