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

void z_func(string& s, vector<int>& z) {
    int l = 0, r = 0;
    for (int i = 1; i < s.size(); i++) {
        if (i <= r) z[i] = min(r-i+1, z[i-l]);
        while (i + z[i]< s.size() && s[z[i]] == s[i+z[i]])
            z[i]++;
        if (i+z[i]-1 > r)
            r = i+z[i]-1, l = i;
    }
}

void readinit(string& s, vector<int>& z) {
    cin >> s;
    z.resize(s.size(), 0);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    vector<int> z;
    readinit(s, z);
    z_func(s, z);
    cout << z << endl;
    return 0;
}