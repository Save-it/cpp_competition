#include<bits/stdc++.h> 
using namespace std;
const int MAXN = 2000;
const int MAXM = 2000;
long ans, ansx, ansy, n, m, in[MAXN][MAXM], c, re[MAXN][MAXM], tmp;

int main() {
	cin >> n >> m >> c;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			cin >> in[x][y];
			if (x != 1 && y != 1) re[x][y] = in[x][y] + re[x][y - 1] + re[x - 1][y] - re[x - 1][y - 1];
			else if (x == y == 1) re[x][y] = in[x][y];
			else if (x == 1) re[x][y] = in[x][y] + re[x][y - 1];
			else if (y == 1) re[x][y] = in[x][y] + re[x - 1][y];
			if (x >= c && y >= c) {
				tmp = re[x][y] + re[x - c][y - c] - re[x - c][y] - re[x][y - c];
				if (tmp > ans) {
					ansx = x - c + 1;
					ansy = y - c + 1;
					ans = tmp;
				}
			}
		}
	}
	
	cout << ansx << " " << ansy;
	
	return 0;
}
