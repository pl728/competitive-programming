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
    int n;
    see(n);
    v<int> a(n);
    rep(i, 0, n) see(a[i]);

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    int g = gcd(a[0], a[1]);

    rep(i, 2, n) g = gcd(g, a[i]);

    cout << *max_element(all(a)) / g << endl;

    // if all are multiples of smallest, then
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