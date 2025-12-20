#include<bits/stdc++.h>
using namespace std;
const int MAXT = 20;
const int MAXL = 200;
struct bi;
int t, L[MAXT], F[MAXT], E[MAXT];
string inO[MAXT], O[MAXT], tmp;

struct bi{
    char name;
    int num;
};
bi b;
vector<bi> B;

string calcO(string o, int num, bool n) {
    string out = "O(";
    if (n) {
        out = "O(n^" + to_string(atoi(o.substr(4, o.size() - 5).c_str()) + num);
    } else if (o != "") out += (char(num * atoi(o.substr(2, o.size() - 2).c_str())) + '0');
    out += ')';
    return out;
}

bool findele(vector<bi> a, bi ele) {
    for (bi i : a) if (i.name == ele.name) return true;
    return false;
}

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> L[i] >> inO[i];
        B.clear();
        for (int j = 0; j < L[i]; j++) {
            getline(cin, tmp);
            if (tmp[0] == 'F') {
                F[i]++;
                b.name = tmp[2];
                tmp = tmp.substr(4, tmp.size() - 4);
                if(findele(B, b)) {
                    cout << "B ERR" << endl;
                    break;
                } else {
                    B.push_back(b);
                    if(int(tmp[5]) >= 48 && int(tmp[5]) <= 57) {
                        b.num = atoi(tmp.substr(4, tmp.find(" ")).c_str());
                        if(tmp[tmp.size() - 1] == 'n') O[i] = calcO(O[i], 1, true);
                        else {
                            calcO(O[i], atoi(tmp.substr(tmp.find(" ") + 1, tmp.size() - tmp.find(" ") - 1).c_str()), false);
                        }
                    } else {
                        O[i] = calcO(O[i], 1, false);
                        break;
                    }
                }
            }
            else (tmp[0] == 'E') E[i]++;
        }
        if (F[i] != E[i]) {
            cout << F[i] << " " << E[i] << " FE ";
            cout << "ERR" << endl;
        }
        else if (O[i] == inO[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
} 