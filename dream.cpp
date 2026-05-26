#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        c -= a;
        d -= b;

        if (a > b) swap(a, b);
        if (c > d) swap(c, d);

        if (((a + 1) << 1) >= b && ((c + 1) << 1) >= d)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
