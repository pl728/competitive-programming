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

void solve()
{
    // after 1,n you get 1,x and y,n
    int n;
    see(n);
    set<pair<int, int>> p;
    rep(i, 0, n)
    {
        int l, r;
        see(l, r);
        p.insert({l, r});
    }
    // sort(all(p), [](pair<int, int> a, pair<int, int> b)
    //      { return a.second > a.first; });

    for (pair<int, int> x : p)
    {
        int a = x.first, b = x.second;
        if (a == b)
        {
            cout << a << " " << b << " " << a << endl;
        }
        else
        {
            // d could be [1,6]
            // 1 -> [2,6]
            // 2 -> [1,1] and [3,6]
            if (p.find({a + 1, b}) != p.end())
            {
                cout << a << " " << b << " " << a << endl;
            }
            else if (p.find({a, b - 1}) != p.end())
            {
                cout << a << " " << b << " " << b << endl;
            }
            else
            {
                rep(d, a + 1, b)
                {
                    if (p.find({a, d - 1}) != p.end() && p.find({d + 1, b}) != p.end())
                    {
                        cout << a << " " << b << " " << d << endl;
                        break;
                    }
                }
            }
        }
    }
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