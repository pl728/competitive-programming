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
    if (n & 1)
    {
        int i = n - n / 2 + 2;
        rep(j, 0, n) a[j] = i++;
        a[0]--, a[n - 1]++, a[n - 2]++;
    }
    else
    {
        int i = n - n / 2;
        rep(j, 0, n / 2) a[j] = i++;
        i++;
        rep(j, n / 2, n) a[j] = i++;
    }
    rep(i, 0, n) cout << a[i] << " ";
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