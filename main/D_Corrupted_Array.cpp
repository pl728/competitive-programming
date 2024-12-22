#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
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
    v<int> b(n + 2);
    multiset<int> ms;
    rep(i, 0, n + 2)
    {
        see(b[i]);
        ms.insert(b[i]);
    }

    ll t = accumulate(all(b), 0LL);
    rep(i, 0, n + 2)
    {
        if ((t - b[i]) % 2 == 0)
        {
            int x = (t - b[i]) / 2;
            ms.erase(ms.find(b[i]));
            if (ms.find(x) != ms.end() && t - b[i] <= 2000000000)
            {
                ms.erase(ms.find(x));
                for (int x : ms)
                {
                    cout << x << " ";
                }
                cout << endl;
                return;
            }
            else
            {
                ms.insert(b[i]);
            }
        }
    }
    cout << "-1" << endl;
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