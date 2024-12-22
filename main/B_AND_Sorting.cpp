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
int visited[1005][1005] = {0};

void solve()
{
    int n;
    see(n);
    v<int> a(n);
    v<int> b;
    rep(i, 0, n)
    {
        see(a[i]);
        if (a[i] != i)
        {
            b.pb(a[i]);
        }
    }
    int x = b[0];
    int m = b.size();
    rep(i, 1, m)
    {
        x = (x & b[i]);
    }
    cout << x << endl;
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