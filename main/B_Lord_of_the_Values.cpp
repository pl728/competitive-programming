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

    cout << 6 * n / 2 << endl;
    rep(i, 0, n / 2)
    {
        int j = n - i - 1;
        cout << 1 << " " << i + 1 << " " << j + 1 << endl;
        cout << 2 << " " << i + 1 << " " << j + 1 << endl;
        cout << 1 << " " << i + 1 << " " << j + 1 << endl;
        cout << 2 << " " << i + 1 << " " << j + 1 << endl;
        cout << 1 << " " << i + 1 << " " << j + 1 << endl;
        cout << 2 << " " << i + 1 << " " << j + 1 << endl;
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