#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    string s; cin >> s;
    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U', 'y', 'Y'};
    string new_string = "";
    for(int i = 0; i < s.length(); i++) {
        if(vowels.find(s[i]) == vowels.end()) {
            // if it is not a vowel
            new_string += ".";
            new_string += tolower(s[i]);
        }
    }
    cout << new_string;
    return 0;
}