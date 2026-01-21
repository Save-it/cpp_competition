#include<bits/stdc++.h> 
using namespace std;
long long n;
string ans, vd[1000000];

string pl(string a, string b) {
	int len = max(a.size(), b.size());
	while(a.size() < len) a = '0' + a;
	while(b.size() < len) b = '0' + b;
	
	int j = 0;
	string out = "";
	int tmp = 0;
	for (int i = len - 1; i > -1; i--) {
		tmp = a[i] - '0' + b[i] - '0' + j;
		if (tmp >= 10) {
			tmp -= 10;
			j = 1;
			if (tmp == 0) out = '0' + out;
			if (tmp > 0) out = char(tmp + '0') + out; 
		} else {
			j = 0;
			out = char(tmp + '0') + out;
		}
	}
	if (j == 1) out = '1' + out;
	
	return out;
}

string dfs(int now) {
	if (now <= 0) {
		if (now == 0) return "1";
		return "0";
	}
	if (vd[now] == "") {
		for (int i = 1; i <= 3; i++) {
			vd[now] = pl(vd[now], dfs(now - i));
		}
	}
	return vd[now];
}


int main() {
	cin >> n;
	
	ans = dfs(n);
	
	cout << ans;
	
	return 0;
}


