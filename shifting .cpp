#include <iostream>
using namespace std;

void solve() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n;
        cin >> n;

        long long total = 0;
        for (int i = 0; i < n; ++i) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            int dx = x2 - x1;
            int dy = y2 - y1;

            if (dy < 0) {
                total += -dy;
                int xMovement = x1 + (dx < 0 ? dx : 0);
                if (xMovement > 0)
                    total += xMovement;
            }

            if (dx < 0)
                total += -dx;
        }

        cout << total << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
