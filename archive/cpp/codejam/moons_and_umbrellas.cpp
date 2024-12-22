#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall moons_and_umbrellas.cpp -o moons_and_umbrellas
// Rules:
// CJ - X
// JC - Y
// Examples:
//

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x;
        cin >> y;
        string s;
        cin >> s;
        lli total_cost = 0;
        s.erase(remove(s.begin(), s.end(), '?'), s.end());
        for (int j = 1; j < (int)s.length(); j++)
        {
            if (s[j - 1] == 'C' && s[j] == 'J')
                total_cost += x;
            if (s[j - 1] == 'J' && s[j] == 'C')
                total_cost += y;
        }
        cout << "Case #" << i + 1 << ": " << total_cost << "\n";
    }

    return 0;
}