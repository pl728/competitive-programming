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
    ll n, m;
    see(n, m);
    set<pair<ll, ll>> edge;
    while (m--)
    {
        ll a, b;
        see(a, b);
        if (a < b)
        {
            pair<ll, ll> x = {b, a};
            if (!contains(edge, x))
            {
                edge.insert({b, a});
            }
        }
        else
        {
            pair<ll, ll> x = {a, b};
            if (!contains(edge, x))
            {
                edge.insert({a, b});
            }
        }
    }
    ll t = 0;
    ll start = 1;
    for (auto x : edge)
    {
        if (x.second < start || x.first < start)
        {
            continue;
        }
        ll h = x.first - start;
        t += h * (h + 1) / 2;
        start = x.first;
    }
    ll h = n - start + 1LL;
    t += h * (h + 1) / 2LL;
    cout << t << endl;
}

void tie()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

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