#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)(x).size())
#define v vector
using ll = long long;
using namespace std;

template <typename... T>
void see(T &...args) { ((cin >> args), ...); }

const int M = 1e9 + 7;
int grid[1005][1005] = {0};

void solve()
{
    // [2,7,10,11,22,26,30]
    // [7,8,10]
    int n, m;
    see(n, m);
    v<int> a(n);
    rep(i, 0, n) see(a[i]);

    v<int> b(m);
    rep(i, 0, m) see(b[i]);

    int i = 0, j = 0;
    ll x = 0, y = 0;
    int ans = 0;
    while (i < n)
    {
        if (x != 0 && x == y)
        {
            ans++;
            x = 0, y = 0;
        }
        if (x < y)
            x += a[i++];
        else
            y += b[j++];
    }
    cout << ans + 1 << endl;
}

int main()
{
    solve();
}