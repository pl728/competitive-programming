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

void solve()
{
    int l, r, d;
    see(l, r, d);
    if (d >= l && d <= r)
    {
        int x = r / d + 1;
        cout << d * x << endl;
    }
    else
    {
        cout << d << endl;
    }
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