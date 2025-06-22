#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

void solve() {
    int a, b;
    cin >> a >> b;

    int diff = abs(a - b);

    if (diff == 0) {
        cout << 0 << " " << 0 <<endl;
        return;
    }

    int x = a / diff;
    int move1 = abs(x * diff - a);
    int move2 = abs((x + 1) * diff - a);

    cout << diff << " " << min(move1, move2) <<endl;
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
