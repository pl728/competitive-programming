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
    int n, k;
    see(n, k);
    if (!(n & 1))
    {
        if (!(k % n))
        {
            cout << n << endl;
        }
        else
        {
            cout << k % n << endl;
        }
    }
    else
    {
        int bSpot = (k % n == 0) ? n : (k % n);
        int nAdd = (k - 1) / (n / 2);
        ll ans = ((bSpot + nAdd) % n == 0) ? n : ((bSpot + nAdd) % n);
        cout << ans << endl;
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