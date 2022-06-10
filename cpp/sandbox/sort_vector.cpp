#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 7;
    string s = "monkey";
    sort(s.rbegin(), s.rend());
    for (int i = 0; i < n; i++)
    {
        cout << s << " ";
    }
    return 0;
}