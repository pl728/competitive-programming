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
    ll t = 0;
    while (n >= 10)
    {
        int x = 10 - (n % 10);
        t += x;
        n += x;
        while (n > 1 && n % 10 == 0)
        {
            n /= 10;
        }
    }
    if (n % 10 == 0)
        t += 1;
    cout << t + 9 << endl;
}

int main()
{
    solve();
}