#include<bits/stdc++.h> 
using namespace std;

string in[100], st, str;
int s[100], n, p, ans;


struct s {
	string str;
	int len;
};

void jie(string lo) {
	if (lo == "") return;
	char now;
	string tmp1, tmp2, tmp3, f;
	int len;
	vector<string> out;
	for (int i = lo.size() - 1; i > -1; i--) {
		now = lo[i];
		for (int k = 0; k < n; k++) {
			f = in[k];
			if (f.find(now) != string::npos && s[k] != 2) {
				tmp1 = lo.substr(i, lo.size() - i);
				tmp2 = f.substr(0, f.find(now) + tmp1.size());
//				cout << tmp1 << " " << tmp2 << endl;
				if (tmp1 == tmp2 && (tmp1 != lo || tmp1 == st) && tmp2 != in[k]) {
					tmp3 = f.substr(f.find(now) + tmp1.size(), f.size() - f.find(now));
					str += tmp3;
					s[k]++;
//					cout << str << endl;
					ans = max(ans, int(str.size()));
					jie(str);
					for (int p = 0; p < tmp3.size(); p++) str.pop_back();
					s[k]--;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> in[i];
	cin >> st;
	str += st;
	jie(str);
	
	cout << ans;
	
	return 0;
}
