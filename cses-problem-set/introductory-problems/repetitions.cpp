#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int best = -1, current = 1;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != str[i - 1])
        {
            best = max(best, current);
            current = 0;
        }
        current++;
    }
    best = max(best, current);
    cout << best;

    return 0;
}