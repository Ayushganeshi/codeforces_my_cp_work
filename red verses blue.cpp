#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

void solve() {
    int n, a, b;
    cin >> n >> a >>b;

    int groups = a / (b + 1);
    int extra = a % (b + 1);

    string s;
    while (n > 0) {
        for (int i = 0; i < groups && a > 0 && n > 0; i++) {
            s.push_back('R');
            --a; --n;
        }

        if (extra && a > 0 && n > 0) {
            s.push_back('R');
            --a; --n;
            --extra;
        }

        if (b > 0 && n > 0) {
            s.push_back('B');
            --b; --n;
        }
    }

    cout << s << "\n";
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

