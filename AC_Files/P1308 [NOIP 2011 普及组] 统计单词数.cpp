#include<bits/stdc++.h> 
using namespace std;

long long ans;
string f1, f2, str;
int main() {
	getline(cin, f1);
	getline(cin, str);
	
	for (int i = 0; i < f1.size(); i++) f2 += tolower(f1[i]);
	int p = -1;
	for (int i = 0; i < str.size(); i++) {
		string tmp = "";
		for (int j = i; j < i + f2.size(); j++) tmp += tolower(str[j]);
		if (tmp == f2 && (i == 0 || str[i - 1] == ' ') && (str[i + f2.size()] == ' ' || i + f2.size() == str.size())) {
			ans++;
			if (p == -1) p = i;
		}
	}
	
	if (ans != 0) cout << ans << " "; 
	cout << p;
	
	return 0;
}
