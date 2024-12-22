#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall _.cpp -o _

int main()
{
    int n, a, b, c;
    cin >> n;
    int problems = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cin >> b;
        cin >> c;
        if (a + b + c >= 2)
        {
            problems++;
        }
    }
    cout << problems;
    return 0;
}