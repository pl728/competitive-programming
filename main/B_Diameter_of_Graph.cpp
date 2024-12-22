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
void yes()
{
    cout << "YES" << endl;
    return;
}
void no()
{
    cout << "NO" << endl;
    return;
}

void solve()
{
    // for n nodes, minimum edges to be connected is n-1 edges
    // minimum diameter is 2
    // maximum diameter is n-1
    ll n, m, k;
    see(n, m, k);
    if (n == 1)
    {
        if (m == 0 && k > 1)
            yes();
        else
            no();
        return;
    }
    ll mFullyConnected = n * (n - 1) / 2;
    if (m < n - 1 || m > mFullyConnected)
    {
        no();
        return;
    }
    int diameter = (m < mFullyConnected) ? 2 : 1;
    (diameter < k - 1) ? yes() : no();
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