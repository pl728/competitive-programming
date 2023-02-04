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
    int n;
    see(n);
    v<int> a(n);
    ll s = 0;
    rep(i, 0, n)
    {
        // 1 1, 1 -1, -1 1, -1 -1
        see(a[i]);
        s += a[i];
    }
    int x = 0, y = 0, z = 0;
    rep(i, 0, n - 1)
    {
        if (a[i] + a[i + 1] == 2)
        {
            x++;
        }
        else if (a[i] + a[i + 1] == 0)
        {
            y++;
        }
        else if (a[i] + a[i + 1] == -2)
        {
            z++;
        }
    }
    if (z > 0)
    {
        cout << s + 4 << endl;
        return;
    }
    if (y > 0)
    {
        cout << s << endl;
        return;
    }
    if (x > 0)
    {
        cout << s - 4 << endl;
        return;
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