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
    int n;
    see(n);
    v<int> a(n);
    int x = 0, y = 0;
    rep(i, 0, n)
    {
        see(a[i]);
        if (a[i] == 1)
            x++;
        if (a[i] > 1)
            y++;
    }

    if (!x)
    {
        cout << "First" << endl;
        return;
    }
    if (!y)
    {
        if (!(x & 1))
        {
            cout << "Second" << endl;
        }
        else
        {
            cout << "First" << endl;
        }
        return;
    }
    rep(i, 0, n)
    {
        if (a[i] != 1)
        {
            if (!(i & 1))
            {
                cout << "First" << endl;
            }
            else
            {
                cout << "Second" << endl;
            }
            return;
        }
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