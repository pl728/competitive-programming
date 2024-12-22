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
// cbcbcac

void solve()
{
    int a, b, c, m;
    see(a, b, c, m);
    ll most = max(0, a - 1) + max(0, b - 1) + max(0, c - 1);
    v<int> x;
    x.pb(a);
    x.pb(b);
    x.pb(c);
    sort(all(x));
    ll least = max(0, x[2] - x[0] - x[1] - 1);
    if (m >= least && m <= most)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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