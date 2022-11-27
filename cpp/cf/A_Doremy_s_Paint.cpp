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
    rep(i, 0, n) cin >> a[i];

    if (n == 1)
    {
        cout << "1 1" << endl;
        return;
    }
    // 9 8 5 2 1 1 2 3 3
    //  3 9 -> 5 2 1 1 2 3 3 -> 7 - 1111 = 3

    int ans = 0;
    unordered_set<int> c;
    c.insert(a[0]);
    int ansValue = ans - 1;
    rep(i, 1, n)
    {
        c.insert(a[i]);
        if (ansValue < i - (int)c.size())
        {
            ansValue = i - (int)c.size();
            ans = i;
        }
    }

    cout << 1 << " " << ans + 1 << endl;
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