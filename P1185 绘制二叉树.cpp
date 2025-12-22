#include<bits/stdc++.h> 
using namespace std;

char ans[10000][10000];
int m, n, a[1000][2], ps[10000], ma[10000], len, l[10000][10000], r[10000][10000];
typedef struct node;
typedef node *tree;
struct node {
	char data = 'o';
	tree lc = NULL;
	tree rc = NULL;
	int x = 0;
	int y = 0;
};

bool findele(tree fa) {
	if (fa == NULL) return false;
	for (int t = 0; t < n; t++) {
		if (fa -> y == a[t][0] && fa -> x == a[t][1]) return true;
	}
	return false;
}

void build(tree fa, int dp, int enddp) {
	fa -> y = dp + 1;
	fa -> x = ma[dp] + 1;
//	cout << fa -> y << " " << fa -> x << endl;
	ma[dp]++;
	dp++;
	if (dp == enddp) return;
	tree lc = new node;
	tree rc = new node;
	fa -> lc = lc;
	fa -> rc = rc;
	build(lc, dp, enddp);
	build(rc, dp, enddp);
}

void draw(tree fa, int dp, int enddp, int f, int d) {
	if (fa == NULL) return;
	int n1 = enddp - dp;
	if (ps[dp] == 0) ps[dp] += 6 * pow(2, n1 - 3) - 1;
	if (findele(fa) || d == 1) {
		ps[dp]++;
		if (n1 == 1) {
			if (f == 0) {
				for (int j = 0; j < 3; j++) {
					ps[dp]++;
				}
			} else if (f == 1) {
				ps[dp]++;
			}
		} else {
			for (int j = 0; j < 6 * pow(2, n1 - 2) - 1 ; j++) {
				ps[dp]++;
			}
		}
		dp++;
		draw(fa -> lc, dp, enddp, 0, 1);
		draw(fa -> rc, dp, enddp, 1, 1);
		return;
	}
	ps[dp]++;
	if (findele(fa -> lc)) l[dp][ps[dp]]++;
	if (findele(fa -> rc)) r[dp][ps[dp]]++;
	ans[dp][ps[dp]] = 'o';
	if (n1 == 1) {
		if (f == 0) {
			for (int j = 0; j < 3; j++) {
				ps[dp]++;
			}
		} else if (f == 1) {
			ps[dp]++;
		}
	} else {
		for (int j = 0; j < 6 * pow(2, n1 - 2) - 1 ; j++) {
			ps[dp]++;
		}
	}
	dp++;
	draw(fa -> lc, dp, enddp, 0, 0);
	draw(fa -> rc, dp, enddp, 1, 0);
}


int main() {
	cin >> m >> n;
	fill(ps, ps + 100, 0);
	for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
	len = pow(2, m - 1) * 6 - 1;
	tree root = new node;
	build(root, 0, m);
	draw(root, 0, m, -1, 0);
	int deps[m];
	fill(deps, deps + m, 1);
	deps[1] = 1;
	for (int i = 2; i < m; i++) {
		for (int j = 0; j < i; j++) {
			deps[i] += deps[j];
		}
		deps[i] += i;
	}
	deps[1] = 2;
	
	for (int i = 0; i < m; i++) {
		vector<int> o;
		o.push_back(1);
		for (int j = 0; j < len && i != 0; j++) if (ans[i - 1][j] != 0) o.push_back(j);
		for (int j = 0; j < deps[m - i - 1] && i != 0; j++) {
			string out;
			while(out.size() < len) out += ' ';
			for (int q = 1; q < o.size(); q++) {
				int p = o[q];
				if (r[i - 1][p] == 0) out[p + j + 1] = '\\';
				if (l[i - 1][p] == 0) out[p - j - 1] = '/';
			}
			cout << out.substr(1, out.size() - 1) << endl;
		}
		for (int j = 1; j < pow(2, m - 1) * 6 - 1; j++) {
			if (ans[i][j] == 0) cout << ' ';
			else cout << 'o';
		}
		cout << endl;
	}
	
	return 0;
}


