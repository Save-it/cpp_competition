#include<bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	
	if (a[0] == '0' || b[0] == '0') {
		cout << 0;
		return 0;
	}
	
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
	
	int p = 0;
	for (int i = 0; i < len; i++) {
		if (out[i] != 0 || p) {
			cout << out[i];
			p++;
		} 
	}
	
	return 0;
}
