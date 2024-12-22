#include <bits/stdc++.h>
#define py puts("YES")
#define pn puts("NO")
#define pf puts("-1")
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
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}
void solve()
{
    int n;
    see(n);
    v<int> a(n);
    rep(i, 0, n) see(a[i]);

    a[0]--;
    sort(a.begin() + 1, a.end());
    if (a[0] < a[1])
    {
        puts("Bob");
    }
    else
    {
        puts("Alice");
    }
}