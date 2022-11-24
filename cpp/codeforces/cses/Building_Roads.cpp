#include <bits/stdc++.h>
#define f(i,b) for (int i = 0; i < b; i++)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define v vector

using ll = long long;
using namespace std;

const int M = 1e9 + 7;
int grid[1005][1005];
int visited[1005];

v<v<int>> G;

int n, m;

void dfs(int x) {
    visited[x] = 1;
    for(int i : G[x]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

void solve() {
    cin >> n >> m;
    G.resize(n+1);
    f(i,m){
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    v<int> p;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            p.pb(i);
            dfs(i);  
        }
    }
    cout << p.size() - 1 << endl;
    for(int i = 1; i < (int) p.size(); i++) {
        cout << p[i-1] << " " << p[i] << endl;
    }
}

int main() {
    solve();
}