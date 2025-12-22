#include<bits/stdc++.h> 
using namespace std;

int n, m;
int tmp[100];
int used[100];
int k;
int g;
void dfs(int x, int s, int y, int z, int* l) {
	if (x == z + 1) {
		int tmp1 = 0;
		for (int i = 1; i <= z; i++) tmp1 += tmp[i];
		int p = 0;
		for (int j = 2; j * j <= tmp1; j++) {
			if (tmp1 % j == 0 || tmp1 == 1) {
				p++;
				j += tmp1;
			}
		}
		if (p == 0) {
			g++;
		}
		k++;
		return;
	}
	for (int i = s; i <= y; i++) {
		if(!used[i]) {
			tmp[x] = l[i - 1];
			used[i] = 1;
			dfs(x + 1, i, y, z, l);
			tmp[x] = 0;
			used[i] = 0;
		}
	}	
} 

int main() {
	cin >> n >> m;
	int l[n];
	for (int i = 0; i < n; i++) cin >> l[i];
	sort(l, l + n);

	dfs(1, 1, n, m, l);
	
	cout << g;
	
	return 0;
}
