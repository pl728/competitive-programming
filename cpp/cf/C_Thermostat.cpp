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

void no()
{
    cout << -1 << endl;
}

void solve()
{
    int l, r, x, a, b;
    see(l, r, x, a, b);
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    if (abs(a - b) >= x)
    {
        cout << 1 << endl;
        return;
    }
    int c = a;
    rep(i, 1, 4)
    {
        int ld = abs(l - c), rd = abs(r - c);
        int dbl = abs(b - l), dlr = abs(b - r);
        if (max(ld, rd) < x)
        {
            no();
            return;
        }
        else if (ld < x)
        {
            c = r;
        }
        else if (rd < x)
        {
            c = l;
        }
        else
        {
            // both are reachable, so choose the one farthest from b
            if (dbl > dlr)
            {
                c = l;
            }
            else
            {
                c = r;
            }
        }

        if (abs(c - b) >= x)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    no();
    // cout << endl;
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