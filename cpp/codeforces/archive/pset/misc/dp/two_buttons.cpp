#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall _.cpp -o _

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    if (n >= m)
    {
        cout << n - m;
        return 0;
    }
    // ----------solution #1 (smart) ----------
    int total = 0;
    while (m != n)
    {
        if (m < n)
        {
            m++;
        }
        else if (m % 2 == 0)
        {
            m /= 2;
        }
        else
        {
            m++;
            m /= 2;
            total++;
        }
        total++;
    }
    cout << total;

    // ----------solution #2 (BFS) ----------
    // queue<pair<int, int>> q;
    // q.push(make_pair(n, 0));
    // unordered_set<int> us;
    // us.insert(n);

    // while (!q.empty())
    // {
    //     auto current = q.front();
    //     q.pop();
    //     if (current.first == m)
    //     {
    //         cout << current.second;
    //         break;
    //     }
    //     if (!us.count(current.first - 1))
    //     {
    //         q.push(make_pair(current.first - 1, current.second + 1));
    //         us.insert(current.first - 1);
    //     }
    //     if (current.first < m && !us.count(current.first * 2))
    //     {
    //         q.push(make_pair(2 * current.first, current.second + 1));
    //         us.insert(current.first * 2);
    //     }
    // }
    return 0;
}