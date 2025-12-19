#include <bits/stdc++.h>
using namespace std;

string dfs_out[10000];
int used[10000];
string tmp;
int k;
void dfs(int x, int n, int m) {
	if (x == m + 1) {
		dfs_out[k] = tmp;
		k++;
		return;
	}
	for (int i = 1; i < n + 1; i++) {
		if (!used[i]) {
			tmp += to_string(i);
			used[i] = 1;
			dfs(x + 1, n, m);
			for (int j = 0; j < to_string(i).size(); j++) tmp.pop_back();
			used[i] = 0;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	string in;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		in += to_string(a);
	}
	
    dfs(1, n, n);
    
    int l[k];
    for (int i = 0; i < k; i++) {
    	l[i] = atoi(dfs_out[i].c_str());
	}
	sort(l, l + k);
	int inl;
	for (int i = 0; i < k; i++) {
		if (l[i] == atoi(in.c_str())) {
			inl = i;
			i += k;
		}
	}
	string out = to_string(l[inl + m]);
	for (int i = 0; i < n; i++) cout << out[i] << " ";
    
    return 0;
}
