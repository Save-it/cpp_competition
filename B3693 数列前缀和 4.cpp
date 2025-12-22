#include<bits/stdc++.h> 
using namespace std;
const int MAXN = 1001;
const int MAXM = 1001;
const long long a = pow(2, 64);
long long q, n, m, c, u, v, xa, ya, ans;
long long in[MAXN][MAXM], re[MAXN][MAXM];

int main() {
	cin >> q;
	for (int i = 0; i < q; i++) {
		ans = 0;
		cin >> n >> m >> c;
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= m; y++) {
				cin >> in[x][y];
				if (x != 1 && y != 1) re[x][y] = in[x][y] + re[x][y - 1] + re[x - 1][y] - re[x - 1][y - 1];
				else if (x == y == 1) re[x][y] = in[x][y];
				else if (x == 1) re[x][y] = in[x][y] + re[x][y - 1];
				else if (y == 1) re[x][y] = in[x][y] + re[x - 1][y];
				}
			}
		for (int j = 0; j < c; j++) {
			cin >> u >> v >> xa >> ya;
//			cout << ((re[x][y] + re[u - 1][v - 1] - re[x][v - 1] - re[u - 1][y]) % a) << endl;
			ans = ans ^ ((re[xa][ya] + re[u - 1][v - 1] - re[xa][v - 1] - re[u - 1][ya]) % a);
		}
		cout << ans << endl;
	}
	
	return 0;
}
