#include <bits/stdc++.h>
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

void solve()
{
    int n;
    see(n);
    // largest x, smallest y
    int a = -1, b = M;
    rep(i, 0, n)
    {
        int x, y;
        see(x, y);
        a = max(a, x);
        b = min(b, y);
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    cout << max(0, a - b) << endl;
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