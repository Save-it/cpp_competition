#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, na, nb;
    cin >> n >> na >> nb;
    
    int a[na], b[nb];
    for (int i = 0; i < na; i++) cin >> a[i];
    for (int i = 0; i < nb; i++) cin >> b[i];
    
    int r[5][5] = {{0, -1, 1, 1, -1},
				   {1, 0, -1, 1, -1},
				   {-1, 1, 0, -1, 1},
				   {-1, -1, 1, 0, 1},
				   {1, 1, -1, -1, 0}};
	int as, bs = 0;
    for (int i = 0; i < n; i++) {
    	if (r[a[i % na]][b[i % nb]] == 1) as++;
    	if (r[a[i % na]][b[i % nb]] == -1) bs++;
//    	cout << a[i % na] << " " << b[i % nb] << " " << r[a[i % na]][b[i % nb]] << endl << as << " " << bs << endl;
	}
    
    cout << as << " " << bs;
    
    return 0;
}
