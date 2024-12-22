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

void yes()
{
    cout << "YES" << endl;
}
void no()
{
    cout << "NO" << endl;
}
bool check(v<int> a, int x)
{
    v<int> b;
    rep(i, 0, sz(a))
    {
        if (a[i] != x)
            b.pb(a[i]);
    }
    rep(i, 0, sz(b) / 2)
    {
        if (b[i] != b[sz(b) - 1 - i])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    see(n);
    v<int> a(n);
    rep(i, 0, n)
    {
        see(a[i]);
    }
    rep(i, 0, n / 2)
    {
        if (a[i] != a[n - 1 - i])
        {
            if (check(a, a[i]) || check(a, a[n - 1 - i]))
            {
                yes();
            }
            else
            {
                no();
            }
            return;
        }
    }
    yes();
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