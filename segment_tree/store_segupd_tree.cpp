#include <bits/stdc++.h>
#define FORN(n) for(int i = 0; i < n; i++)
#define nl '\n'
#define INF 1e9
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
    return;
}

void push(int v) {
    if (stree[v] != -1)
        stree[v*2] = stree[v*2+1] = stree[v], stree[v] = -1;
    return;
}

void update(int l, int r, int val, int v = 1, int tl = 0, int tr = n-1) {
    if (tl > r || tr < l) return;
    if (tl >= l && tr <= r) {
        stree[v] = val;
        return;
    }
    push(v);
    int mid = (tl+tr)/2;
    update(l, r, val, v*2, tl, mid);
    update(l, r, val, v*2+1, mid+1, tr);
    return;
}

ll get(int i, int v = 1, int tl = 0, int tr = n-1) {
    if (tl <= i && tr >= i && stree[v] != -1)
        return stree[v];
    int mid = (tl+tr)/2;
    if (i <= mid)
        return get(i, v*2, tl, mid);
    else
        return get(i, v*2+1, mid+1, tr);
}

void read() {
    cin >> n;
    a.resize(n);
    stree.resize(4*n);
    FORN(n)
        cin >> a[i];
    build();
}

void requests() {
    int m; cin >> m;
    char r; int u, v, k;
    FORN(m) {
        cin >> r >> u;
        if (r == 'U') {
            cin >> v >> k;
            update(u, v, k);
        } else {
            cout << get(u) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    read();
    requests();
    return 0;
}