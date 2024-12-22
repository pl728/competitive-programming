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
    int n;
    string s;
    see(n, s);
    // num t = num m * 2
    v<int> t, m;
    rep(i, 0, n)
    {
        if (s[i] == 'T')
            t.pb(i);
        else
            m.pb(i);
    }
    if (sz(m) * 2 != sz(t))
    {
        cout << "NO" << endl;
        return;
    }

    rep(i, 0, sz(m))
    {
        if (m[i] < t[i] || m[i] > t[sz(m) + i])
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