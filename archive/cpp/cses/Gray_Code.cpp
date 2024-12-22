#include <bits/stdc++.h>
#define f(i,b) for (int i = 0; i < b; i++)
#define pb push_back
using ll = long long;
using namespace std;

const int M = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<string> v;
    v.pb("0");
    v.pb("1");
    f(i,n-1) {
        int x = v.size();
        for(int i = x-1; i >= 0; i--) {
            v.pb("1" + v[i]);
        }
        f(i,x) {
            v[i] = "0" + v[i];
        }
    }
    f(i, pow(2,n)) {
        cout << v[i] << endl;
    }
}

int main() {
    solve();
}