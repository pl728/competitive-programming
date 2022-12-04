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
// 1 5 8
//  4 7

void solve()
{
    int n;
    cin >> n;
    v<int> a(n);
    rep(i, 0, n) see(a[i]);

    // if all same, print -1
    sort(all(a));
    v<int> diff;
    rep(i, 1, n)
    {
        if (a[i] - a[0] != 0)
        {
            diff.pb(a[i] - a[0]);
        }
    }
    if (sz(diff) == 0)
    {
        cout << -1 << endl;
        return;
    }
    if (sz(diff) == 1)
    {
        cout << diff[0] << endl;
        return;
    }
    int g = gcd(diff[0], diff[1]);
    rep(i, 2, sz(diff))
    {
        g = gcd(g, diff[i]);
    }
    cout << g << endl;
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