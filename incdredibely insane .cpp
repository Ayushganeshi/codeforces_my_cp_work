#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    std::string s;
    std::cin >> s;
    
    s[0]--;
    
    std::sort(s.begin(), s.end());
    
    int ans = s.size();
    int sum = 0;
    for (auto x : s) {
        sum += x - '0';
        if (sum < 9) {
            ans--;
        }
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
