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

void no()
{
    cout << "-1" << endl;
    return;
}

void solve()
{
    int n;
    see(n);
    v<ll> a(n);
    rep(i, 0, n) see(a[i]);

    int fp = -1;
    if (a[n - 2] > a[n - 1])
    {
        cout << "-1" << endl;
        return;
    }
    if (a[n - 1] >= 0)
    {
        fp = n - 1;
    }
    else if (a[n - 2] >= 0)
    {
        fp = n - 2;
    }

    v<v<ll>> ans;

    rev(i, n - 3, 0)
    {
        if (a[i] > a[i + 1])
        {
            if (fp < 0)
            {
                no();
                return;
            }
            a[i] = a[i + 1] - a[fp];
            ans.pb({i, i + 1, fp});
        }
    }
    cout << sz(ans) << endl;
    rep(i, 0, sz(ans))
    {
        cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << " " << ans[i][2] + 1 << " " << endl;
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