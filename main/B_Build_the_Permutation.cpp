#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)(x).size())
#define v vector
using ll = long long;
using namespace std;

template <typename... T>
void see(T &...args) { ((cin >> args), ...); }

const int M = 1e9 + 7;
int grid[1005][1005] = {0};

void pv(v<int> a)
{
    rep(i, 0, sz(a))
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void solve()
{
    int n, a, b;
    see(n, a, b);
    if (a + b > n - 2 || abs(a - b) > 1)
    {
        cout << -1 << endl;
        return;
    }

    // 1 2 3 4 5 6 7 8, a=3, b=3
    // 1 7 2 3 4 5 6 8 (1,1)
    // 1 7 2 6 3 4 5 8 (2,2)
    v<int> x(n);
    if (a == b)
    {
        x[0] = 1;
        x[n - 1] = n;
        int ii = 1;
        int i = 2;
        int j = n - 1;
        while (ii < a + b)
        {
            x[ii] = j--;
            x[ii + 1] = i++;
            ii += 2;
        }
        while (ii < n - 1)
        {
            x[ii] = x[ii - 1] + 1;
            ii++;
        }
    }
    // 4 1 0
    // 1 4 3 2

    // 5 2 1
    // 1 5 3 4 2

    // 5 1 0
    // 1 5 4 3 2

    // 7 3 2
    // 1 7 3 6 4 5 2

    // 7 2 1
    // 1 7 3 6 5 4 2
    else if (a > b)
    {
        x[0] = 1;
        x[n - 1] = 2;
        int ii = 1;
        int i = 3;
        int j = n;
        while (ii <= a + b)
        {
            if (ii & 1)
            {
                x[ii] = j--;
            }
            else
            {
                x[ii] = i++;
            }
            ii++;
        }
        while (ii < n - 1)
        {
            x[ii] = x[ii - 1] - 1;
            ii++;
        }
    }
    // 5 1 2
    // 5 1 3 2 4
    // 7 2 3
    // 7 1 5 2 4 3 6
    //
    // 7 1 2
    // 7 1 5 2 3 4 6
    else if (b > a)
    {
        x[0] = n;
        x[n - 1] = n - 1;
        int ii = 1;
        int i = 1;
        int j = n - 2;
        while (ii <= a + b)
        {
            if (ii & 1)
            {
                x[ii] = i++;
            }
            else
            {
                x[ii] = j--;
            }
            ii++;
        }
        while (ii < n - 1)
        {
            x[ii] = x[ii - 1] + 1;
            ii++;
        }
    }

    pv(x);
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