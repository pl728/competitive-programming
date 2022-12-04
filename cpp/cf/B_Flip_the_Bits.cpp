#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
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
    see(n);
    string s, t;
    see(s, t);
    if (s == t)
    {
        cout << "YES" << endl;
        return;
    }
    set<int> equalPoints;
    int x = 0, y = 0;
    rep(i, 0, n)
    {
        if (s[i] == '0')
            x++;
        else
            y++;
        if (x == y)
        {
            equalPoints.insert(i + 1);
        }
    }
    if (sz(equalPoints) == 0)
    {
        cout << "NO" << endl;
        return;
    }
    v<int> diff;
    rep(i, 1, n)
    {
        if ((s[i] == t[i] && s[i - 1] != t[i - 1]) || (s[i] != t[i] && s[i - 1] == t[i - 1]))
        {
            diff.pb(i);
        }
    }
    if (s[n - 1] != t[n - 1])
        diff.pb(n);
    rep(i, 0, sz(diff))
    {
        if (equalPoints.find(diff[i]) == equalPoints.end())
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