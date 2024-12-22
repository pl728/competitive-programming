#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define v vector
using ll = long long;
using namespace std;

template <typename... T>
void see(T &...args) { ((cin >> args), ...); }

const int M = 1e9 + 7;
int grid[1005][1005] = {0};
int ps[107][107] = {0};
void solve()
{
    int n, m;
    see(n, m);
    rep(i, 0, n)
    {
        string s;
        see(s);
        rep(j, 0, (int)s.length())
        {
            grid[i][j] = s[j] - '0';
        }
    }
    if (n < 2 && m < 2)
    {
        cout << "YES" << endl;
        return;
    }
    rep(i, 0, n - 1)
    {
        rep(j, 0, m - 1)
        {
            int t = grid[i][j] + grid[i][j + 1] + grid[i + 1][j] + grid[i + 1][j + 1];
            if (t == 3)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    return;

    // nice = black, not contained within another
    // elegant = no nice intersecting rectangles
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