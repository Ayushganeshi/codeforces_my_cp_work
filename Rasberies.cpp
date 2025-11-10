#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupt
//       !! CHESS & CODEEE &&& CODEEEE

void solve() {
    int n, k;
    cin >> n >>k;
    int mini = INT_MAX, op;
    int eve = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x % 2 == 0) eve++;

        if (x % k == 0) {
            mini = 0;
        }

        int a = x / k;
        op = (a + 1) * k - x;
        mini = min(op, mini);
    }

    if (k == 4) {
        if (eve == 1) mini = min(1LL, mini); 
        else if (eve >= 2) mini = min(0LL, mini);
        mini = min(2LL, mini);
    }

    cout << mini <<endl;
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


