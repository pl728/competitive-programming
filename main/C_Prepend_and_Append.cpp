#include <bits/stdc++.h>
#define py puts("YES")
#define pn puts("NO")
#define pf puts("-1")
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)(x).size())
#define len(x) ((int)(x).length())
#define v vector
#define vi v<int>
#define vii v<v<int>>
#define contains(a, b) ((a).find(b) != (a).end())
using ll = long long;
using namespace std;

template <typename... T>
void see(T &...args) { ((cin >> args), ...); }

const int MXN = 1e9 + 7;
int grid[1005][1005] = {0};

void solve()
{
    int n;
    string s;
    see(n, s);
    int i = 0;
    int j = n - 1;
    while (i < j && ((s[i] == '0' && s[j] == '1') || (s[i] == '1' && s[j] == '0')))
    {
        i++;
        j--;
    }
    if (i == j)
    {
        cout << 1 << endl;
    }
    else if (i > j)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << j - i + 1 << endl;
    }
}

void tie()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve();
int main()
{
    tie();
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}