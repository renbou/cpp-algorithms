#include <bits/stdc++.h>
#define FORN(n) for(int i = 0; i < n; i++)
#define nl '\n'
#define INF 1e9
using namespace std;

typedef long long ll;

struct nd {
    ll mx, up = 0;
};

vector<nd> stree;
vector<ll> a;
int n;
void build(int v = 1, int tl = 0, int tr = n-1) {
    if (tl == tr) {
        stree[v].mx = a[tl];
        return;
    }
    int mid = (tl+tr)/2;
    build(v*2, tl, mid);
    build(v*2+1, mid+1, tr);
    stree[v].mx = max(stree[v*2].mx, stree[v*2+1].mx);
    return;
}

void update(int l, int r, ll val, int v = 1, int tl = 0, int tr = n-1) {
    if (tl > r || tr < l) return;
    if (tl >= l && tr <= r) {
        stree[v].up += val;
        stree[v].mx += val;
        return;
    }
    int mid = (tl+tr)/2;
    update(l, r, val, v*2, tl, mid);
    update(l, r, val, v*2+1, mid+1, tr);
    stree[v].mx = stree[v].up+max(stree[v*2].mx, stree[v*2+1].mx);
    return;
}

ll getmax(int l, int r, int v = 1, int tl = 0, int tr = n-1) {
    if (tl > r || tr < l) return -INF;
    if (tl >= l && tr <= r) return stree[v].mx;
    int mid = (tl+tr)/2;
    return stree[v].up+max(getmax(l, r, v*2, tl, mid), getmax(l, r, v*2+1, mid+1, tr));
}
 
void readinit() {
    cin >> n;
    a.resize(n);
    stree.resize(n*4, {0, 0});
    FORN(n)
        cin >> a[i];
    build();
    return;
}

void requests() {
    int m; cin >> m;
    char r; int u, v, k;
    FORN(m) {
        cin >> r >> u >> v;
        if (r == 'U') {
            cin >> k;
            update(u, v, k);
        }
        else
            cout << getmax(u, v) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    readinit();
    requests();
    return 0;
}