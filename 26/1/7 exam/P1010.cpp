#include<bits/stdc++.h> 
using namespace std;
int n;

void dfs(int now) {
	if (now == 0) return;
	int tmp1 = 0;
	vector<int> tmp2;
	while (now != 1) {
		if (now % 2 == 1) {
			now -= 1;
			tmp2.push_back(tmp1);
		}
		else {
			now /= 2;
			tmp1++;
		}
	}
	tmp2.push_back(tmp1);
	for (int i = tmp2.size() - 1; i > -1; i--) {
		if (i != tmp2.size() - 1) cout << "+";
		if (tmp2[i] != 1 && tmp2[i] != 0) {
			cout << "2(";
			dfs(tmp2[i]);
			cout << ")";
		} else {
			if (tmp2[i] == 1) cout << "2";
			else cout << "2(0)";
		}
	}
}

int main() {
	cin >> n;
	
	dfs(n);
	
	return 0;
}


