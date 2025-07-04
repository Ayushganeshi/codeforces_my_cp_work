#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

void solve() {
    string s;
    cin >> s;
    int zero = 0, one = 0;

    for (char c : s) {
        if (c == '0') zero++;
        else one++;
    }

    int moves = min(zero, one);
    if (moves % 2 == 1)
        cout << "DA" << '\n';
    else
        cout << "NET" << '\n';
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
