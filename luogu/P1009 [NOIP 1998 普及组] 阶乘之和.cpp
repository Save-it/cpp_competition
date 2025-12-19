#include<bits/stdc++.h>
using namespace std;

string multiply(string a, string b) {	
	if (a[0] == '0' || b[0] == '0') {
		cout << 0;
		return 0;
	}
	
	stringstream ss;
	int len = a.size() + b.size();
	string tmp;
	int out[len];
	fill(out, out + len, 0);
	for (int i = a.size() - 1; i > -1; i--) {
		for (int j = b.size() - 1; j > -1; j--) {
			ss << (a[i] - '0') * (b[j] - '0');
			tmp = ss.str();
			if (tmp.size() == 1) tmp = '0' + tmp;
			ss.str("");
			for (int k = 0; k < tmp.size(); k++) {
				int t =  i + j + 1;
				out[t - k] += tmp[tmp.size() - k - 1] - '0';
				if (out[t - k] >= 10) {
					out[t - k - 1] += floor(out[t - k] / 10);
					out[t - k] = out[t - k] % 10;
				}
			}
		}
	}
	
	int p = 0;
	for (int i = 0; i < len; i++) {
		if (out[i] != 0 || p) {
			ss << out[i];
			p++;
		} 
	}
	return ss.str();
}

string add(string a, string b) {
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

int main() {
	int n;
	cin >> n;
	
	string out = "0";
	stringstream ss;
	for (int i = 1; i <= n; i++) {
		string tmp = "1";
		for (int j = 2; j <= i; j++) {
			ss << j;
			tmp = multiply(tmp, ss.str());
			ss.str("");
//			cout << tmp << endl; 
		}
		out = add(out, tmp);
	}
	
	cout << out;
	
	return 0;
}
