#include<bits/stdc++.h> 
using namespace std;
const int MAXN = 10000;
int n, k, T, ans;
double in1[MAXN][2], in2[MAXN][2], x, y, tmp, len;

int main() {
	cin >> n >> k >> T;
	
	for (int i = 0; i < n; i++) cin >> in1[i][0] >> in1[i][1];
	for (int i = 0; i < k; i++) cin >> in2[i][0] >> in2[i][1];
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		int p = 0;
		len = 0;
		for (int j = 0; j < n; j++) {
			tmp = sqrt(pow(in1[j][0] - x, 2) + pow(in1[j][1] - y, 2));
			if (tmp > len) {
				len = tmp;
				p = j;
			} else if (tmp == len) p = min(p, j);
		}
		for (int j = 0; j < k; j++) {
			if (in1[p][0] == in2[j][0] && in1[p][1] == in2[j][1]) {
				ans++;
				break;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}


