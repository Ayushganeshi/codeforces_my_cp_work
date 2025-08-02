// https://codeforces.com/contest/1821/problem/B
// Sort the Subarray

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

#define gcd __gcd
#define ull unsigned long long
#define endl "\n"
#define pp pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define mod 1000000007
#define sort(v) sort(v.begin(), v.end())

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

vector<int> read(int n) {
    vector<int> arr(n);
    for (int i = 0; i <n; i++) cin >> arr[i];
    return arr;
}

void solve() {
    int n;
    cin >> n;

    vi a = read(n);
    vi b = read(n);

    int i = 0, j = 0;
    int l = 1, r = n, len = 0;

    while (j < n) {
        int count = 0;
        while (j < n - 1 && b[j] <= b[j + 1]) {
            if (a[j] != b[j]) count++;
            j++;
        }

        if (a[j] != b[j]) count++;  // Include the last element in this range

        if (count) {
            int curr = j - i + 1;
            if (curr > len) {
                len = curr;
                l = i + 1;
                r = j + 1;
            }
        }

        while (i <= j) {
            if (a[i] != b[i]) count--;
            i++;
            if (count) {
                int curr = j - i + 1;
                if (curr > len) {
                    len = curr;
                    l = i + 1;
                    r = j + 1;
                }
            }
        }
        j++;
    }

    cout << l << " " << r << endl;
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

