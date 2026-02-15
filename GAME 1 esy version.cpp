#include <bits/stdc++.h>
 
using namespace std;
 
const long long INF = 1000000000000LL + 1;

void solve(){
    int x;
    long long y, k;
 
    cin >> x >> y >> k;
 
    long long l = 1, r = INF;
    long long m;
 
    while(l <= r){
        m = l + (r - l) / 2;
        long long ost = (m - 1);
        for (int i = 0; i < x; i++){
            ost -= ost / y;
        }
        if (ost + 1 > k){
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
 
    if (r == INF){
        cout << -1 << '\n';
    }
    else{
        cout << r << '\n';
    }
}
 
signed main()
{
#ifdef FELIX
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
 
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }
 
#ifdef FELIX
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
    chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}
