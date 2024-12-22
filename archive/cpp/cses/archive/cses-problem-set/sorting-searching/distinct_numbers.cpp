#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main()
{
    lli n;
    cin >> n;
    set<lli> u;
    int count = 0;
    lli next;
    for (lli i = 0; i < n; i++)
    {
        cin >> next;
        if (u.find(next) == u.end())
        {
            count += 1;
        }
        u.insert(next);
    }
    cout << count;

    return 0;
}