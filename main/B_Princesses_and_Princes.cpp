#include <bits/stdc++.h>
#define py puts("OPTIMAL")
#define pn puts("IMPROVE")
#define pf puts("-1")
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)(x).size())
#define len(x) ((int)(x).length())
#define v vector
#define vi v<int>
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
    set<int> married;
    vi notMarried;
    rep(i, 0, n)
    {
        int m;
        see(m);
        bool md = false;
        rep(i, 0, m)
        {
            int x;
            see(x);
            if (!md && !contains(married, x))
            {
                married.insert(x);
                md = true;
            }
        }
        if (!md)
        {
            notMarried.pb(i);
        }
    }
    if (sz(married) == n)
        py;
    else
    {
        int c = 1;
        while (contains(married, c))
        {
            c++;
        }
        pn;
        cout << notMarried[0] + 1 << " " << c << endl;
    }
}

void tie()
{
    // ios_base::sync_with_stdio(0);
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