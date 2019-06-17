#include <bits/stdc++.h>
#pragma GCC optimize ("-O3,unroll-loops")
#define FORN(n) for(int i = 0; i < n; i++)
#define nl '\n'
#define INF 1e9
#define F first
#define S second
#define PB push_back
#define INS insert
#define ER erase
using namespace std;

mt19937 rnd(42);

typedef long long ll;

struct node {
    ll key, pr;
    int cnt = 0;
    node* l = nullptr, * r = nullptr;
    node (ll x): key(x), pr(rnd()) {}
};

ll get_cnt(node* &t) {
    return t != nullptr ? t->cnt : 0;
}

void upd(node* &t) {
    if (t != nullptr) t->cnt = 1 + get_cnt(t->l) + get_cnt(t->r);
    return;
}

void merge(node* &t, node* l, node* r) {
    if (l == nullptr || r == nullptr)
        t = l != nullptr ? l : r;
    else if (l->pr > r->pr) 
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd(t);
    return;
}

void split(node* t, node* &l, node* &r, ll key) {
    if (t == nullptr)
        l = r = nullptr;
    else if (key < t->key)
        split(t->l, l, t->l, key), r = t;
    else
        split(t->r, t->r, r, key), l = t;
    upd(t);
    return; 
}

void insert(node* &t, ll key) {
    node* l, * r;
    split(t, l, r, key);
    node* tmp = new node(key);
    merge(t, l, tmp);
    merge(t, t, r);
    return;
}

void erase_by_key(node* &t, ll key) {
    if (t == nullptr) return;
    if (t->key == key) merge(t, t->l, t->r);
    else if (key < t->key) erase_by_key(t->l, key);
    else erase_by_key(t->r, key);
    upd(t);
    return;
}

void erase_by_order(node* &t, ll ind) {
    if (t == nullptr) return;
    if (ind == get_cnt(t->l)+1) merge(t, t->l, t->r);
    else if (ind <= get_cnt(t->l)) erase_by_order(t->l, ind);
    else erase_by_order(t->r, ind-get_cnt(t->l)-1);
    upd(t);
    return;
}

int get_order(node* &t, ll key) {
    if (t == nullptr) return -1;
    if (t->key == key) return get_cnt(t->l)+1;
    else if (t->key > key) return get_order(t->l, key);
    else return get_cnt(t->l)+1+get_order(t->r, key);
}

node* get_by_order(node* &t, ll ind) {
    if (t == nullptr || ind < 1 || ind > t->cnt) return nullptr;
    if (ind == get_cnt(t->l)+1) return t;
    else if (ind <= get_cnt(t->l)) return get_by_order(t->l, ind);
    else return get_by_order(t->r, ind-get_cnt(t->l)-1);
}

void build(vector<ll> &a, node* &f) {
    for (ll i: a)
        insert(f, i);
    return;
}

void read(vector<ll> &a) {
    int n; cin >> n;
    a.resize(n);
    FORN(n)
        cin >> a[i];
    return;
}

void requests(node* &f) {
    int m; cin >> m;
    string r; ll u;
    FORN(m) {
        cin >> r >> u;
        if (r == "INS")
            insert(f, u);
        else if (r == "DEL_IND")
            erase_by_order(f, u);
        else if (r == "DEL_KEY")
            erase_by_key(f, u);
        else if (r == "GET_IND") {
            int res = get_order(f, u);
            if (res == -1)
                cout << "KEY NOT FOUND" << endl;
            else
                cout << "KEY FOUND AT INDEX " << res << endl;
        }
        else if (r == "GET_KEY") {
            node* res = get_by_order(f, u);
            if (res == nullptr)
                cout << "NO KEY AT INDEX " << u << endl;
            else
                cout << "FOUND KEY " << res->key << endl;
        }
        else
            cout << "NO SUCH COMMAND" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<ll> ar;
    node* f = nullptr;
    read(ar);
    build(ar, f);
    requests(f);
    return 0;
}