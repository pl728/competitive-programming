#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall _.cpp -o _

int main()
{
    int n;
    cin >> n;
    string str[n];
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        if (str[i].length() > 10)
        {
            string replacement = str[i].at(0) + to_string(str[i].length() - 2) + str[i].at(str[i].length() - 1);
            str[i] = replacement;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << str[i] << "\n";
    }

    return 0;
}