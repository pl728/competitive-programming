#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// rating: 800

int main()
{
    int w;
    cin >> w;
    if (w == 2)
    {
        cout << "NO";
    }
    else if (!(w & 1))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}