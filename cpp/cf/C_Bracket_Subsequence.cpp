#include <bits/stdc++.h>
#define py puts("YES")
#define pn puts("NO")
#define pf puts("-1")
#define hh puts("")
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

void solve();
int main()
{
    solve();
}
void solve()
{
    int n, k;
    see(n, k);
    string s;
    see(s);
    v<int> x;
    set<int> t;
    rep(i, 0, n)
    {
        if (s[i] == '(')
        {
            x.pb(i);
        }
        else
        {
            if (sz(t) < n - k)
            {
                t.insert(x.back());
                t.insert(i);
            }
            x.pop_back();
        }
    }
    string u = "";
    hh;
    rep(i, 0, n)
    {
        if (t.find(i) == t.end())
        {
            u += s[i];
        }
    }
    cout << u << endl;
}