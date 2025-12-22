#include<bits/stdc++.h> 
using namespace std;

string a, b;
typedef struct node;
typedef node *tree;
struct node {
	char data;
	tree lc = NULL; 
	tree rc = NULL;
};

void pr(tree father) {
	if (father == NULL) return;
	cout << father -> data;
//	printf("%d fa:%d lc:%d rc:%d \n", char(father -> data), father, father -> lc, father -> rc);
	pr(father -> lc);
	pr(father -> rc);
}

void inbuild(string s1, string s2, tree root) {
	root -> data = s1[s1.size() - 1];
	if (s1.size() == 1 || s2.size() == 1) {
		return;
	}
	tree lc = new node;
	tree rc = new node;
	int p = s2.find(s1[s1.size() - 1]);
	string l1 = s1.substr(0, p);
	string l2 = s2.substr(0, p);
	if (p != 0) {
		inbuild(l1, l2, lc);
		root -> lc = lc;
	}
	string r1 = s1.substr(p, s1.size() - p - 1);
	string r2 = s2.substr(p + 1, s2.size() - p - 1);
	if (s1.size() - p - 1 != 0) {
		inbuild(r1, r2, rc);
		root -> rc = rc;
	}
}

int main() {
	getline(cin, a);
	getline(cin, b);
	tree bt = new node;
	inbuild(b, a, bt);
	
	pr(bt);
	
	return 0;
}

