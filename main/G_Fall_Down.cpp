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
char grid[1005][1005];

void solve()
{
    int n, m;
    see(n, m);
    v<pair<int, int>> obstacles;
    rep(i, 0, n)
    {
        string s;
        see(s);

        rep(j, 0, m)
        {
            grid[i][j] = s[j];
            if (s[j] == 'o')
                obstacles.pb({i, j});
        }
    }
    rep(i, 0, m)
    {
        obstacles.pb({n, i});
    }
    for (auto p : obstacles)
    {
        int i = p.first - 1, j = p.second;
        int stonesAbove = 0;
        while (i >= 0)
        {
            if (grid[i][j] == 'o')
            {
                break;
            }
            if (grid[i][j] == '*')
            {
                stonesAbove++;
            }
            i--;
        }
        for (int k = p.first - 1; k > i; k--)
        {
            if (stonesAbove > 0)
            {
                grid[k][j] = '*';
                stonesAbove--;
            }
            else
            {
                grid[k][j] = '.';
            }
        }
    }
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
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