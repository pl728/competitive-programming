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
    ll x;
    see(x);
    v<ll> p;
    for (ll i = 1; i < 10000; i++)
    {
        p.pb(i * i * i);
    }
    int i = 0, j = p.size() - 1;
    while (i <= j)
    {
        ll t = p[i] + p[j];
        if (t == x)
        {
            cout << "YES" << endl;
            return;
        }
        else if (t < x)
            i++;
        else
            j--;
    }
    cout << "NO" << endl;
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