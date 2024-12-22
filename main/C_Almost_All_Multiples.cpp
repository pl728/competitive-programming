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
    int n, x;
    see(n, x);
    v<int> a(n + 1);
    if (n % x != 0)
    {
        cout << -1 << endl;
        return;
    }

    a[1] = x, a[n] = 1;
    rep(i, 2, n) a[i] = i;
    if (x != n)
    {
        a[x] = n;
    }
    else
    {
        rep(i, 1, n + 1) cout << a[i] << " ";
        cout << endl;
        return;
    }
    int j = x;
    rep(i, x + 1, n)
    {
        if (a[i] % j == 0 && a[j] % i == 0)
        {
            swap(a[i], a[j]);
            j = i;
        }
    }
    rep(i, 1, n + 1) cout << a[i] << " ";
    cout << endl;
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