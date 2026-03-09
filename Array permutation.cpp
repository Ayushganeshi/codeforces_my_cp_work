#include <bits/stdc++.h>
//Author:: ayush kumar gupta;
//CHESS &&& CODE
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define len(a) int(a.size())
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
using namespace std;
 
const int mod = 998244353;
 
const int N = 1e6 + 228;
 
pair<int, int> zero = {-1, N};
 
 
void solve() {
    int n;
    cin >> n;
    map<int, int> pos;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        pos[a] = i;
    }
    int lst = -1;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) {
        if (lst > pos[b[i]]) {
            cout << "NO\n";
            return;
        }
        lst = pos[b[i]];
    }
    cout << "YES\n";
}
 
int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    while (t--) solve();
}
