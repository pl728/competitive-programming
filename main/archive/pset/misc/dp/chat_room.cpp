#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall _.cpp -o _

int main()
{
    string s;
    string hello = "hello";
    int length_hello = 5;
    int j = 0;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == hello[j] && j < length_hello)
            j++;
    }
    if (j == length_hello)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}