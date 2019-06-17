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

void pref_func(string& s, vector<int>& p) {
    int j;
    for (int i = 1; i < s.size(); i++) {
        j = p[i-1];
        while (j > 0 && s[i] != s[j])
            j = p[j-1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return;
}

void readinit(string& s, vector<int>& p) {
    cin >> s;
    p.resize(s.size(), 0);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    vector<int> p;
    readinit(s, p);
    pref_func(s, p);
    cout << p << endl;
    return 0;
}