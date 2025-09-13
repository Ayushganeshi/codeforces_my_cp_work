#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS &  CODE!! 

int get_steps(int a, int b, int c, int d) {
    if (b > d) return -1;
    int up = d - b;
    int new_a = a + up;
    if (new_a < c) return -1;
    int left = new_a - c;
    return up + left;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << get_steps(a, b, c, d) << endl;
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

