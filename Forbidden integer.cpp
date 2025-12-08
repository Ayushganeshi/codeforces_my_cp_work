#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    if (n%2 != 0) {
        if (x !=1) {
            cout << "YES" << endl << n << endl;
            for (int i = 0; i < n; ++i) cout << 1 << " ";
        } else if (k > 2) {
            cout << "YES" << endl;
            int m = (n - 3) / 2 + 1;
            cout << m << endl;
            cout << 3 << " ";
            for (int i = 1; i <= m - 1; ++i) cout << 2 << " ";
        } else {
            cout << "NO";
        }
    } else {
        if (x != 1) {
            cout << "YES" << endl << n << endl;
            for (int i = 0; i < n; ++i) cout << 1 << " ";
        } else if (x != 2 && k >= 2) {
            cout << "YES" << endl;
            cout << n / 2 << endl;
            for (int i = 0; i < n / 2; ++i) cout << 2 << " ";
        } else {
            cout << "NO";
        }
    }

    cout << endl;
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


