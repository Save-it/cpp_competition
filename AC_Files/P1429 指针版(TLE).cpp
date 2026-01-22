#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
const int M = 2100000000;
int n, tmp;
double ans;

struct p {
    int x;
    int y;
} r[MAXN];

struct node;
typedef node* tree;
struct node {
    tree fa = NULL;
    tree lc = NULL;
    tree rc = NULL;
    p pt;
    int maxx, maxy, minx, miny;
    bool fx;
};

bool cmpx(p a, p b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool cmpy(p a, p b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

void build(int start, int end, tree fa, bool fx) {
    if (start >= end) {
        if (start == end) {
            fa -> pt = r[start];
            fa -> fx = fx;
            fa -> maxx = r[start].x;
            fa -> maxy = r[start].y;
            fa -> minx = r[start].x;
            fa -> miny = r[start].y;
        }
        return;
    }
    int mid = (start + end) / 2;
    if (fx) nth_element(r + start, r + mid, r + (end - start + 1), cmpx);
    else nth_element(r + start, r + mid, r + (end - start + 1), cmpy);
    fa -> pt = r[mid];
    fa -> fx = fx;
    
    tree lc = new node;
    tree rc = new node;
    lc -> fa = fa;
    rc -> fa = fa;
    fa -> lc = lc;
    fa -> rc = rc;
    build(start, mid - 1, lc, !fx);
    build(mid + 1, end, rc, !fx);
    fa -> maxx = max(fa -> lc -> maxx, fa -> rc -> maxx);
    fa -> maxy = max(fa -> lc -> maxy, fa -> rc -> maxy);
    fa -> minx = min(fa -> lc -> minx, fa -> rc -> minx);
    fa -> miny = min(fa -> lc -> miny, fa -> rc -> miny);
}

void print(tree fa) {
    if (fa == NULL) return;

    print(fa -> lc);
    cout << fa -> pt.x << " " << fa -> pt.y << endl;
    print(fa -> rc);
}

int rectDst(tree x, tree r) {
    if (r == NULL) return M;
    int out = M;
    out = min(x -> pt.x - r -> maxx, out);
    out = min(x -> pt.x - r -> minx, out);
    out = min(x -> pt.y - r -> maxy, out);
    out = min(x -> pt.y - r -> miny, out);
    return pow(out, 2);
}

int minDst(tree root, tree x) {
    if (root == NULL) return M;
    int out = M;
    int tmp = int(pow(x -> pt.x - root -> pt.x, 2) + pow(x -> pt.y - root -> pt.y, 2));
    if (tmp != 0) out = min(tmp, out);
    if (rectDst(x, root -> lc) < out) out = min(minDst(root -> lc, x), out);
    if (rectDst(x, root -> rc) < out) out = min(minDst(root -> rc, x), out);
    return out;
}

int search(tree root, tree x) {
    if (x == NULL) return M;
    int out = M;
    out = min(minDst(root, x), out);
    out = min(search(root, x -> lc), out);
    out = min(search(root, x -> rc), out);
    return out;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r[i].x >> r[i].y;
     }
    
    tree root = new node;
    build(0, n - 1, root, true);
    
    ans = search(root, root);

    printf("%.4f", sqrt(ans));

    return 0;
}