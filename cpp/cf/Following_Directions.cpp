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
    string s;
    see(s);
    int x = 0, y = 0;
    rep(i, 0, n)
    {
        if (s[i] == 'L')
        {
            x--;
        }
        else if (s[i] == 'R')
        {
            x++;
        }
        else if (s[i] == 'U')
        {
            y++;
        }
        else
        {
            y--;
        }
        if (x == 1 && y == 1)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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