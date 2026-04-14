#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
 
int t, n, m;
 
int main() {
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        
        int c, cnt, mx = 1;
        
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            
            if (!i) {
                c = a;
                cnt = 1;
            }
            else if (a != c) {
                c = a;
                mx = max(mx, cnt);
                cnt = 1;
            }
            else {
                cnt++;
            }
        }
        
        mx = max(mx, cnt);
        
        if(mx < m) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    
    return 0;
}
