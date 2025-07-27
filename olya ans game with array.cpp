#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

void solve() {
    int n;
    cin >> n;
    int k = n;
    vector<int> res;
    int mini =INT_MAX;

    while (n--) {
        int m;
        cin >> m;
        vector<int> temp(m);
        int fmin = INT_MAX, smin = INT_MAX;

        for (int i = 0; i < m; i++) {
            cin >> temp[i];
            if (fmin > temp[i]) {
                smin = fmin;
                fmin = temp[i];
            } else if (smin > temp[i]) {
                smin = temp[i];
            }
        }

        mini = min(mini,fmin);
        res.push_back(smin);
    }

    sort(res.begin(), res.end());
    int sum = 0;
    sum += mini;
    int i = res.size() - 1;
    int cnt = 0;
    while (cnt++ < k - 1) {
        sum += res[i--];
    }
    cout << sum <<endl;
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
