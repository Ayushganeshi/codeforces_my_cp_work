#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

// Function to compute all divisors of n (excluding n)
vector<int> get_divisors(int n) {
    vector<int> ans;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i != n) ans.push_back(i);
            if (n / i != i && (n / i) != n) ans.push_back(n / i);
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    vector<int> divisors = get_divisors(n);
    int answer = 0;

    for (int d : divisors) {
        int mini = LLONG_MAX, maxi = LLONG_MIN, sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            if ((i + 1) % d == 0) {
                mini = min(mini, sum);
                maxi = max(maxi, sum);
                sum = 0;
            }
        }
        answer = max(answer, maxi - mini);
    }

    cout << answer << '\n';
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
