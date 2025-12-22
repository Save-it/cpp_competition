#include<bits/stdc++.h>
using namespace std;
const int MAXT = 20;
const int MAXL = 200;
struct bi;
int t, L[MAXT], F[MAXT], E[MAXT], O[MAXT];
string inO[MAXT], tmp[4];
bool On[MAXT];

struct bi{
    string name;
    int num;
};
bi b;
vector<bi> B;

bool findele(vector<bi> a, bi ele) {
    for (bi i : a) if (i.name == ele.name) return true;
    return false;
}

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> L[i];
        cin >> inO[i];
        inO[i] = inO[i].substr(2, inO[i].size() - 3);
        B.clear();
        bool f = false;
        for (int j = 0; j < L[i]; j++) {
            fill(tmp, tmp + 4, "");
            cin >> tmp[0];
            if (tmp[0] == "F") {
                cin >> tmp[1] >> tmp [2] >> tmp[3];
                F[i]++;
                b.name = tmp[1];
                if(findele(B, b)) {
                    cout << "B ERR" << endl;
                    break;
                } else {
                    B.push_back(b);
                }
                if (f == false) {
                    if (tmp[2] == "n") {
                        f = true;
                        O[i]++;
                    } else if (tmp[3] == "n") {
                        On[i] = true;
                        O[i]++;
                    } else {
                        O[i] 
                    }
                }
                
            }
            else {cout << "E";E[i]++;}
        }
        cout << L[i] << "  in: " << inO[i] << "  out: " << O[i] << "  " << endl;
        if (F[i] != E[i]) {
            cout << F[i] << " " << E[i] << " FE ";
            cout << "ERR" << endl;
        }
        else if ("n^" + to_string(O[i]) == inO[i] || to_string(O[i]) == inO[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
} 