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
using ll = long long;
using namespace std;

template <typename... T>
void see(T &...args) { ((cin >> args), ...); }

const int M = 1e9 + 7;
int grid[1005][1005] = {0};

void x()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve();
int main()
{
    x();
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}
void solve()
{
    ll h, p;
    see(h, p);
    ll ans = 0;
    ll t = (1LL << h) - 1;
    rep(i, 0, h)
    {
        ll num = (1LL << i);
        if (p >= num)
        {
            ans++;
            t -= num;
        }
        else
        {
            break;
        }
    }
    ans += t / p;
    if (t % p)
    {
        ans++;
    }
    cout << ans << endl;
}