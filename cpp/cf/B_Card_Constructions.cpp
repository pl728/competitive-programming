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
    // 2, 7, 15
    int n;
    see(n);
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    int pyramids = 1;
    int x = 2;
    int delta = 5;
    v<int> s;
    s.pb(x);
    while (x + delta <= n)
    {
        x += delta;
        delta += 3;
        s.pb(x);
    }
    n -= x;
    int i = s.size() - 1;
    while (n >= 2)
    {
        if (n < s[i])
        {
            i--;
        }
        else if (n >= s[i])
        {
            pyramids++;
            n -= s[i];
        }
    }

    cout << pyramids << endl;
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