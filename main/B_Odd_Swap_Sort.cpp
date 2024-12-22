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

void solve()
{
    //

    int n;
    see(n);
    v<int> a(n);
    rep(i, 0, n) see(a[i]);
    v<int> o, e;
    rep(i, 0, n)
    {
        if ((a[i] & 1))
        {
            o.pb(a[i]);
        }
        else
        {
            e.pb(a[i]);
        }
    }
    rep(i, 1, sz(o))
    {
        if (o[i] < o[i - 1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    rep(i, 1, sz(e))
    {
        if (e[i] < e[i - 1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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