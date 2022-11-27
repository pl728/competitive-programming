#include <bits/stdc++.h>
#define for(i,a,b) for (int i = a; i < b; i++)
using ll = long long;
using namespace std;

const int M = 1e9 + 7;

void solve1() {
    int n; cin >> n;
    unordered_set<int> uset;
    for(i,0,n){
        uset.insert(i+1);
    }
    for(i,0,n-1) {
        int x; cin >> x;
        uset.erase(x);
    }
    cout << *uset.begin();
}

void solve2() {
    int n; cin >> n;
    ll total1 = (n * (n + 1)) / 2;
    ll total2 = 0;
    for(i,0,n - 1) {
        int x; cin >> x;
        total2 += x;
    }
    cout << total1 - total2;
}

int main() {
    solve2();
}