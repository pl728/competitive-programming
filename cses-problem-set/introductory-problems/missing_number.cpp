#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, s = 0, next;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> next;
        s += next;
    }
    cout << (n * (n + 1)) / 2 - s;
    return 0;
}
