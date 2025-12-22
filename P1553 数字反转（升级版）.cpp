#include<bits/stdc++.h> 
using namespace std;

string z(string in) {
	string out = "";
	while (in[in.size() - 1] == '0') in.pop_back();
	for (int i = in.size() - 1; i > -1; i--) out += in[i];
	
	return out;
}

int main() {
	string ans, in;
	cin >> in;
	if (in.find(".") != string::npos) {
		string a, b;
		int p = in.find('.');
		a = in.substr(0, p);
		b = in.substr(p + 1, in.size() - 1);
		a = z(a);
		b = z(z(z(b)));
        if (a == "") a = "0";
        if (b == "") b = "0";
		ans = a + "." + b;
	} else if (in.find("/") != string::npos) {
		string a, b;
		int p = in.find('/');
		a = in.substr(0, p);
		b = in.substr(p + 1, in.size() - 1);
		a = z(a);
		b = z(b);
        if (a == "") a = "0";
		ans = a + "/" + b;
	} else if (in.find("%") != string::npos) {
		ans = z(in.substr(0, in.size() - 1)) + "%";
        if (ans == "%") ans = "0%";
	} else {
		ans = z(in);
        if (ans == "") ans = "0";
	}
	
	cout << ans;
	
	return 0;
}
