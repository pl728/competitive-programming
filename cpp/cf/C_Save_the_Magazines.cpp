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

void pv(v<int> a)
{
    rep(i, 0, sz(a)) cout << a[i] << " ";
    cout << endl;
}

void solve()
{
    int n;
    see(n);
    string s;
    see(s);
    v<int> a(n);
    rep(i, 0, n) see(a[i]);

    if (n == 1)
    {
        if (s[0] == '1')
            cout << a[0] << endl;
        else
            cout << 0 << endl;
        return;
    }
    int i = 0;
    ll t = 0;
    while (i < n - 1)
    {
        if (s[i] == '0' && s[i + 1] == '1')
        {
            int sm = a[i];
            ll u = a[i];
            i++;
            while (i < n && s[i] == '1')
            {
                sm = min(sm, a[i]);
                u += a[i];
                i++;
            }
            // cout << sm << endl;
            u -= sm;
            t += u;
            continue;
        }
        else if (s[i] == '1')
        {
            t += a[i];
        }
        i++;
    }
    if (i == n - 1 && s[n - 1] == '1')
        t += a[n - 1];
    cout << t << endl;
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