#include <bits/stdc++.h>
#define FORN(n) for(int i = 0; i < n; i++)
#define nl '\n'
#define INF 1e9
using namespace std;

typedef long long ll;

vector<ll> a;
int n;

ll get(int i) {
    return a[i];
}

void update(int l, int r, int val) {
    for (int i = l; i < r; i++)
        a[i] = val;
    return;
}

void add(int l, int r, int val) {
    for (int i = l; i < r; i++)
        a[i] += val;
    return;
}

ll rsq(int l, int r) {
    ll sum = 0;
    for (int i = l; i < r; i++)
        sum += a[i];
    return sum;
}

ll rmq(int l, int r) {
    ll mn = INF;
    for (int i = l; i < r; i++)
        mn = min(mn, a[i]);
    return mn;
}

void readinit() {
    cin >> n;
    a.resize(n);
    FORN(n)
        cin >> a[i];
    return;
}

void requests() {
    int m; cin >> m;
    string r; int u, v, k;
    FORN(m) {
        cin >> r >> u;
        if (r == "get")
            cout << get(u-1) << endl;
        else if (r == "update") {
            cin >> v >> k;
            update(u-1, v, k);
        } else if (r == "add") {
            cin >> v >> k;
            add(u-1, v, k);
        } else if (r == "rsq") {
            cin >> v;
            cout << rsq(u-1, v) << endl;
        } else {
            cin >> v;
            cout << rmq(u-1, v) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    readinit();
    requests();
    return 0;
}