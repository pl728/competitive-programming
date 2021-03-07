#include <bits/stdc++.h>
#define lli long long int
using namespace std;
#define F(i, n) for (int i = 1; i <= n; i++)

int main()
{
    int n;
    cin >> n;
    F(i, n)
    {
        if (i == 1)
        {
            cout << 0 << "\n";
        }
        else if (i == 2)
        {
            cout << 6 << "\n";
        }
        else
        {
            lli output = 0.5 * pow(i, 2) * (pow(i, 2) - 1) - 4 * (i - 1) * (i - 2);
            cout << output << "\n";
        }
    }

    return 0;
}
