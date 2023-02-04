#include <bits/stdc++.h>
#define py puts("YES")
#define pn puts("NO")
#define pf puts("-1")
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)(x).size())
#define len(x) ((int)(x).length())
#define v vector
#define vi v<int>
#define vii v<v<int>>
#define contains(a, b) ((a).find(b) != (a).end())
using ll = long long;
using namespace std;

template <typename... T>
void see(T &...args) { ((cin >> args), ...); }

const int MXN = 1e9 + 7;
int grid[1005][1005] = {0};

void solve()
{
    ll n;
    ;
    see(n);
    v<ll> a(n);
    rep(i, 0, n) see(a[i]);
    sort(all(a));
    map<ll, int> count;
    rep(i, 0, n)
    {
        count[a[i]]++;
    }
    if (a[0] != a[n - 1])
    {
        ll x = count[a[0]], y = count[a[n - 1]];
        ll ans = 2 * x * y;
        cout << ans << endl;
    }
    else
    {
        ll ans = n * (n - 1);
        cout << ans << endl;
    }
}

void tie()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve();
int main()
{
    tie();
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}