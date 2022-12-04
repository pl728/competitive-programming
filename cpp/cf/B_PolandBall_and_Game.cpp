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
    int n, m;
    see(n, m);
    unordered_set<string> a, b;
    rep(i, 0, n)
    {
        string x;
        see(x);
        a.insert(x);
    }
    rep(i, 0, m)
    {
        string x;
        see(x);
        b.insert(x);
    }
    int overlap = 0;
    for (string s : a)
    {
        if (b.contains(s))
            overlap++;
    }

    n -= overlap;
    m -= overlap;

    if (!(overlap & 1))
    {
        if (n > m)
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    else
    {
        if (n >= m)
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
}

int main()
{
    solve();
}