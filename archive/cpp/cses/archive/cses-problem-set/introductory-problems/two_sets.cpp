#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall two_sets.cpp -o two_sets

int main()
{
    int n;
    cin >> n;
    if (n % 4 == 0)
    {
        cout << "YES"
             << "\n";
        vector<int> x, y;
        for (int i = 0; i < n / 2; i++)
        {
            if (i % 2 == 0)
            {
                x.push_back(i + 1);
                x.push_back(n - i);
            }
            else
            {
                y.push_back(i + 1);
                y.push_back(n - i);
            }
        }
        cout << x.size() << "\n";
        for (int i = 0; i < (int)x.size(); i++)
        {
            cout << x[i] << " ";
        }
        cout << "\n";
        cout << y.size() << "\n";
        for (int i = 0; i < (int)y.size(); i++)
        {
            cout << y[i] << " ";
        }
    }
    else if ((n - 3) % 4 == 0)
    {
        cout << "YES"
             << "\n";
        vector<int> x, y;
        x.push_back(1);
        x.push_back(2);
        y.push_back(3);
        int midpoint = (n - 3) / 2;
        for (int i = 1; i < midpoint + 1; i++)
        {
            if (i % 2 == 1)
            {
                x.push_back(i + 3);
                x.push_back(n - i + 1);
            }
            else
            {
                y.push_back(i + 3);
                y.push_back(n - i + 1);
            }
        }
        cout << x.size() << "\n";
        for (int i = 0; i < (int)x.size(); i++)
        {
            cout << x[i] << " ";
        }
        cout << "\n";
        cout << y.size() << "\n";
        for (int i = 0; i < (int)y.size(); i++)
        {
            cout << y[i] << " ";
        }
    }
    else
    {
        cout << "NO";
    }

    return 0;
}