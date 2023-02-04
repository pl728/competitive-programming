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
#define contains(a, b) ((a).find(b) != (a).end())
using ll = long long;
using namespace std;

template <typename... T>
void see(T &...args) { ((cin >> args), ...); }

const int MXN = 1e9 + 7;
int grid[1005][1005] = {0};

void solve()
{
    // if missing letters, output the first letter missing
    // the output must be between length [1,3]

    int n;
    see(n);
    string st;
    see(st);
    unordered_set<string> s;
    rep(i, 0, n)
    {
        s.insert(st.substr(i, 1));
    }
    rep(i, 0, n - 1)
    {
        s.insert(st.substr(i, 2));
    }
    rep(i, 0, n - 2)
    {
        s.insert(st.substr(i, 3));
    }
    rep(i, 0, 26)
    {
        string x;
        x += ('a' + i);
        if (!contains(s, x))
        {
            cout << x << endl;
            return;
        }
    }
    rep(i, 0, 26)
    {
        rep(j, 0, 26)
        {
            string x;
            x += ('a' + i);
            x += ('a' + j);
            if (!contains(s, x))
            {
                cout << x << endl;
                return;
            }
        }
    }
    rep(i, 0, 26)
    {
        rep(j, 0, 26)
        {
            rep(k, 0, 26)
            {
                string x;
                x += ('a' + i);
                x += ('a' + j);
                x += ('a' + k);
                if (!contains(s, x))
                {
                    cout << x << endl;
                    return;
                }
            }
        }
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