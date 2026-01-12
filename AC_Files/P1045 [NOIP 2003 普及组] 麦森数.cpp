#include<bits/stdc++.h>
using namespace std;

string mul(string a, string b) {
	int len = a.size() + b.size();
	int tmp; 
	int out[len];
	fill(out, out + len, 0);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			out[i + j] += (a[i] - '0') * (b[j] - '0');
		}
	}
	for (int i = len - 1; i > 0; i--) {
		out[i - 1] += floor(out[i] / 10);
		out[i] = out[i] % 10;
	}
	if (out[len - 1] == 0) len--;
	
	stringstream ss;
	int p = 0;
	for (int i = 0; i < len; i++) {
		if (out[i] != 0 || p) {
			ss << out[i];
			p++;
		} 
	}
	return ss.str();
}

int main() {
	int p;
	cin >> p;
	
	cout << int(log10(2) * p + 1) << endl;
	string out = "1";
	string a = "2";
	while (p > 0) {
		if (p % 2 == 1) {
			out = mul(out, a);
			out = out.substr(out.size() - min(500, int(out.size())), min(500, int(out.size())));
		}
//		cout << out << endl;
		a = mul(a, a);
		a = a.substr(a.size() - min(500, int(a.size())), min(500, int(a.size())));
		p /= 2;
//		cout << out.size() << " " << p << endl;
	}
	
	out[out.size() - 1] = out[out.size() - 1] - 1;
	
	while (out.size() < 500) out = '0' + out;
	for (int i = 0; i < 500; i++) {
		cout << out[i];
		if ((i+1) % 50 == 0 && i != 0) cout << endl;
	}
	
	return 0;
}
