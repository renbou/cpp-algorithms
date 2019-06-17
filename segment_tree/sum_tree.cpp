#include <bits/stdc++.h>
#define FORN(n) for(int i = 0; i < n; i++)
#define nl '\n'
using namespace std;

typedef long long ll;

vector<ll> stree;
vector<ll> a;
int n;
void build(int v = 1, int tl = 0, int tr = n-1) {
    if (tl == tr) {
        stree[v] = a[tl];
        return;
    }
    int mid = (tl+tr)/2;
    build(v*2, tl, mid);
    build(v*2+1, mid+1, tr);
    stree[v] = stree[v*2]+stree[v*2+1];
    return;
}

void update(int i, ll val, int v = 1, int tl = 0, int tr = n-1) {
    if (tl == tr) {
        stree[v] = val;
        return;
    }
    int mid = (tl+tr)/2;
    if (i <= mid)
        update(i, val, v*2, tl, mid);
    else
        update(i, val, v*2+1, mid+1, tr);
    stree[v] = stree[v*2] + stree[v*2+1];
    return;
}

ll getsum(int l, int r, int v = 1, int tl = 0, int tr = n-1) {
    if (tl > r || tr < l) return 0;
    if (tl >= l && tr <= r) return stree[v];
    int mid = (tl+tr)/2;
    return getsum(l, r, v*2, tl, mid) + getsum(l, r, v*2+1, mid+1, tr);
}
 
void readinit() {
    cin >> n;
    a.resize(n);
    stree.resize(n*4, 0);
    FORN(n)
        cin >> a[i];
    build();
    return;
}

void requests() {
    int m; cin >> m;
    char r; int u, v;
    FORN(m) {
        cin >> r >> u >> v;
        if (r == 'U')
            update(u, v);
        else
            cout << getsum(u, v) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    readinit();
    requests();
    return 0;
}