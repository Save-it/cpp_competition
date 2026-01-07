#include<bits/stdc++.h> 
using namespace std;
int n, m, k, ans[3];
string tmp, in[4];

int main() {
	cin >> n >> m >> k;
	
	for (int i = 0; i < n / 4; i++) {
		for (int p = 0; p < 4; p++) {
			for (int j = 0; j < m - 1; j++) cin >> tmp;
			cin >> in[p];
		}
		if (in[0].size() >= k && in[1].size() >= k && in[2].size() >= k && in[3].size() >= k) {
			for (int j = 0; j < 4; j++) in[j] = in[j].substr(in[j].size() - k, k);
			if (in[0] == in[1] && in[2] == in[3]) ans[0]++;
			if (in[0] == in[2] && in[1] == in[3]) ans[1]++;
			if (in[1] == in[2] && in[0] == in[3]) ans[2]++;
		}
	}
	
	printf("%d %d %d", ans[0], ans[1], ans[2]);
	
	return 0;
}


