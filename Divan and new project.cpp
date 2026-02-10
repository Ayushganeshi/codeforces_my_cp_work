#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS &    CODE!! 

void solve() {
    int n;
    cin >> n;
    
    using pp = pair<int,int>;
    priority_queue<pp, vector<pp>> pq;
    vector<int> importance(n);
    
    for (int i = 0; i <n; i++) {
        cin >> importance[i];
        pq.push({importance[i], i});
    }

    int left = 0, right = 0;
    bool goRight = true;
    vector<int> position(n);
    int ans = 0;

    while (!pq.empty()) {
        auto [val, idx] = pq.top(); pq.pop();
        if (goRight) {
            right++;
            position[idx] = right;
            ans += 2 * val * right;
        } else {
            left--;
            position[idx] = left;
            ans += 2*val *abs(left);
        }
        goRight = !goRight;
    }

    cout << ans << '\n';
    cout << 0 << ' ';
    for (int x : position ) cout << x << ' ';
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




