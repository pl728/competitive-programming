#include <bits/stdc++.h>
#define f(i,b) for (int i = 0; i < b; i++)
#define pb push_back
using ll = long long;
using namespace std;

const int M = 1e9 + 7;

void solve() {
    ll n; cin >> n; 
    int k; cin >> k;
    vector<ll> a(k);
    f(i,k) cin >> a[i];
    ll total = 0;
    f(i,k) {
        total += n / a[i];
    }
    for(int i = 0; i < k; i++) {
        for(int j = i + 1; j < k; j++) {
            total -= n / (a[i] * a[j]);
        }
    }
    for(int i)
    // all pairs, all triples, all quadruples, etc
    cout << total << endl;
}
int main() {
    solve();
}