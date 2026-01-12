#include<bits/stdc++.h> 
using namespace std;

int n, m;
int tmp[10000];
vector<int> dfs_out;
int used[10000];
int k;
void dfs(int x, int y, int z) {
	if (x == z + 1) {
		int tmp1 = 0;
		for (int j = z - 1; j > -1; j--) tmp1 += tmp[j + 1] * ceil(pow(10, n - j - 1));
		dfs_out.push_back(tmp1);
		k++;
		return;
	}
	for (int i = 1; i <= y; i++) {
		if(!used[i]) {
			tmp[x] = i;
			used[i] = 1;
			dfs(x + 1, y, z);
			tmp[x] = 0;
			used[i] = 0;
		}
	}
} 

int main() {
	cin >> n >> m;
	int tmp1;
	int in = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp1;
		tmp1 *= ceil(pow(10, n - 1 - i));
		in += tmp1;
	}
	
	dfs(1, n, n);
	cout << "dfs" << endl;
	sort(dfs_out.begin(), dfs_out.end());
	cout << "sort" << endl;
	
	for (int i = 0; i < k; i++) {
		if (dfs_out[i] == in) {
			stringstream ss;
			ss << dfs_out[i + m];
			for (int j = 0; j < n; j++) cout << ss.str()[j] << " ";
			cout << endl;
			i += k;
		}
	}
	
	return 0;
}
