#include<bits/stdc++.h> 
using namespace std;
string str, ans;

string unpack(string in) {
	string out = "";
	if (in.find('[') == string::npos) return in;
	for (int i = 0; i < in.size(); i++) {
		if (in[i] == '[') {
			int p = 0;
			int t = 0;
			int j = 0;
			int k = 0;
			string tmp1 = "";
			string tmp2 = "";
			for (j = i + 1; j < in.size(); j++) {
				if (in[j] == '[') t++;
				if (in[j] == ']') p++;
				if (t == p - 1) break;
			}
			for (k = i + 1; k < j; k++) {
				if (!isdigit(in[k])) break;
			}
			tmp1 = in.substr(i + 1, k - i - 1);
			for (int q = 0; q < atoi(tmp1.c_str()); q++) {
				tmp2 += in.substr(k, j - k);
			}
			out += unpack(tmp2);
			i = j;
		} else out += in[i];
	}
	return out;
} 

int main() {
	cin >> str;
	
	ans = unpack(str);
	
	cout << ans;
	
	return 0;
}
