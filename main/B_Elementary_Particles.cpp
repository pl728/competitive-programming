#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define v vector
using ll = long long;
using namespace std;

template <typename... T>
void see(T &...args) { ((cin >> args), ...); }

const int M = 1e9 + 7;
int grid[1005][1005] = {0};
int visited[1005][1005] = {0};

void solve()
{
    int n;
    see(n);
    v<int> a(n);
    unordered_map<int, v<int>> b;
    rep(i, 0, n) see(a[i]);
    int ans = -1;
    rep(i, 0, n)
    {
        b[a[i]].pb(i);
    }
    for (const auto &x : b)
    {
        v<int> y = x.second;
        rep(i, 1, y.size())
        {
            ans = max(ans, n - (y[i] - y[i - 1]));
        }
    }
    cout << ans << endl;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}