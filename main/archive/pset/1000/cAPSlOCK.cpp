#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// if entire word is uppercase
// if first char is lower, rest is upper

string stringUpperToLower(string s) {
    string new_string = "";
    for(int i = 0; i < s.length(); i++) {
        new_string += tolower(s[i]);
    }
    return new_string;
}

int main()
{
    string s; cin >> s;
    int n = s.length();
    if(n == 1) {
        if(isupper(s[0])) {
            cout << (char) tolower(s[0]);
        } else{
            cout << (char) toupper(s[0]);
        }
    } else {

        for(int i = 1; i < n; i++) {
            if(islower(s[i])){
                cout << s;
                return 0;
            }
        }

        if(isupper(s[0])){
            cout << stringUpperToLower(s);
            return 0;
        } else {
            cout << (char) toupper(s[0]) + stringUpperToLower(s.substr(1, s.length()));
            return 0;
        }
    }
    return 0;
}