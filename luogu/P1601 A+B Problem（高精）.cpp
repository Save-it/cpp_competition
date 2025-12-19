#include<bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	
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
	
	cout << out;
	
	return 0;
}
