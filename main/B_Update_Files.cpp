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

ll intCeil(ll x, ll y)
{
    return (x + y - 1) / y;
}

void solve()
{
    ll n, k;
    see(n, k);
    ll t = 0;
    ll c = 0;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    for (ll i = 1; i <= k; i *= 2)
    {
        t += i;
        c++;
        if (t >= n - 1)
        {
            cout << c << endl;
            return;
        }
    }
    cout << c + intCeil((n - 1 - t), k) << endl;
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