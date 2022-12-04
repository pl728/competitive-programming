#include <bits/stdc++.h>
#define py puts("YES")
#define pn puts("NO")
#define pf puts("-1")
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

ll intCeil(int x, int y)
{
    return (x + y - 1) / y;
}

void solve();
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}
void solve()
{
    int n;
    see(n);
    ll ans = 0;
    v<ll> a(n + 1);
    rep(i, 1, n + 1) see(a[i]);
    rep(i, 1, n + 1)
    {
        // int ii = i + 1;
        // while (ii < n + 1 && (ii + i) % a[i] != 0)
        //     ii++;
        // find x such that x | a[i] and x - i > i
        ll x = i / a[i] + 1;
        ll ii = (x * a[i]) - i;
        while (ii < n + 1)
        {
            if (ii > i && ii + i == a[ii] * a[i])
                ans++;
            ii += a[i];
        }
    }
    cout << ans << endl;
}