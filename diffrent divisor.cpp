#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 



int prime(int n) { 
    if(n == 2 || n == 3) return n;
    if(n % 2 == 0) ++n;
    while (true) {
        bool isPrime = true;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) return n;
        n += 2;
    }
}

void solve() {
    int d;
    cin >> d;
    int x = prime(1 + d);
    int y = prime(x + d);
    cout << x * y << "\n";
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
