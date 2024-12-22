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
    int n, c;
    see(n, c);
    v<int> a(n);
    rep(i, 0, n) see(a[i]);
    v<int> b(n);
    rep(i, 0, n)
    {
        // 1 1 1 1 1
        // 1 2 3 4 5
        b[i] = i + 1 + a[i];
    }
    sort(all(b));
    int d = 0;
    rep(i, 0, n)
    {
        if (c - b[i] < 0)
        {
            break;
        }
        c -= b[i];
        d++;
    }
    cout << d << endl;
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