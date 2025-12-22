#include<bits/stdc++.h> 
using namespace std;

struct boat {
	int t, g = 0;
};

int n, head, tail, gj[1000000], ans;
boat bs[2000000];
vector<int> q;

int main() {
	cin >> n;
	int a = 0;
	for (int i = 0; i < n; i++) {
		int t, g, tmp;
		boat b;
		cin >> t >> g;
		b.t = t;
		b.g = g;
		for (int j = 0; j < g; j++) {
			cin >> tmp;
			q.push_back(tmp);
			gj[tmp]++;
			if (gj[tmp] == 1) ans++;
		}
		bs[i] = b;
		while (bs[i].t - 86400 >= bs[head].t) {
			for (int j = a; j < a + bs[head].g; j++) {
				if (gj[q[j]] != 0) gj[q[j]]--;
				if (gj[q[j]] == 0) ans--;
			}
			a += bs[head].g;
			head++;
		}
		cout << ans<< endl;
	}
	
	return 0;
}
