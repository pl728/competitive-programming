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
    try
    {
        int a[100000000][100000000];
    }

    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        return;
    }
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            for (int k = 0; k < 10000; k++)
            {
                cout << i << " " << j << " " << k << " " << endl;
            }
        }
    }
}

int main()
{
    solve();
}