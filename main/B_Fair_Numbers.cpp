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

bool fair(ll x)
{
    ll y = x;
    while (x)
    {
        if (x % 10 && (y % (x % 10)))
        {
            return false;
        }
        x /= 10;
    }
    return true;
}

void solve()
{
    ll n;
    see(n);
    while (!fair(n))
    {
        n++;
    }
    cout << n << endl;
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