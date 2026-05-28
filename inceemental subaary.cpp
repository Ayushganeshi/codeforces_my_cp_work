#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--) {
        long long n, m;
        cin >> n >> m;

        vector<long long> a(m + 1);

        for (long long i = 1; i <= m; i++) {
            cin >> a[i];
        }

        long long ans = n - a[m] + 1;

        for (long long i = 2; i <= m; i++) {
            if (a[i] == 1) {
                ans = 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
