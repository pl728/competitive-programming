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
// -1 2
// 1 3
// 2 4
// 3 -1
// 4 0
// 8 2
struct point
{
    int weight, pos, id;
};

void solve()
{
    int n, m;
    see(n, m);
    vector<point> p(m);
    rep(i, 0, m)
    {
        see(p[i].pos, p[i].weight);
        p[i].id = i + 1;
    }
    sort(all(p), [](point a, point b)
         { return a.weight < b.weight; });
    ll t = 0;
    rep(i, 0, m)
    {
        if (i < 2 * n)
            t += p[i].weight;
        else
            p.pop_back();
    }
    sort(all(p), [](point a, point b)
         { return a.pos < b.pos; });

    cout << t << endl;
    rep(i, 0, n)
    {
        cout << p[i].id << " " << p[2 * n - 1 - i].id << endl;
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