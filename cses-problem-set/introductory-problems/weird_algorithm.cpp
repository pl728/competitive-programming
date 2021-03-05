#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    cout << n << " ";
    while (n != 1)
    {
        // bitwise AND: if n & 1 returns 0, then n is even
        // if n & 1 returns 1, then n is odd
        // "n & 1 => 1 if n is odd, 0 if n is even"
        if ((n & 1) == 0)
        {
            n = n / 2;
        }
        else
        {
            n = 3 * n + 1;
        }
        cout << n << " ";
    }

    return 0;
}
