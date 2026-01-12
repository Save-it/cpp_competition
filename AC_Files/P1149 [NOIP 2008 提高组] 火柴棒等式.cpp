#include<bits/stdc++.h> 
using namespace std;

int a, b, c;
vector<vector<int>> ans;
struct combination{
	int g;
	vector<int> l;
};

const int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; 
vector<combination> cs;
int k;
vector<int> tmp1;
void comb1(int n) {
	if (n == 0) {
			combination tmp;
			for (int j = 0; j < tmp1.size(); j++) tmp.l.push_back(tmp1[j]);
			tmp.g = tmp1.size();
			cs.push_back(tmp);
			k++;
			return;
		}
	for (int i = 0; i < 10; i++) {
		if (n >= num[i] && n != 0) {
			tmp1.push_back(i);
			comb1(n - num[i]);
			tmp1.pop_back();
		} else {continue;}
	}
	return;
}

vector<int> tmp;
vector<vector<int>> dfs_out;
int used[10000];
void dfs(int x, int s, int y, int z) {
	if (x == z + 1) {
		dfs_out.push_back(tmp);
		return;
	}
	for (int i = s; i <= y; i++) {
		if(!used[i]) {
			tmp.push_back(i);
			used[i] = 1;
			dfs(x + 1, i, y, z);
			tmp.pop_back();
			used[i] = 0;
		}
	}
} 

void jud(int a, int b, int c) {
	vector<int> res = {a, b, c};
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i][0] == a && ans[i][1] == b && ans[i][2] == c) return;
	}
//	cout << a << "+" << b << "=" << c << endl;
	ans.push_back(res);
}

int main() {
	int n;
	cin >> n;
	n -= 4;
	comb1(n);
	
	for (int i = 0; i < k; i++) {
//		for (int j = 0; j < cs[i].g; j++) cout << cs[i].l[j] << " ";
//		cout << endl;
		dfs(1, 1, cs[i].g - 1, 2);
//		cout << "    ";
		for (int j = 0; j < dfs_out.size(); j++) {
			a = b = c = 0;
			int p1 = dfs_out[j][0];
			int p2 = dfs_out[j][1];
//			cout << p1 << " " << p2 << "   ";
			string ast, bst, cst = "";
			for (int t = 0; t < p1; t++) ast += char(cs[i].l[t] + '0');
			for (int t = p1; t < p2; t++) bst += char(cs[i].l[t] + '0');
			for (int t = p2; t < cs[i].g; t++) cst += char(cs[i].l[t] + '0');
//			cout << ast << "  " << bst << "  " << cst << "  /  ";
			if (!((ast[0] == '0' && ast.size() == 1) || (ast[0] != '0'))) continue;
			if (!((bst[0] == '0' && bst.size() == 1) || (bst[0] != '0'))) continue;
			if (!((cst[0] == '0' && cst.size() == 1) || (cst[0] != '0'))) continue;
			a = atoi(ast.c_str());
			b = atoi(bst.c_str());
			c = atoi(cst.c_str());
//			cout << a << "  " << b << "  " << c << "  /  ";
			if (a + b == c) jud(a, b, c);
			if (b + a == c && b != a) jud(b, a, c);
			if (a + c == b) jud(a, c, b);
			if (c + a == b && c != a) jud(c, a, b);
			if (b + c == a) jud(b, c, a);
			if (c + b == a && c != b) jud(c, b, a);
		}
//		cout << endl;
		dfs_out.clear();
	}
	
	cout << ans.size();
	
	return 0;
}
