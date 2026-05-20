#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        long long n;
        cin >> n;

        vector<long long> c(n);

        for (long long i = 0; i < n; i++) {
            cin >> c[i];
        }

        long long s = 0;
        long long ones = 0;
        long long slots = 0;

        for (long long x : c) {

            s += x;

            if (x == 1) {
                ones++;
            }
            else {
                slots += (x / 2) - 1;
            }
        }

        if (ones == n - 1) {
            slots++;
        }

        long long wasted = max(0LL, ones - slots);

        if (s - wasted < 3) {
            cout << 0 << '\n';
        }
        else {
            cout << s - wasted << '\n';
        }
    }

    return 0;
}
