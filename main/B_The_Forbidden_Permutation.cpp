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
    int n, m, d;
    see(n, m, d);
    unordered_map<int, int> p;
    rep(i, 0, n)
    {
        int x;
        see(x);
        p[x] = i;
    }

    v<int> a(m);
    rep(i, 0, m)
    {
        see(a[i]);
    }

    int ans = 1e6;
    rep(i, 1, m)
    {
        int x = p[a[i - 1]], y = p[a[i]];
        int dx = y - x;
        // if dx = 1, and d = 2, we need
        if (y < x || dx > d)
        {
            cout << 0 << endl;
            return;
        }

        // calculate dist to move > d
        if ((n - 1) > d)
        {
            ans = min(ans, d - dx + 1);
        }

        // calculate dist to swap
        ans = min(ans, dx);
    }
    cout << ans << endl;
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