#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
/

void solve() {
    string s;
    cin >>s;
    int z = 0, o = 0;
    for (auto x : s) {
        if (x == '0') z++;
        else o++;
    }

    int n = s.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (o > 0) o--, n--;
            else break;
        } else {
            if (z > 0) z--, n--;
            else break;
        }
    }

    cout << n <<endl;
}

int32_t main() {
    fast_io();
    
    int t; 
    cin >> t;  
    while (t--) {
        solve();
    }

    return 0;
}


