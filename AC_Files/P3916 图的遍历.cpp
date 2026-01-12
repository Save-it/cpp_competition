#include<bits/stdc++.h> 
using namespace std;

const int MAXN = 1000000;
const int MAXM = 1000000;
int n, m, num, head[MAXN], u, v, ans[MAXN], vd[MAXM], bk[MAXN];

struct edge {
	int next;
	int to;
} edge[MAXM];

void add(int from, int to) {
	num++;
	edge[num].next = head[from];
	edge[num].to = to;
	head[from] = num;
}

void dfs(int i, int now) {
	now = max(now, ans[i]);
	ans[i] = now;
	for (int j = head[i]; j != 0; j = edge[j].next) {
		if (vd[j] != 2) {
			vd[j]++;
			dfs(edge[j].to, now);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) ans[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		add(v, u);
	}
	
	for (int i = n; i >= 1; i--) {
		dfs(i, i);
//		fill(vd, vd + MAXM, 0);
	}
	
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	
	return 0;
}

