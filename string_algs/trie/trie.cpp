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

template<typename T> inline ostream & operator<< (ostream &_out, vector<T> &_v) { for (auto &_i : _v) { _out << _i << " "; } return _out; }
template<typename T> inline istream & operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }

mt19937 rnd(42);

typedef long long ll;

struct trie_node {
    trie_node * children[26] = {nullptr};
    int end = -1;
};

void insert(trie_node *f, string s) {
    int ind;
    for (char c: s) {
        ind = c - 'a';
        if (f->children[ind] == nullptr)
            f->children[ind] = new trie_node;
        f = f->children[ind];
    }
    f->end = s.size();
}

bool search(trie_node *f, string s) {
    int ind;
    for (char c: s) {
        ind = c - 'a';
        if (f->children[ind] == nullptr) return false;
        f = f->children[ind];
    }
    if (f->end == s.size()) return true;
    return false;
}

void read(vector<string>& w) {
    int n; cin >> n;
    w.resize(n);
    cin >> w;
    return;
}

void build (trie_node& dict, vector<string>& w) {
    for (string s: w)
        insert(&dict, s);
    return;
}

void requests(trie_node& dict) {
    int m; cin >> m;
    string req, r;
    FORN(m) {
        cin >> req >> r;
        if (req == "INS")
            insert(&dict, r);
        else if (req == "FIND")
            cout << (search(&dict, r) ? "FOUND" : "NOT FOUND") << endl;
        else
            cout << "NO SUCH COMMAND" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<string> words;
    trie_node dict;
    read(words);
    build(dict, words);
    requests(dict);
    return 0;
}