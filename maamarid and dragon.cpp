#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);//////////////////////////////   time complexity  0(N)

                    /////////////////////////////      Space complexity  0(N)

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int pref2 = 0, suf = 0;

        for (char x : s) {
            if (x == '1' || x == '3') {
                suf++;
            }
        }

        int ans = pref2 + suf;

        for (char x : s) {
            if (x == '2') {
                pref2++;
            }

            if (x == '1' || x == '3') {
                suf--;
            }

            ans = max(ans, pref2 + suf);
        }

        cout << s.length() - ans << '\n';
    }

    return 0;
}
