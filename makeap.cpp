#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!!



void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int d1 = b - c, d2 = c - b;
    if (d1 == d2) {
        cout << "YES\n";
        return;
    }

    
    int d = (c - a) / 2;
    int x = a + d;
    if ((c - a) % 2 == 0 && x % b == 0 && x != 0 && x >= b) {
        cout << "YES\n";
        return;
    }

    
    d = b - a;
    x = b + d;
    if (x % c == 0 && x != 0 && x >= c) {
        cout << "YES\n";
        return;
    }

    
    d = c - b;
    x = b - d;
    if (x % a == 0 && x != 0 && x >= a) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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


