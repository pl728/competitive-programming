#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall _.cpp -o _

int main()
{
    unordered_map<string, int> um;
    int n;
    cin >> n;
    string outputs[n];
    for (int i = 0; i < n; i++)
    {
        string next;
        cin >> next;
        if (um[next])
        {
            outputs[i] = next + to_string(um[next]);
            um[next]++;
        }
        else
        {
            outputs[i] = "OK";
            um[next] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << outputs[i] << "\n";
    }
    return 0;
}