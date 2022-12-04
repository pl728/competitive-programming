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

bool contains8(ll a)
{
    while (a)
    {
        if (abs(a % 10) == 8)
        {
            return true;
        }
        a /= 10;
    }
    return false;
}

void solve()
{
    ll a;
    see(a);
    int xy = a % 100;
    if (xy == 0)
    {
        if (a < 0)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 8 << endl;
        }

        return;
    }

    a /= 100;
    if (contains8(a))
    {
        cout << 1 << endl;
        return;
    }
    if (a < 0 && xy > 0)
    {
        xy *= -1;
    }
    int xyz = xy + 1;
    while (!contains8(xyz))
    {
        xyz++;
    }
    cout << xyz - xy << endl;
}

int main()
{
    solve();
}